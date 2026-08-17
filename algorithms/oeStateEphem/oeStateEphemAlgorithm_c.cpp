#include "oeStateEphemAlgorithm_c.h"
#include "oeStateEphemAlgorithm.h"
#include "utilities/fsw/freestandingInvalidArgument.h"
#include "utilities/fsw/opaqueHandle.h"

#include <algorithm>
#include <array>
#include <cstddef>

namespace {
OEStateEphemConfig configFromC(const double centralBodyGravitationalParameter,
                               const unsigned int numberOfArcs,
                               const double ephemerisTimeJ2000,
                               const double vehicleTimeOffset,
                               const ChebyshevFitArc_c fitCoefficients[MAX_OE_RECORDS]) {
    std::array<ChebyshevFitArc, kMaxOeRecords> arcs{};
    for (std::size_t i = 0; i < kMaxOeRecords; ++i) {
        const ChebyshevFitArc_c& src = fitCoefficients[i];
        ChebyshevFitArc& dst = arcs.at(i);
        // Copied field by field on purpose. The two structs now agree on field order and on
        // anomalyFlag's width, which makes them look castable -- but this copy is what keeps
        // ChebyshevFitArc's layout out of the Ada ABI, and std::array<double, N> matching
        // double[N] is universal in practice rather than guaranteed. Do not replace with a
        // memcpy or a reinterpret_cast.
        dst.numberChebCoefficients = src.numberChebCoefficients;
        dst.ephemerisTimeMiddle = src.ephemerisTimeMiddle;
        dst.ephemerisTimeRadius = src.ephemerisTimeRadius;
        dst.anomalyFlag = src.anomalyFlag;
        std::ranges::copy(src.radiusPeriapsisCoefficients, dst.radiusPeriapsisCoefficients.begin());
        std::ranges::copy(src.eccentricityCoefficients, dst.eccentricityCoefficients.begin());
        std::ranges::copy(src.inclinationCoefficients, dst.inclinationCoefficients.begin());
        std::ranges::copy(src.argPeriapsisCoefficients, dst.argPeriapsisCoefficients.begin());
        std::ranges::copy(src.raanCoefficients, dst.raanCoefficients.begin());
        std::ranges::copy(src.trueAnomalyCoefficients, dst.trueAnomalyCoefficients.begin());
    }
    return OEStateEphemConfig::create(
        centralBodyGravitationalParameter, numberOfArcs, ephemerisTimeJ2000, vehicleTimeOffset, arcs);
}
}  // namespace

bool OEStateEphemAlgorithm_validateConfig(const double centralBodyGravitationalParameter,
                                          const unsigned int numberOfArcs,
                                          const double ephemerisTimeJ2000,
                                          const double vehicleTimeOffset,
                                          ChebyshevFitArc_c fitCoefficients[MAX_OE_RECORDS]) {
    // Attempt to build the config through the real create path; success means valid,
    // a throw means invalid. Reusing configFromC keeps validation from drifting.
    try {
        (void)configFromC(
            centralBodyGravitationalParameter, numberOfArcs, ephemerisTimeJ2000, vehicleTimeOffset, fitCoefficients);
        return true;
    } catch (const fsw::invalid_argument&) {
        return false;
    }
}

OEStateEphemAlgorithmHandle* OEStateEphemAlgorithm_create(const double centralBodyGravitationalParameter,
                                                          const unsigned int numberOfArcs,
                                                          const double ephemerisTimeJ2000,
                                                          const double vehicleTimeOffset,
                                                          ChebyshevFitArc_c fitCoefficients[MAX_OE_RECORDS]) {
    return fsw::createHandle<::OEStateEphemAlgorithm, OEStateEphemAlgorithmHandle>(configFromC(
        centralBodyGravitationalParameter, numberOfArcs, ephemerisTimeJ2000, vehicleTimeOffset, fitCoefficients));
}

void OEStateEphemAlgorithm_destroy(OEStateEphemAlgorithmHandle* self) {
    fsw::deleteHandle<::OEStateEphemAlgorithm>(self);
}

void OEStateEphemAlgorithm_setConfig(OEStateEphemAlgorithmHandle* self,
                                     const double centralBodyGravitationalParameter,
                                     const unsigned int numberOfArcs,
                                     const double ephemerisTimeJ2000,
                                     const double vehicleTimeOffset,
                                     ChebyshevFitArc_c fitCoefficients[MAX_OE_RECORDS]) {
    fsw::fromHandle<::OEStateEphemAlgorithm>(self)->setConfig(configFromC(
        centralBodyGravitationalParameter, numberOfArcs, ephemerisTimeJ2000, vehicleTimeOffset, fitCoefficients));
}

CartesianState_c OEStateEphemAlgorithm_update(OEStateEphemAlgorithmHandle* self, const uint64_t callTime) {
    const orbitalMotion::CartesianState result = fsw::fromHandle<::OEStateEphemAlgorithm>(self)->update(callTime);
    CartesianState_c out;
    out.position[0] = result.position[0];
    out.position[1] = result.position[1];
    out.position[2] = result.position[2];
    out.velocity[0] = result.velocity[0];
    out.velocity[1] = result.velocity[1];
    out.velocity[2] = result.velocity[2];
    return out;
}

uint32_t OEStateEphemAlgorithm_getMaxOeCoeff(void) { return MAX_OE_COEFF; }

uint32_t OEStateEphemAlgorithm_getMaxOeRecords(void) { return MAX_OE_RECORDS; }

uint32_t OEStateEphemAlgorithm_getFitArcSizeBits(void) { return static_cast<uint32_t>(sizeof(ChebyshevFitArc_c) * 8U); }
