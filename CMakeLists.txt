cmake_minimum_required(VERSION 3.28)
project(CppProjects)
set(CMAKE_CXX_STANDARD 17)

# minHeap
add_executable(CppProjects minHeap_main.cpp minHeap.cpp)

# Object Detection
set(OpenCV_DIR "C:/Users/froys/Downloads/MLH/opencv-mingw/opencv-mingw/x64/mingw/lib")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(object_detection objDet_main.cpp)
target_link_libraries(object_detection ${OpenCV_LIBS})
message(STATUS "OpenCV_LIBS = ${OpenCV_LIBS}")
message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
