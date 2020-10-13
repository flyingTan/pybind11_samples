cmake_minimum_required(VERSION 3.0.0)
project(add_op VERSION 0.1.0)

#include(CTest)
#enable_testing()

find_package(pybind11 CONFIG REQUIRED)
if(pybind11_FOUND)
    MESSAGE( [MAIN] "Found pybind11 v${pybind11_VERSION}: ${pybind11_INCLUDE_DIRS}")
    MESSAGE( [Main] " pybind11_INCLUDE_DIRS = ${pybind11_INCLUDE_DIRS}")
    MESSAGE( [Main] " pybind11_LIBRARIES = ${pybind11_LIBRARIES}")
elseif()
    message(FATAL_ERROR "pybind11 has NOT been installed!")
endif()

include_directories(${pybind11_INCLUDE_DIRS})
message(STATUS ${pybind11_INCLUDE_DIRS})
pybind11_add_module(add_op add.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
