cmake_minimum_required(VERSION 3.14)
project(mvc_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(mvc_project main.cpp)

find_package(OpenCV REQUIRED)

add_subdirectory(lib_mvc)

target_link_libraries(mvc_project ${OpenCV_LIBRARIES} lib_mvc)
target_include_directories(mvc_project PUBLIC ${OpenCV_INCLUDE_DIR})

