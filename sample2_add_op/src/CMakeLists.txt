cmake_minimum_required(VERSION 3.0)

## 1. Find pybind library
find_package(pybind11 CONFIG REQUIRED)
if(pybind11_FOUND)
    MESSAGE( [MAIN] "Found pybind11 v${pybind11_VERSION}: ${pybind11_INCLUDE_DIRS}")
    MESSAGE( [Main] " pybind11_INCLUDE_DIRS = ${pybind11_INCLUDE_DIRS}")
    MESSAGE( [Main] " pybind11_LIBRARIES = ${pybind11_LIBRARIES}")
elseif()
    message(FATAL_ERROR "pybind11 has NOT been installed!")
endif()

include_directories(${pybind11_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
message(STATUS ${pybind11_INCLUDE_DIRS})

## 2. Generate executable and library

# 2.1 Generate lib
add_library(add_op SHARED add_op.cpp)
target_include_directories(add_op
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include)

# 2.2 Generate python lib
pybind11_add_module(add_op_python add_op_python.cpp)
target_link_libraries(add_op_python PRIVATE add_op)

# 2.3 Generate executable pro
add_executable(sample_test sample_test.cpp)
target_link_libraries(sample_test PRIVATE add_op)
#target_include_directories(sample_test PRIVATE ${PROJECT_SOURCE_DIR}/include)