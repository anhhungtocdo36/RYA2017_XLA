#include <opencv2/opencv.hpp>
#include <cv.h>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;

const string nameWindow1 = "Anh Goc";
const string nameWindow2 = "Trackbars";

int s16_blur_val = 4;
int s16_blur_max = 255;

int s16_H_val = 0;
int s16_H_max = 255;
int s16_S_val = 0;
int s16_S_max = 255;
int s16_V_val = 0;
int s16_V_max = 255;

void Init(){
    namedWindow(nameWindow2, 0);
    createTrackbar("Blue size", nameWindow2, &s16_blur_val, s16_blur_max);
    createTrackbar("H min val", nameWindow2, &s16_H_val, s16_H_max);
    createTrackbar("S min val", nameWindow2, &s16_S_val, s16_S_max);
    createTrackbar("V min val", nameWindow2, &s16_V_val, s16_V_max);

    createTrackbar("H max val", nameWindow2, &s16_H_max, s16_H_max);
    createTrackbar("S max val", nameWindow2, &s16_S_max, s16_S_max);
    createTrackbar("V max val", nameWindow2, &s16_V_max, s16_V_max);
}
int main(){
    Init();
    Mat img_raw, blurred_img, HSV_img, threshold;
    img_raw = imread("14398232797931663.bmp", CV_LOAD_IMAGE_UNCHANGED);
    while (1){
        imshow(nameWindow1,img_raw);
        blur(img_raw, blurred_img, Size(s16_blur_val*2+1, s16_blur_val*2+1), Point(-1,-1), BORDER_DEFAULT);
        //imshow("Blur", blurred_img);
        cvtColor(blurred_img, HSV_img, COLOR_BGR2HSV);
        //imshow("Convert to HSV", HSV_img);

        inRange(HSV_img, Scalar(s16_H_val, s16_S_val, s16_V_val), Scalar(s16_H_max, s16_S_max, s16_V_max), threshold);
        imshow("abc", threshold);
        if (waitKey(33)=='q')
            break;
    }
    
    return 0;
}