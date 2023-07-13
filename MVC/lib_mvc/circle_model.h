//
// Created by Jin-uu on 2023/07/13.
//

#ifndef LIB_MVC_CIRCLE_MODEL_H_
#define LIB_MVC_CIRCLE_MODEL_H_

#include "opencv2/opencv.hpp"

namespace mvc {

class CircleModel {
 public:
  CircleModel(cv::Point location, const cv::Vec3b& color,
              int radius, int thickness);

  void set_location(const cv::Point& location);
  void set_color(const cv::Vec3b& color);

  [[nodiscard]] cv::Point location() const;
  [[nodiscard]] cv::Vec3b color() const;
  [[nodiscard]] int radius() const;
  [[nodiscard]] int thickness() const;


 private:
  cv::Point location_;
  cv::Vec3b color_;
  int radius_;
  int thickness_;



};

}   // namespace mvc

#endif  // LIB_MVC_CIRCLE_MODEL_H_
