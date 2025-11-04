/* MIT License
 *
 Copyright (c) 2025, Laboratory for Atmospheric and Space Physics, University of Colorado at Boulder
 */

#include "inertial3DAlgorithm_c.h"

#include "inertial3DAlgorithm.h"

#include <Eigen/Core>

Inertial3DAlgorithm* Inertial3DAlgorithm_create(void) {
    return reinterpret_cast<Inertial3DAlgorithm*>(new ::Inertial3DAlgorithm());
}

void Inertial3DAlgorithm_destroy(Inertial3DAlgorithm* self) { delete reinterpret_cast<::Inertial3DAlgorithm*>(self); }

void Inertial3DAlgorithm_setSigmaR0N(Inertial3DAlgorithm* self, Vector3f_c sigma_R0N) {
    Eigen::Vector3f vector;
    vector << sigma_R0N.data[0], sigma_R0N.data[1], sigma_R0N.data[2];
    reinterpret_cast<::Inertial3DAlgorithm*>(self)->setSigmaR0N(vector);
}

Vector3f_c Inertial3DAlgorithm_getSigmaR0N(const Inertial3DAlgorithm* self) {
    Eigen::Vector3f vector = reinterpret_cast<const ::Inertial3DAlgorithm*>(self)->getSigmaR0N();
    Vector3f_c out;
    out.data[0] = vector[0];
    out.data[1] = vector[1];
    out.data[2] = vector[2];
    return out;
}

AttRefMsgF32Payload Inertial3DAlgorithm_update(const Inertial3DAlgorithm* self) {
    return reinterpret_cast<const ::Inertial3DAlgorithm*>(self)->update();
}
