/* MIT License
 *
 * Copyright (c) 2025, Laboratory for Atmospheric and Space Physics, University of Colorado at Boulder
 */

#include "stepperMotorControllerAlgorithm_c.h"
#include "stepperMotorControllerAlgorithm.h"

StepperMotorControllerAlgorithm* StepperMotorControllerAlgorithm_create(void) {
    return reinterpret_cast<StepperMotorControllerAlgorithm*>(new ::StepperMotorControllerAlgorithm());
}

void StepperMotorControllerAlgorithm_destroy(StepperMotorControllerAlgorithm* self) {
    delete reinterpret_cast<::StepperMotorControllerAlgorithm*>(self);
}

void StepperMotorControllerAlgorithm_reset(StepperMotorControllerAlgorithm* self) {
    reinterpret_cast<::StepperMotorControllerAlgorithm*>(self)->reset();
}

StepperMotorControllerOutput StepperMotorControllerAlgorithm_update(
    StepperMotorControllerAlgorithm* self,
    uint64_t callTime,
    float hingedRigidBodyMsgTimeWritten,
    const HingedRigidBodyMsgF32Payload* motorRefAngleIn) {
    return reinterpret_cast<::StepperMotorControllerAlgorithm*>(self)->update(
        callTime, hingedRigidBodyMsgTimeWritten, *motorRefAngleIn);
}

void StepperMotorControllerAlgorithm_setThetaInit(StepperMotorControllerAlgorithm* self, float thetaInit) {
    reinterpret_cast<::StepperMotorControllerAlgorithm*>(self)->setThetaInit(thetaInit);
}

float StepperMotorControllerAlgorithm_getThetaInit(const StepperMotorControllerAlgorithm* self) {
    return reinterpret_cast<const ::StepperMotorControllerAlgorithm*>(self)->getThetaInit();
}

void StepperMotorControllerAlgorithm_setThetaMax(StepperMotorControllerAlgorithm* self, float thetaMax) {
    reinterpret_cast<::StepperMotorControllerAlgorithm*>(self)->setThetaMax(thetaMax);
}

float StepperMotorControllerAlgorithm_getThetaMax(const StepperMotorControllerAlgorithm* self) {
    return reinterpret_cast<const ::StepperMotorControllerAlgorithm*>(self)->getThetaMax();
}

void StepperMotorControllerAlgorithm_setThetaMin(StepperMotorControllerAlgorithm* self, float thetaMin) {
    reinterpret_cast<::StepperMotorControllerAlgorithm*>(self)->setThetaMin(thetaMin);
}

float StepperMotorControllerAlgorithm_getThetaMin(const StepperMotorControllerAlgorithm* self) {
    return reinterpret_cast<const ::StepperMotorControllerAlgorithm*>(self)->getThetaMin();
}

void StepperMotorControllerAlgorithm_setStepAngle(StepperMotorControllerAlgorithm* self, float stepAngle) {
    reinterpret_cast<::StepperMotorControllerAlgorithm*>(self)->setStepAngle(stepAngle);
}

float StepperMotorControllerAlgorithm_getStepAngle(const StepperMotorControllerAlgorithm* self) {
    return reinterpret_cast<const ::StepperMotorControllerAlgorithm*>(self)->getStepAngle();
}

void StepperMotorControllerAlgorithm_setStepTime(StepperMotorControllerAlgorithm* self, float stepTime) {
    reinterpret_cast<::StepperMotorControllerAlgorithm*>(self)->setStepTime(stepTime);
}

float StepperMotorControllerAlgorithm_getStepTime(const StepperMotorControllerAlgorithm* self) {
    return reinterpret_cast<const ::StepperMotorControllerAlgorithm*>(self)->getStepTime();
}
