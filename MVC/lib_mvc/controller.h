//
// Created by Jin-uu on 2023/07/13.
//

#ifndef LIB_MVC_CONTROLLER_H_
#define LIB_MVC_CONTROLLER_H_

#include <vector>
#include <random>

#include "lib_mvc/view.h"
#include "lib_mvc/circle_model.h"

namespace mvc {

class Controller {
 public:
  using circles = std::vector<CircleModel>;
  explicit Controller(int circle_number);

  void Start();

 private:
  const cv::Vec3b kBlack = cv::Vec3b(0, 0, 0);
  const cv::Vec3b kRed = cv::Vec3b(0, 0, 255);
  const int kCircleRadius =  30;
  const int kCircleThickness = 3;

  View view_;
  circles circles_;
  cv::Mat image_;

  void ResetImage();
  void DrawCircles();
  void ShowImage();
  void MoveCircles();
  cv::Point GetRandomLocation();
};

}   // namespace mvc

#endif  // LIB_MVC_CONTROLLER_H_
