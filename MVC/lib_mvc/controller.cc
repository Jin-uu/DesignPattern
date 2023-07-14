//
// Created by Jin-uu on 2023/07/13.
//

#include "lib_mvc/controller.h"

namespace mvc {

Controller::Controller(int circle_number)
    : view_() {
  image_ = cv::Mat(view_.window_size(), CV_8UC3);
  for (int i = 0; i < circle_number; i++) {
    circles_.emplace_back(GetRandomLocation(), kRed,
                          kCircleRadius, kCircleThickness);
  }
}

void Controller::Start() {
  cv::namedWindow(view_.window_name(), cv::WINDOW_AUTOSIZE);
  cv::setMouseCallback(view_.window_name(), OnMouseHandler, this);

  for (;;) {
    ResetImage();
    DrawCircles();

    ShowImage();

    MoveCircles();

    const auto key = cv::waitKeyEx(10);
    if (key == 27) {
      break;
    }
  }
}

void Controller::OnMouseHandler(int event, int x, int y, int flags, void* userdata) {
  auto controller = static_cast<Controller*>(userdata);
  if (event == cv::EVENT_LBUTTONDOWN) {
    controller->HandleClickEvent(x, y);
  }
}

void Controller::ResetImage() {
  view_.ResetImage(&image_, kBlack);
}

void Controller::DrawCircles() {
  for (const auto& circle : circles_) {
    view_.DrawCircle(&image_, circle);
  }
}

void Controller::ShowImage() {
  view_.ShowImage(image_);
}

void Controller::MoveCircles() {
  for (auto& circle : circles_) {
    const auto new_target = GetRandomLocation();
    const auto new_direction  = (new_target - circle.location()) / cv::norm(new_target - circle.location());
    const auto new_location = circle.location() + new_direction;
    circle.set_location(new_location);
  }
}

void Controller::HandleClickEvent(int x, int y) {
  for (auto& circle : circles_) {
    if (cv::norm(circle.location() - cv::Point(x, y)) <= circle.radius()) {
      circle.set_location(GetRandomLocation());
    }
  }
}

cv::Point Controller::GetRandomLocation() {
  static auto gen = std::mt19937(std::random_device {}());
  static auto width_dis = std::uniform_int_distribution<int>(0, view_.window_size().width);
  static auto height_dis = std::uniform_int_distribution<int>(0, view_.window_size().width);
  return cv::Point{width_dis(gen), height_dis(gen)};
}

}   // namespace mvc
