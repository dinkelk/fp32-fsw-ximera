/* MIT License
 *
 Copyright (c) 2025, Laboratory for Atmospheric and Space Physics, University of Colorado at Boulder
 */

#include "sunSearchAlgorithm_c.h"
#include "sunSearchAlgorithm.h"

uint32_t SunSearchAlgorithm_getNumSlews(void) { return NUM_SLEWS; }

SunSearchAlgorithm* SunSearchAlgorithm_create(void) {
    return reinterpret_cast<SunSearchAlgorithm*>(new ::SunSearchAlgorithm());
}

void SunSearchAlgorithm_destroy(SunSearchAlgorithm* self) {
    delete reinterpret_cast<::SunSearchAlgorithm*>(self);
}

void SunSearchAlgorithm_reset(SunSearchAlgorithm* self,
                              uint64_t currentSimNanos,
                              const VehicleConfigMsgF32Payload* vehicleConfigIn) {
    reinterpret_cast<::SunSearchAlgorithm*>(self)->reset(currentSimNanos, *vehicleConfigIn);
}

AttGuidMsgF32Payload SunSearchAlgorithm_update(SunSearchAlgorithm* self,
                                               uint64_t currentSimNanos,
                                               const NavAttMsgF32Payload* navAttIn) {
    return reinterpret_cast<::SunSearchAlgorithm*>(self)->update(currentSimNanos, *navAttIn);
}

void SunSearchAlgorithm_setSlewProperties(SunSearchAlgorithm* self,
                                          const SlewProperties* slewPropertiesInput) {
    reinterpret_cast<::SunSearchAlgorithm*>(self)->setSlewProperties(*slewPropertiesInput);
}

void SunSearchAlgorithm_modifySlewProperties(SunSearchAlgorithm* self,
                                             const SlewProperties* slewPropertiesInput,
                                             uint32_t index) {
    reinterpret_cast<::SunSearchAlgorithm*>(self)->modifySlewProperties(*slewPropertiesInput, index);
}

SlewProperties SunSearchAlgorithm_getSlewProperties(const SunSearchAlgorithm* self, uint32_t index) {
    return reinterpret_cast<const ::SunSearchAlgorithm*>(self)->getSlewProperties(index);
}
