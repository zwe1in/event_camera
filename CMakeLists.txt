cmake_minimum_required(VERSION 3.0)

project(EVENT_CAMERA)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(CUDA REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})
cuda_add_library(parameterize src/parameterize.cu src/parameter.cpp)

add_executable(main main.cpp src/IOUtil.cpp src/filter.cpp src/event.cpp src/region.cpp)

target_link_libraries(main ${OpenCV_LIBS} parameterize)