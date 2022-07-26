cmake_minimum_required(VERSION 3.0.0)
project(self_driving_robot VERSION 0.1.0)

include(CTest)
enable_testing()

#find opencv
#find_package(OpenCV REQUIRED COMPONENTS core videoio imgproc highgui imgcodecs)
#include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(self_driving_robot main.cpp motor_control/odroid_pins.cpp motor_control/engine_control.cpp) 
#target_link_libraries(self_driving_robot ${OpenCV_LIBS})
set_property(TARGET self_driving_robot PROPERTY CXX_STANDARD 20)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
