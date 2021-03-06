#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "motor_control/odroid_pins.hpp"

using namespace std;
using namespace cv;

void write_to_file(const char* path, int value){
    ofstream my_file(path);
    my_file << value << endl;
}
void test_openCV(){
    string image_path = samples::findFile("HappyFish.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);
    if(img.empty()){
        cout << "could not read the image"<< image_path<< endl;
    }
    imshow("display window", img);
    int k = waitKey(0);
}

int main(int argv, char* args[]){

    PwmPins* pwm0 = new PwmPins(); 
    PwmPins* pwm1 = new PwmPins("pwmchip1");
    pwm0->initPin();
    pwm1->initPin();
    cout << "test programu, periond " << endl;
    
    GpioPins* a   = new GpioPins("gpio0B3", "dwa", "trzy");

    return 0;
}
