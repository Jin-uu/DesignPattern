cmake_minimum_required(VERSION 3.14)
project(mvp_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(mvp_project main.cpp)

find_package(OpenCV REQUIRED)

add_subdirectory(lib_mvp)

target_link_libraries(mvp_project ${OpenCV_LIBRARIES} lib_mvp)
target_include_directories(mvp_project PUBLIC ${OpenCV_INCLUDE_DIR})

