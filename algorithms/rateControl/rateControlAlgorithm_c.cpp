/* MIT License
 *
 Copyright (c) 2025, Laboratory for Atmospheric and Space Physics, University of Colorado at Boulder
 */

#include "rateControlAlgorithm_c.h"
#include "rateControlAlgorithm.h"

#include <Eigen/Core>

RateControlAlgorithm* RateControlAlgorithm_create(void) {
    return reinterpret_cast<RateControlAlgorithm*>(new ::RateControlAlgorithm());
}

void RateControlAlgorithm_destroy(RateControlAlgorithm* self) {
    delete reinterpret_cast<::RateControlAlgorithm*>(self);
}

CmdTorqueBodyMsgF32Payload RateControlAlgorithm_update(RateControlAlgorithm* self,
                                                       const AttGuidMsgF32Payload* attGuidIn) {
    return reinterpret_cast<::RateControlAlgorithm*>(self)->update(*attGuidIn);
}

void RateControlAlgorithm_setSpacecraftInertia(RateControlAlgorithm* self,
                                               const VehicleConfigMsgF32Payload* vehicleConfigIn) {
    reinterpret_cast<::RateControlAlgorithm*>(self)->setSpacecraftInertia(*vehicleConfigIn);
}

void RateControlAlgorithm_setDerivativeGainP(RateControlAlgorithm* self, float P) {
    reinterpret_cast<::RateControlAlgorithm*>(self)->setDerivativeGainP(P);
}

float RateControlAlgorithm_getDerivativeGainP(const RateControlAlgorithm* self) {
    return reinterpret_cast<const ::RateControlAlgorithm*>(self)->getDerivativeGainP();
}

void RateControlAlgorithm_setKnownTorquePntB_B(RateControlAlgorithm* self, Vector3f_c knownTorquePntB_B) {
    Eigen::Vector3f vec;
    vec << knownTorquePntB_B.data[0], knownTorquePntB_B.data[1], knownTorquePntB_B.data[2];
    reinterpret_cast<::RateControlAlgorithm*>(self)->setKnownTorquePntB_B(vec);
}

Vector3f_c RateControlAlgorithm_getKnownTorquePntB_B(const RateControlAlgorithm* self) {
    const Eigen::Vector3f& vec = reinterpret_cast<const ::RateControlAlgorithm*>(self)->getKnownTorquePntB_B();
    Vector3f_c out;
    out.data[0] = vec[0];
    out.data[1] = vec[1];
    out.data[2] = vec[2];
    return out;
}
