
add_library(lib_mvp STATIC
        circle_model.cc
        controller.cc
        view.cc)

target_link_libraries(lib_mvp ${OpenCV_LIBRARIES})
target_include_directories(lib_mvp PUBLIC ${CMAKE_SOURCE_DIR})



