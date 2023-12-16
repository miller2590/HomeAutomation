# CMakeLists.txt
# 
# This file is used by CMake to build the HomeAutomation project. It specifies the minimum required 
# version of CMake, the project name and version, the languages used (C and C++), and the source files to be compiled.
# It also includes the CTest module for testing, and the CPack module for packaging the software.
# 
# @author Gage Miller

# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.5.0)

# Specify the project name, version, and languages used
project(HomeAutomation VERSION 0.1.0 LANGUAGES C CXX)

# Include the CTest module for testing and the CPack module for packaging
include(CTest)

enable_testing()

# Add the executable target to be built from the source files
add_executable(
    HomeAutomation 
    ./src/main.cpp 
    ./src/HomeController.cpp 
    ./src/Lights.cpp
    ./src/Menu.cpp
    ./src/SecuritySystem.cpp
    ./src/SmartDevice.cpp
    ./src/Television.cpp
    ./src/Thermostat.cpp
    ./src/GenerateUUID.cpp
)

# Add the include directory to the include path
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
