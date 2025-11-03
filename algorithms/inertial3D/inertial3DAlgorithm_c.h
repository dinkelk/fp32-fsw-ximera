/* MIT License
 *
 Copyright (c) 2025, Laboratory for Atmospheric and Space Physics, University of Colorado at Boulder
 */

#ifndef F32XIMERA_INERTIAL3DALGORITHM_C_H
#define F32XIMERA_INERTIAL3DALGORITHM_C_H

#include <stdint.h>

#include "msgPayloadDef/AttRefMsgF32Payload.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Opaque handle to the C++ Inertial3DAlgorithm instance.
 */
typedef struct Inertial3DAlgorithm Inertial3DAlgorithm;

/**
 * @brief POD representation of a 3-vector (Eigen::Vector3f).
 */
typedef struct {
    float data[3];
} Vector3f_c;

/**
 * @brief Construct a new Inertial3DAlgorithm instance.
 * @return Pointer to a new Inertial3DAlgorithm (must be destroyed).
 */
Inertial3DAlgorithm* Inertial3DAlgorithm_create(void);

/**
 * @brief Destroy a previously created Inertial3DAlgorithm.
 * @param self Pointer to the instance to destroy.
 */
void Inertial3DAlgorithm_destroy(Inertial3DAlgorithm* self);

/**
 * @brief Set the reference MRP vector sigma_R0N.
 * @param self      Pointer to the instance.
 * @param sigma_R0N POD three-vector representing sigma_R0N.
 */
void Inertial3DAlgorithm_setSigmaR0N(Inertial3DAlgorithm* self, Vector3f_c sigma_R0N);

/**
 * @brief Get the current reference MRP vector sigma_R0N.
 * @param self Pointer to the instance.
 * @return Vector3f_c Flattened POD containing sigma_R0N.
 */
Vector3f_c Inertial3DAlgorithm_getSigmaR0N(const Inertial3DAlgorithm* self);

/**
 * @brief Compute the inertial attitude reference message.
 * @param self Pointer to the instance.
 * @return AttRefMsgF32Payload Attitude reference message payload.
 */
AttRefMsgF32Payload Inertial3DAlgorithm_update(const Inertial3DAlgorithm* self);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // F32XIMERA_INERTIAL3DALGORITHM_C_H
