########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(gsl-lite_FIND_QUIETLY)
    set(gsl-lite_MESSAGE_MODE VERBOSE)
else()
    set(gsl-lite_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/gsl-liteTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${gsl-lite_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(gsl-lite_VERSION_STRING "0.40.0")
set(gsl-lite_INCLUDE_DIRS ${gsl-lite_INCLUDE_DIRS_RELEASE} )
set(gsl-lite_INCLUDE_DIR ${gsl-lite_INCLUDE_DIRS_RELEASE} )
set(gsl-lite_LIBRARIES ${gsl-lite_LIBRARIES_RELEASE} )
set(gsl-lite_DEFINITIONS ${gsl-lite_DEFINITIONS_RELEASE} )


# Only the last installed configuration BUILD_MODULES are included to avoid the collision
foreach(_BUILD_MODULE ${gsl-lite_BUILD_MODULES_PATHS_RELEASE} )
    message(${gsl-lite_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


