#include <boost/program_options.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  po::options_description desc("Permitted options");
  desc.add_options()
    ("help,h", "Display help message")
    ("index,i", po::value<int>()->default_value(0), "Camera index to access (default: 0)")
  ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);
  if (vm.count("help")) {
    std::cout << desc << '\n';
    return 1;
  }
  const int camera_index = vm["index"].as<int>();

  std::string cam_title = "Edge converted video";
  cv::namedWindow(cam_title, cv::WINDOW_NORMAL);

  cv::VideoCapture cap;
  cap.open(camera_index);
  if (!cap.isOpened()) {
    std::cerr << "Could not open capture.\n";
    return -2;
  }

  cv::Mat frame, gray_frame, canny_frame;
  for(;;) {
    cap >> frame;
    if (frame.empty()) {
      break;
    }

    cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);
    cv::Canny(gray_frame, canny_frame, 10, 100, 3, true);
    cv::imshow(cam_title, canny_frame);

    if((char) cv::waitKey(33) >= 0) {
      break;
    }
  }

  return 0;
}
