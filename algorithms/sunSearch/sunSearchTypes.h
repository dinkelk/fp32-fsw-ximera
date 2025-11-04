/*
 MIT License

 Copyright (c) 2025, Laboratory for Atmospheric and Space Physics,
 University of Colorado at Boulder
 */

#ifndef F32XIMERA_SUN_SEARCH_TYPES_H
#define F32XIMERA_SUN_SEARCH_TYPES_H

#define NUM_SLEWS 3

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Slew properties for a sun search maneuver.
 */
typedef struct {
    float slewTime;       /*!< [s] total time for the three-axes maneuver */
    float slewAngle;      /*!< [rad] total angle sweep around one axis */
    float slewMaxRate;    /*!< [rad/s] maximum spacecraft body rate norm */
    float slewMaxTorque;  /*!< [Nm] maximum torque for slew */
    int slewRotAxis;      /*!< [-] axes about which to perform the Sun search */
} SlewProperties;

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // F32XIMERA_SUN_SEARCH_TYPES_H
