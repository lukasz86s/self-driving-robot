#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

// #include <opencv2/opencv.hpp>
// #include <opencv2/core/core.hpp>
// #include <opencv2/highgui/highgui.hpp>

#include "motor_control/odroid_pins.hpp"
#include "motor_control/engine_control.hpp"
#include <unistd.h>

using namespace std;
//using namespace cv;

void write_to_file(const char* path, int value){
    ofstream my_file(path);
    my_file << value << endl;
}
// void test_openCV(){
//     string image_path = samples::findFile("HappyFish.jpg");
//     Mat img = imread(image_path, IMREAD_COLOR);
//     if(img.empty()){
//         cout << "could not read the image"<< image_path<< endl;
//     }
//     imshow("display window", img);
//     int k = waitKey(0);
// }

int main(int argv, char* args[]){

    printf("start");
    EngineControl* engines = new EngineControl("gpio3C7", "gpio3D1", "gpio3C6", "gpio3D0", "pwmchip1");
    engines->moveForward();
    sleep(5);
    engines->moveStop();
    delete engines;

    return 0;
}
