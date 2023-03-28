cmake_minimum_required(VERSION 3.14)
project(camera_edge_detector
    VERSION 1.0
    LANGUAGES CXX
)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Boost REQUIRED COMPONENTS program_options)
include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(app)