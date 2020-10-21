cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(GPU_NMS)

## 1. Find libtorch 
set(CMAKE_PREFIX_PATH /home/tanfeiyang/workspace/python_cpp_programming/libtorch)
find_package(Torch REQUIRED)
message(${TORCH_INCLUDE_DIRS})

include_directories(SYSTEM ${TORCH_INCLUDE_DIRS})

## 2. Find CUDA
set( CMAKE_CUDA_COMPILER "/usr/local/cuda/bin/nvcc")
find_package(CUDA)
if(NOT CUDA_FOUND)
    message(FATAL_ERROR "CUDA not found")
else()
    message(STATUS "LOG: FIND CUDA")
    enable_language("CUDA")
endif()

include_directories(/usr/local/cuda-10.0/include)

## 3.Find Pybind11
find_package(pybind11 CONFIG REQUIRED)
if(pybind11_FOUND)
    MESSAGE( [MAIN] "Found pybind11 v${pybind11_VERSION}: ${pybind11_INCLUDE_DIRS}")
    MESSAGE( [Main] " pybind11_INCLUDE_DIRS = ${pybind11_INCLUDE_DIRS}")
    MESSAGE( [Main] " pybind11_LIBRARIES = ${pybind11_LIBRARIES}")
elseif()
    message(FATAL_ERROR "pybind11 has NOT been installed!")
endif()
include_directories(${pybind11_INCLUDE_DIRS})

## 4. CPU lib
add_library(nms_cpu SHARED src/cpu/nms_cpu.cpp)
target_link_libraries(nms_cpu ${TORCH_LIBRARIES})

## 5. GPU lib
cuda_add_library(nms_cuda SHARED src/cuda/nms_cuda.cpp src/cuda/nms_kernel.cu)
target_compile_features(nms_cuda PUBLIC cxx_std_11)
target_link_libraries(nms_cuda  ${CUDA_LIBRARIES})
set_target_properties(nms_cuda PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

##6. Pybind for Python lib
pybind11_add_module(nms_cuda_python src/nms_ext.cpp)
target_link_libraries(nms_cuda_python PRIVATE nms_cpu nms_cuda)

## Add execuatable 
add_executable(main main.cpp)
target_link_libraries(main ${TORCH_LIBRARIES} nms_cuda)
#target_link_libraries(main PRIVATE nms_cuda)
set_property(TARGET main PROPERTY CXX_STANDARD 14)
