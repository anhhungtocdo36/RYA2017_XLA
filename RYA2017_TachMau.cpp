#include <opencv2/opencv.hpp>
#include <cv.h>
#include <string>
#include <iostream>
#include <vector>

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

int s16_H_val_Pink = 123;
int s16_H_max_Pink = 159;
int s16_S_val_Pink = 81;
int s16_S_max_Pink = 201;
int s16_V_val_Pink = 0;
int s16_V_max_Pin = 255;

// int s16_H_val = 62;
// int s16_H_max = 89;
// int s16_S_val = 74;
// int s16_S_max = 177;
// int s16_V_val = 0;
// int s16_V_max = 255;

// int s16_H_val = 0;
// int s16_H_max = 255;
// int s16_S_val = 0;
// int s16_S_max = 255;
// int s16_V_val = 0;
// int s16_V_max = 255;

Scalar pink_min = Scalar(123,81,0);
Scalar pink_max = Scalar(159,201,255);

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
    Mat img_raw, blurred_img, HSV_img, threshold, result_img;
    img_raw = imread("14398232797931663.bmp", CV_LOAD_IMAGE_UNCHANGED);
    vector <vector <Point> > contours;
    vector <Vec4i> hierarchy;

    while (1){
        result_img = img_raw.clone();
        imshow(nameWindow1,img_raw);
        blur(img_raw, blurred_img, Size(s16_blur_val*2+1, s16_blur_val*2+1), Point(-1,-1), BORDER_DEFAULT);
        //imshow("Blur", blurred_img);
        cvtColor(blurred_img, HSV_img, COLOR_BGR2HSV);
        //imshow("Convert to HSV", HSV_img);

        //inRange(HSV_img, Scalar(s16_H_val, s16_S_val, s16_V_val), Scalar(s16_H_max, s16_S_max, s16_V_max), threshold);
        inRange(HSV_img, pink_min,pink_max, threshold);

        findContours(threshold, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
        int area;
        for(int i = 0;i<contours.size(); i++){
            area = contourArea(contours.at(i));
            if (area > 3000){
                RotatedRect rect = minAreaRect(contours.at(i));
                putText(result_img, "RESULT OBJECT", rect.center, FONT_HERSHEY_COMPLEX, 0.8, Scalar(255,255,255),1);
                drawContours(result_img, contours,i,Scalar(255,255,255),1);
            }
        }
        imshow("new", result_img);
        imshow("abc", threshold);
        if (waitKey(33)=='q')
            break;
    }
    
    return 0;
}