/* MIT License
 *
 Copyright (c) 2025, Laboratory for Atmospheric and Space Physics, University of Colorado at Boulder
 */

#ifndef F32XIMERA_RATECONTROLALGORITHM_C_H
#define F32XIMERA_RATECONTROLALGORITHM_C_H

#include "msgPayloadDef/AttGuidMsgF32Payload.h"
#include "msgPayloadDef/CmdTorqueBodyMsgF32Payload.h"
#include "msgPayloadDef/VehicleConfigMsgF32Payload.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Opaque handle to the C++ RateControlAlgorithm instance.
 */
typedef struct RateControlAlgorithm RateControlAlgorithm;

/**
 * @brief POD representation of a 3-vector (Eigen::Vector3f).
 */
typedef struct {
    float data[3];
} Vector3f_c;

/**
 * @brief Construct a new RateControlAlgorithm instance.
 * @return Pointer to a new RateControlAlgorithm (must be destroyed).
 */
RateControlAlgorithm* RateControlAlgorithm_create(void);

/**
 * @brief Destroy a previously created RateControlAlgorithm.
 * @param self Pointer to the instance to destroy.
 */
void RateControlAlgorithm_destroy(RateControlAlgorithm* self);

/**
 * @brief Run the update step to compute control torque.
 * @param self         Pointer to the instance.
 * @param attGuidIn    Pointer to attitude guidance message payload.
 * @return CmdTorqueBodyMsgF32Payload  The computed torque command message.
 */
CmdTorqueBodyMsgF32Payload RateControlAlgorithm_update(RateControlAlgorithm* self,
                                                       const AttGuidMsgF32Payload* attGuidIn);

/**
 * @brief Set the spacecraft inertia from vehicle configuration message.
 * @param self              Pointer to the instance.
 * @param vehicleConfigIn   Pointer to vehicle config message payload.
 */
void RateControlAlgorithm_setSpacecraftInertia(RateControlAlgorithm* self,
                                               const VehicleConfigMsgF32Payload* vehicleConfigIn);

/**
 * @brief Set the derivative gain P.
 * @param self  Pointer to the instance.
 * @param P     [N*m*s] Rate error feedback gain applied.
 */
void RateControlAlgorithm_setDerivativeGainP(RateControlAlgorithm* self, float P);

/**
 * @brief Get the derivative gain P.
 * @param self  Pointer to the instance.
 * @return float  [N*m*s] The current derivative gain.
 */
float RateControlAlgorithm_getDerivativeGainP(const RateControlAlgorithm* self);

/**
 * @brief Set the known external torque about point B.
 * @param self              Pointer to the instance.
 * @param knownTorquePntB_B [N*m] Known external torque in body frame components.
 */
void RateControlAlgorithm_setKnownTorquePntB_B(RateControlAlgorithm* self, Vector3f_c knownTorquePntB_B);

/**
 * @brief Get the known external torque about point B.
 * @param self  Pointer to the instance.
 * @return Vector3f_c  [N*m] The known external torque in body frame components.
 */
Vector3f_c RateControlAlgorithm_getKnownTorquePntB_B(const RateControlAlgorithm* self);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // F32XIMERA_RATECONTROLALGORITHM_C_H
