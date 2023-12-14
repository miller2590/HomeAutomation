cmake_minimum_required(VERSION 3.5.0)
project(HomeAutomation VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

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
    ./src/Vacuum.cpp
    ./src/GenerateUUID.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
