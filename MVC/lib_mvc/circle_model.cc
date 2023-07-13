//
// Created by Jin-uu on 2023/07/13.
//

#include "lib_mvc/circle_model.h"

namespace mvc {

CircleModel::CircleModel(cv::Point location, const cv::Vec3b& color,
                         int radius, int thickness)
    :radius_(radius), thickness_(thickness) {
  set_location(location);
  set_color(color);
}

void CircleModel::set_location(const cv::Point& location) {
  location_ = location;
}

void CircleModel::set_color(const cv::Vec3b& color) {
  color_ = color;
}

cv::Point CircleModel::location() const {
  return location_;
}

cv::Vec3b CircleModel::color() const {
  return color_;
}

int CircleModel::radius() const {
  return radius_;
}

int CircleModel::thickness() const {
  return thickness_;
}

}   // namespace mvc
