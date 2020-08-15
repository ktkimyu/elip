message(STATUS "Extensible Library for solving Inverse Problems")
message(STATUS "Cmake ${CMAKE_VERSION}\n")

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Require C++11 and disable extensions for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

################################################################################
# Project
################################################################################
project(ELIP)
set(${CMAKE_PROJECT_NAME}_VERSION_MAJOR "0")
set(${CMAKE_PROJECT_NAME}_VERSION_MINOR "0")
set(${CMAKE_PROJECT_NAME}_VERSION_PATCH "0")
set(${CMAKE_PROJECT_NAME}_VERSION ${${CMAKE_PROJECT_NAME}_VERSION_MAJOR}.${${CMAKE_PROJECT_NAME}_VERSION_MINOR}.${${CMAKE_PROJECT_NAME}_VERSION_PATCH})

set(PROJECT_ROOT_NAME "Elip")

################################################################################
# Find packages
################################################################################
include(FeatureSummary)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Boost
#-------------------------------------------------------------------------------
#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.50 REQUIRED COMPONENTS filesystem)

set_package_properties(Boost PROPERTIES TYPE REQUIRED
    DESCRIPTION "Boost C++ libraries"
    URL "http://www.boost.org")

# Eigen3 
#-------------------------------------------------------------------------------
# FIXME: this is only valid to my platform
set(ENV{EIGEN3_ROOT_DIR} "/Users/ktkim/cpplib/eigen")

find_package (Eigen3 3.3 REQUIRED)

set_package_properties(Eigen3 PROPERTIES 
    TYPE REQUIRED
    DESCRIPTION "Lightweight C++ template library for linear algebra"
    URL "http://eigen.tuxfamily.org")

feature_summary(WHAT ALL)

################################################################################
# Compile, link and install libraries
################################################################################
add_subdirectory(src)

enable_testing()
add_subdirectory(test)

################################################################################
# Create cmake files
################################################################################
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_ROOT_NAME}ConfigVersion.cmake"
    VERSION ${${CMAKE_PROJECT_NAME}_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file("${CMAKE_SOURCE_DIR}/cmake/config/${PROJECT_ROOT_NAME}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_ROOT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_ROOT_NAME}"
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_ROOT_NAME}ConfigVersion.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_ROOT_NAME}Config.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_ROOT_NAME}"
)

install(EXPORT "${PROJECT_ROOT_NAME}Targets"
    NAMESPACE ${PROJECT_ROOT_NAME}::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_ROOT_NAME}"
)
