//
// Created by Jin-uu on 2023/07/13.
//

#include "lib_mvp/view.h"

#include <string>

#include "opencv2/opencv.hpp"

namespace mvc {

void View::ShowImage(const cv::Mat& image) {
  cv::imshow(kWindowName, image);
}

std::string View::window_name() {
  return kWindowName;
}

cv::Size View::window_size() {
  return kWindowSize;
}

void View::DrawCircle(cv::Mat* image, const cv::Point& location, const cv::Vec3b& color,
                      const int& radius, const int& thickness) {
  cv::circle(*image, location, radius, color, thickness);
}

void View::ResetImage(cv::Mat* image, const cv::Vec3b& color) {
  *image = color;
}

}   // namespace mvc
