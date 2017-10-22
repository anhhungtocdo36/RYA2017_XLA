#include <opencv2/opencv.hpp>
#include <cv.h>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;

const string nameWindow1 = "Anh Goc";
const string nameWindow2 = "Trackbars";

int s16_blur_min = 0;
int s16_blur_max = 255;

void Init(){
    namedWindow(nameWindow2, 0);
    createTrackbar("Blue size", nameWindow2, &s16_blur_min, s16_blur_max);
}
int main(){
    Init();
    Mat img_raw, blurred_img;
    img_raw = imread("14398232797931663.bmp", CV_LOAD_IMAGE_UNCHANGED);
    while (1){
        imshow(nameWindow1,img_raw);
        blur(img_raw, blurred_img, Size(s16_blur_min*2+1, s16_blur_min*2+1), Point(-1,-1), BORDER_DEFAULT);
        imshow("Blur", blurred_img);
        if (waitKey(33)=='q')
            break;
    }
    
    return 0;
}