//
// Created by Jin-uu on 2023/07/13.
//

#ifndef LIB_MVP_PRESENTER_H_
#define LIB_MVP_PRESENTER_H_

#include <vector>
#include <random>

#include "lib_mvp/view.h"
#include "lib_mvp/circle_model.h"

namespace mvc {

class Presenter {
 public:
  using circles = std::vector<CircleModel>;
  explicit Presenter(int circle_number);

  void Start();

 private:
  static void OnMouseHandler(int event, int x, int y, int flags, void* userdata);

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
  void HandleClickEvent(int x, int y);
  cv::Point GetRandomLocation();
};

}   // namespace mvc

#endif  // LIB_MVP_PRESENTER_H_
