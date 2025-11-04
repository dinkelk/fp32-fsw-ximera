/* MIT License
 *
 * Copyright (c) 2025, Laboratory for Atmospheric and Space Physics, University of Colorado at Boulder
 */

#ifndef F32XIMERA_STEPPER_MOTOR_CONTROLLER_TYPES_H
#define F32XIMERA_STEPPER_MOTOR_CONTROLLER_TYPES_H

#include <stdbool.h>
#include <stdint.h>

#include "msgPayloadDef/MotorStepCommandMsgPayload.h"

#ifndef __cplusplus
#ifndef bool
#define bool _Bool
#endif
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Output data produced by the StepperMotorControllerAlgorithm.
 */
typedef struct {
    MotorStepCommandMsgPayload motorStepCommandOut; /**< Commanded motor steps output message */
    bool writeOutputMessage;                        /**< True when the output message must be written */
} StepperMotorControllerOutput;

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // F32XIMERA_STEPPER_MOTOR_CONTROLLER_TYPES_H
