//
// Created by Jin-uu on 2023/07/13.
//

#ifndef LIB_MVC_VIEW_H_
#define LIB_MVC_VIEW_H_

#include <string>

#include "lib_mvc/circle_model.h"

#include "opencv2/opencv.hpp"

namespace mvc {

class View {
 public:
  View() = default;

  void ShowImage(const cv::Mat& image);

  cv::Size window_size();
  std::string window_name();

  void DrawCircle(cv::Mat* image, const CircleModel& circle);

  void ResetImage(cv::Mat* image, const cv::Vec3b& color);

 private:
  const std::string kWindowName = "window";
  const cv::Size kWindowSize {1200, 900};
};

}   // namespace mvc

#endif  // LIB_MVC_VIEW_H_
