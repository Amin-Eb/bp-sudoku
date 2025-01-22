########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

list(APPEND gsl-lite_COMPONENT_NAMES gsl::gsl-lite)
list(REMOVE_DUPLICATES gsl-lite_COMPONENT_NAMES)
if(DEFINED gsl-lite_FIND_DEPENDENCY_NAMES)
  list(APPEND gsl-lite_FIND_DEPENDENCY_NAMES )
  list(REMOVE_DUPLICATES gsl-lite_FIND_DEPENDENCY_NAMES)
else()
  set(gsl-lite_FIND_DEPENDENCY_NAMES )
endif()

########### VARIABLES #######################################################################
#############################################################################################
set(gsl-lite_PACKAGE_FOLDER_RELEASE "/root/.conan2/p/gsl-l883b7c727b374/p")
set(gsl-lite_BUILD_MODULES_PATHS_RELEASE )


set(gsl-lite_INCLUDE_DIRS_RELEASE "${gsl-lite_PACKAGE_FOLDER_RELEASE}/include")
set(gsl-lite_RES_DIRS_RELEASE )
set(gsl-lite_DEFINITIONS_RELEASE "-DGSL_TERMINATE_ON_CONTRACT_VIOLATION")
set(gsl-lite_SHARED_LINK_FLAGS_RELEASE )
set(gsl-lite_EXE_LINK_FLAGS_RELEASE )
set(gsl-lite_OBJECTS_RELEASE )
set(gsl-lite_COMPILE_DEFINITIONS_RELEASE "GSL_TERMINATE_ON_CONTRACT_VIOLATION")
set(gsl-lite_COMPILE_OPTIONS_C_RELEASE )
set(gsl-lite_COMPILE_OPTIONS_CXX_RELEASE )
set(gsl-lite_LIB_DIRS_RELEASE )
set(gsl-lite_BIN_DIRS_RELEASE )
set(gsl-lite_LIBRARY_TYPE_RELEASE UNKNOWN)
set(gsl-lite_IS_HOST_WINDOWS_RELEASE 0)
set(gsl-lite_LIBS_RELEASE )
set(gsl-lite_SYSTEM_LIBS_RELEASE )
set(gsl-lite_FRAMEWORK_DIRS_RELEASE )
set(gsl-lite_FRAMEWORKS_RELEASE )
set(gsl-lite_BUILD_DIRS_RELEASE )
set(gsl-lite_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(gsl-lite_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${gsl-lite_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${gsl-lite_COMPILE_OPTIONS_C_RELEASE}>")
set(gsl-lite_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${gsl-lite_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${gsl-lite_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${gsl-lite_EXE_LINK_FLAGS_RELEASE}>")


set(gsl-lite_COMPONENTS_RELEASE gsl::gsl-lite)
########### COMPONENT gsl::gsl-lite VARIABLES ############################################

set(gsl-lite_gsl_gsl-lite_INCLUDE_DIRS_RELEASE "${gsl-lite_PACKAGE_FOLDER_RELEASE}/include")
set(gsl-lite_gsl_gsl-lite_LIB_DIRS_RELEASE )
set(gsl-lite_gsl_gsl-lite_BIN_DIRS_RELEASE )
set(gsl-lite_gsl_gsl-lite_LIBRARY_TYPE_RELEASE UNKNOWN)
set(gsl-lite_gsl_gsl-lite_IS_HOST_WINDOWS_RELEASE 0)
set(gsl-lite_gsl_gsl-lite_RES_DIRS_RELEASE )
set(gsl-lite_gsl_gsl-lite_DEFINITIONS_RELEASE "-DGSL_TERMINATE_ON_CONTRACT_VIOLATION")
set(gsl-lite_gsl_gsl-lite_OBJECTS_RELEASE )
set(gsl-lite_gsl_gsl-lite_COMPILE_DEFINITIONS_RELEASE "GSL_TERMINATE_ON_CONTRACT_VIOLATION")
set(gsl-lite_gsl_gsl-lite_COMPILE_OPTIONS_C_RELEASE "")
set(gsl-lite_gsl_gsl-lite_COMPILE_OPTIONS_CXX_RELEASE "")
set(gsl-lite_gsl_gsl-lite_LIBS_RELEASE )
set(gsl-lite_gsl_gsl-lite_SYSTEM_LIBS_RELEASE )
set(gsl-lite_gsl_gsl-lite_FRAMEWORK_DIRS_RELEASE )
set(gsl-lite_gsl_gsl-lite_FRAMEWORKS_RELEASE )
set(gsl-lite_gsl_gsl-lite_DEPENDENCIES_RELEASE )
set(gsl-lite_gsl_gsl-lite_SHARED_LINK_FLAGS_RELEASE )
set(gsl-lite_gsl_gsl-lite_EXE_LINK_FLAGS_RELEASE )
set(gsl-lite_gsl_gsl-lite_NO_SONAME_MODE_RELEASE FALSE)

# COMPOUND VARIABLES
set(gsl-lite_gsl_gsl-lite_LINKER_FLAGS_RELEASE
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${gsl-lite_gsl_gsl-lite_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${gsl-lite_gsl_gsl-lite_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${gsl-lite_gsl_gsl-lite_EXE_LINK_FLAGS_RELEASE}>
)
set(gsl-lite_gsl_gsl-lite_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${gsl-lite_gsl_gsl-lite_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${gsl-lite_gsl_gsl-lite_COMPILE_OPTIONS_C_RELEASE}>")