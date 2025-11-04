/* MIT License
 *
 * Copyright (c) 2025, Laboratory for Atmospheric and Space Physics, University of Colorado at Boulder
 */

#ifndef F32XIMERA_STEPPER_MOTOR_CONTROLLER_ALGORITHM_C_H
#define F32XIMERA_STEPPER_MOTOR_CONTROLLER_ALGORITHM_C_H

#include <stdbool.h>
#include <stdint.h>

#include "msgPayloadDef/HingedRigidBodyMsgF32Payload.h"
#include "stepperMotorControllerTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Opaque handle to the C++ StepperMotorControllerAlgorithm instance.
 */
typedef struct StepperMotorControllerAlgorithm StepperMotorControllerAlgorithm;

/**
 * @brief Construct a new StepperMotorControllerAlgorithm instance.
 * @return Pointer to a new StepperMotorControllerAlgorithm (must be destroyed).
 */
StepperMotorControllerAlgorithm* StepperMotorControllerAlgorithm_create(void);

/**
 * @brief Destroy a previously created StepperMotorControllerAlgorithm.
 * @param self Pointer to the instance to destroy.
 */
void StepperMotorControllerAlgorithm_destroy(StepperMotorControllerAlgorithm* self);

/**
 * @brief Reset the algorithm state.
 * @param self Pointer to the instance.
 */
void StepperMotorControllerAlgorithm_reset(StepperMotorControllerAlgorithm* self);

/**
 * @brief Run the update step to compute motor step commands.
 * @param self                         Pointer to the instance.
 * @param callTime                     Time stamp for update in nanoseconds.
 * @param hingedRigidBodyMsgTimeWritten Time the input message was written in seconds.
 * @param motorRefAngleIn              Pointer to the motor reference angle payload.
 * @return StepperMotorControllerOutput The computed motor step command and write flag.
 */
StepperMotorControllerOutput StepperMotorControllerAlgorithm_update(
    StepperMotorControllerAlgorithm* self,
    uint64_t callTime,
    float hingedRigidBodyMsgTimeWritten,
    const HingedRigidBodyMsgF32Payload* motorRefAngleIn);

/**
 * @brief Set the initial motor angle.
 * @param self      Pointer to the instance.
 * @param thetaInit Initial motor angle in radians.
 */
void StepperMotorControllerAlgorithm_setThetaInit(StepperMotorControllerAlgorithm* self, float thetaInit);

/**
 * @brief Get the initial motor angle.
 * @param self Pointer to the instance.
 * @return float Initial motor angle in radians.
 */
float StepperMotorControllerAlgorithm_getThetaInit(const StepperMotorControllerAlgorithm* self);

/**
 * @brief Set the motor upper actuation limit.
 * @param self     Pointer to the instance.
 * @param thetaMax Motor upper actuation limit in radians.
 */
void StepperMotorControllerAlgorithm_setThetaMax(StepperMotorControllerAlgorithm* self, float thetaMax);

/**
 * @brief Get the motor upper actuation limit.
 * @param self Pointer to the instance.
 * @return float Motor upper actuation limit in radians.
 */
float StepperMotorControllerAlgorithm_getThetaMax(const StepperMotorControllerAlgorithm* self);

/**
 * @brief Set the motor lower actuation limit.
 * @param self     Pointer to the instance.
 * @param thetaMin Motor lower actuation limit in radians.
 */
void StepperMotorControllerAlgorithm_setThetaMin(StepperMotorControllerAlgorithm* self, float thetaMin);

/**
 * @brief Get the motor lower actuation limit.
 * @param self Pointer to the instance.
 * @return float Motor lower actuation limit in radians.
 */
float StepperMotorControllerAlgorithm_getThetaMin(const StepperMotorControllerAlgorithm* self);

/**
 * @brief Set the motor step angle.
 * @param self      Pointer to the instance.
 * @param stepAngle Motor step angle in radians.
 */
void StepperMotorControllerAlgorithm_setStepAngle(StepperMotorControllerAlgorithm* self, float stepAngle);

/**
 * @brief Get the motor step angle.
 * @param self Pointer to the instance.
 * @return float Motor step angle in radians.
 */
float StepperMotorControllerAlgorithm_getStepAngle(const StepperMotorControllerAlgorithm* self);

/**
 * @brief Set the motor step time.
 * @param self     Pointer to the instance.
 * @param stepTime Motor step time in seconds.
 */
void StepperMotorControllerAlgorithm_setStepTime(StepperMotorControllerAlgorithm* self, float stepTime);

/**
 * @brief Get the motor step time.
 * @param self Pointer to the instance.
 * @return float Motor step time in seconds.
 */
float StepperMotorControllerAlgorithm_getStepTime(const StepperMotorControllerAlgorithm* self);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // F32XIMERA_STEPPER_MOTOR_CONTROLLER_ALGORITHM_C_H
