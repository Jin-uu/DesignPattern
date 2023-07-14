
add_library(lib_mvc STATIC
        circle_model.cc
        controller.cc
        view.cc)

target_link_libraries(lib_mvc ${OpenCV_LIBRARIES})
target_include_directories(lib_mvc PUBLIC ${CMAKE_SOURCE_DIR})



