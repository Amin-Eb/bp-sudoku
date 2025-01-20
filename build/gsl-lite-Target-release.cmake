# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(gsl-lite_FRAMEWORKS_FOUND_RELEASE "") # Will be filled later
conan_find_apple_frameworks(gsl-lite_FRAMEWORKS_FOUND_RELEASE "${gsl-lite_FRAMEWORKS_RELEASE}" "${gsl-lite_FRAMEWORK_DIRS_RELEASE}")

set(gsl-lite_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET gsl-lite_DEPS_TARGET)
    add_library(gsl-lite_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET gsl-lite_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Release>:${gsl-lite_FRAMEWORKS_FOUND_RELEASE}>
             $<$<CONFIG:Release>:${gsl-lite_SYSTEM_LIBS_RELEASE}>
             $<$<CONFIG:Release>:>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### gsl-lite_DEPS_TARGET to all of them
conan_package_library_targets("${gsl-lite_LIBS_RELEASE}"    # libraries
                              "${gsl-lite_LIB_DIRS_RELEASE}" # package_libdir
                              "${gsl-lite_BIN_DIRS_RELEASE}" # package_bindir
                              "${gsl-lite_LIBRARY_TYPE_RELEASE}"
                              "${gsl-lite_IS_HOST_WINDOWS_RELEASE}"
                              gsl-lite_DEPS_TARGET
                              gsl-lite_LIBRARIES_TARGETS  # out_libraries_targets
                              "_RELEASE"
                              "gsl-lite"    # package_name
                              "${gsl-lite_NO_SONAME_MODE_RELEASE}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${gsl-lite_BUILD_DIRS_RELEASE} ${CMAKE_MODULE_PATH})

########## COMPONENTS TARGET PROPERTIES Release ########################################

    ########## COMPONENT gsl::gsl-lite #############

        set(gsl-lite_gsl_gsl-lite_FRAMEWORKS_FOUND_RELEASE "")
        conan_find_apple_frameworks(gsl-lite_gsl_gsl-lite_FRAMEWORKS_FOUND_RELEASE "${gsl-lite_gsl_gsl-lite_FRAMEWORKS_RELEASE}" "${gsl-lite_gsl_gsl-lite_FRAMEWORK_DIRS_RELEASE}")

        set(gsl-lite_gsl_gsl-lite_LIBRARIES_TARGETS "")

        ######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
        if(NOT TARGET gsl-lite_gsl_gsl-lite_DEPS_TARGET)
            add_library(gsl-lite_gsl_gsl-lite_DEPS_TARGET INTERFACE IMPORTED)
        endif()

        set_property(TARGET gsl-lite_gsl_gsl-lite_DEPS_TARGET
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     $<$<CONFIG:Release>:${gsl-lite_gsl_gsl-lite_FRAMEWORKS_FOUND_RELEASE}>
                     $<$<CONFIG:Release>:${gsl-lite_gsl_gsl-lite_SYSTEM_LIBS_RELEASE}>
                     $<$<CONFIG:Release>:${gsl-lite_gsl_gsl-lite_DEPENDENCIES_RELEASE}>
                     )

        ####### Find the libraries declared in cpp_info.component["xxx"].libs,
        ####### create an IMPORTED target for each one and link the 'gsl-lite_gsl_gsl-lite_DEPS_TARGET' to all of them
        conan_package_library_targets("${gsl-lite_gsl_gsl-lite_LIBS_RELEASE}"
                              "${gsl-lite_gsl_gsl-lite_LIB_DIRS_RELEASE}"
                              "${gsl-lite_gsl_gsl-lite_BIN_DIRS_RELEASE}" # package_bindir
                              "${gsl-lite_gsl_gsl-lite_LIBRARY_TYPE_RELEASE}"
                              "${gsl-lite_gsl_gsl-lite_IS_HOST_WINDOWS_RELEASE}"
                              gsl-lite_gsl_gsl-lite_DEPS_TARGET
                              gsl-lite_gsl_gsl-lite_LIBRARIES_TARGETS
                              "_RELEASE"
                              "gsl-lite_gsl_gsl-lite"
                              "${gsl-lite_gsl_gsl-lite_NO_SONAME_MODE_RELEASE}")


        ########## TARGET PROPERTIES #####################################
        set_property(TARGET gsl::gsl-lite
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     $<$<CONFIG:Release>:${gsl-lite_gsl_gsl-lite_OBJECTS_RELEASE}>
                     $<$<CONFIG:Release>:${gsl-lite_gsl_gsl-lite_LIBRARIES_TARGETS}>
                     )

        if("${gsl-lite_gsl_gsl-lite_LIBS_RELEASE}" STREQUAL "")
            # If the component is not declaring any "cpp_info.components['foo'].libs" the system, frameworks etc are not
            # linked to the imported targets and we need to do it to the global target
            set_property(TARGET gsl::gsl-lite
                         APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                         gsl-lite_gsl_gsl-lite_DEPS_TARGET)
        endif()

        set_property(TARGET gsl::gsl-lite APPEND PROPERTY INTERFACE_LINK_OPTIONS
                     $<$<CONFIG:Release>:${gsl-lite_gsl_gsl-lite_LINKER_FLAGS_RELEASE}>)
        set_property(TARGET gsl::gsl-lite APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                     $<$<CONFIG:Release>:${gsl-lite_gsl_gsl-lite_INCLUDE_DIRS_RELEASE}>)
        set_property(TARGET gsl::gsl-lite APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                     $<$<CONFIG:Release>:${gsl-lite_gsl_gsl-lite_LIB_DIRS_RELEASE}>)
        set_property(TARGET gsl::gsl-lite APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                     $<$<CONFIG:Release>:${gsl-lite_gsl_gsl-lite_COMPILE_DEFINITIONS_RELEASE}>)
        set_property(TARGET gsl::gsl-lite APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                     $<$<CONFIG:Release>:${gsl-lite_gsl_gsl-lite_COMPILE_OPTIONS_RELEASE}>)

    ########## AGGREGATED GLOBAL TARGET WITH THE COMPONENTS #####################
    set_property(TARGET gsl::gsl-lite APPEND PROPERTY INTERFACE_LINK_LIBRARIES gsl::gsl-lite)

########## For the modules (FindXXX)
set(gsl-lite_LIBRARIES_RELEASE gsl::gsl-lite)
