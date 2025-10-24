add_library(utilities INTERFACE)

target_sources(utilities INTERFACE
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/eigenSupport.h>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/rigidBodyKinematics.hpp>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/messageConversionHelpers.hpp>"
)

target_include_directories(utilities INTERFACE
  "${PROJECT_SOURCE_DIR}"
  "${EIGEN3_DIR}"
)

# Included via -include to ensure it's included before any other translation unit
# Only include freestanding header for RISC-V builds, not for Linux
if(CMAKE_CROSSCOMPILING)
  target_compile_options(utilities INTERFACE
    -include "${EIGEN3_DIR}/Eigen/src/Freestanding/all_freestanding.hpp"
  )
  # Only define EIGEN_FREESTANDING for RISC-V builds, not for Linux
  target_compile_definitions(utilities INTERFACE EIGEN_FREESTANDING=1)
endif()
