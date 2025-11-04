/* MIT License
 *
 Copyright (c) 2025, Laboratory for Atmospheric and Space Physics, University of Colorado at Boulder
 */

#ifndef F32XIMERA_SUNSEARCHALGORITHM_C_H
#define F32XIMERA_SUNSEARCHALGORITHM_C_H

#include "sunSearchTypes.h"
#include <stdint.h>
#include "msgPayloadDef/AttGuidMsgF32Payload.h"
#include "msgPayloadDef/NavAttMsgF32Payload.h"
#include "msgPayloadDef/VehicleConfigMsgF32Payload.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Opaque handle to the C++ SunSearchAlgorithm instance.
 */
typedef struct SunSearchAlgorithm SunSearchAlgorithm;

/**
 * @brief Get the maximum number of slews constant for validation.
 * @return The maximum number of slews (NUM_SLEWS).
 */
uint32_t SunSearchAlgorithm_getNumSlews(void);

/**
 * @brief Construct a new SunSearchAlgorithm instance.
 * @return Pointer to a new SunSearchAlgorithm (must be destroyed).
 */
SunSearchAlgorithm* SunSearchAlgorithm_create(void);

/**
 * @brief Destroy a previously created SunSearchAlgorithm.
 * @param self Pointer to the instance to destroy.
 */
void SunSearchAlgorithm_destroy(SunSearchAlgorithm* self);

/**
 * @brief Reset the algorithm state.
 * @param self             Pointer to the instance.
 * @param currentSimNanos  Time stamp for reset in nanoseconds.
 * @param vehicleConfigIn  Pointer to vehicle configuration message payload.
 */
void SunSearchAlgorithm_reset(SunSearchAlgorithm* self,
                              uint64_t currentSimNanos,
                              const VehicleConfigMsgF32Payload* vehicleConfigIn);

/**
 * @brief Run the update step to compute guidance message.
 * @param self             Pointer to the instance.
 * @param currentSimNanos  Time stamp for update in nanoseconds.
 * @param navAttIn         Pointer to navigation attitude message payload.
 * @return AttGuidMsgF32Payload  The computed attitude guidance message.
 */
AttGuidMsgF32Payload SunSearchAlgorithm_update(SunSearchAlgorithm* self,
                                               uint64_t currentSimNanos,
                                               const NavAttMsgF32Payload* navAttIn);

/**
 * @brief Set the properties of a slew maneuver (adds to internal array).
 * @param self                 Pointer to the instance.
 * @param slewPropertiesInput  The slew properties to add.
 */
void SunSearchAlgorithm_setSlewProperties(SunSearchAlgorithm* self,
                                          const SlewProperties* slewPropertiesInput);

/**
 * @brief Modify the properties of an existing slew maneuver.
 * @param self                 Pointer to the instance.
 * @param slewPropertiesInput  The new slew properties.
 * @param index                Index of the slew maneuver to modify.
 */
void SunSearchAlgorithm_modifySlewProperties(SunSearchAlgorithm* self,
                                             const SlewProperties* slewPropertiesInput,
                                             uint32_t index);

/**
 * @brief Get the properties of a slew maneuver.
 * @param self  Pointer to the instance.
 * @param index Index of the slew maneuver to retrieve.
 * @return SlewProperties  The properties of the slew maneuver.
 */
SlewProperties SunSearchAlgorithm_getSlewProperties(const SunSearchAlgorithm* self,
                                                    uint32_t index);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // F32XIMERA_SUNSEARCHALGORITHM_C_H
