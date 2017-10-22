#include <opencv2/opencv.hpp>
#include <cv.h>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;

const string nameWindow1 = "Anh Goc";
int main(){
    Mat img_raw;
    img_raw = imread("14398232797931663.bmp", CV_LOAD_IMAGE_UNCHANGED);
    while (1){
        imshow(nameWindow1,img_raw);
        if (waitKey(33)=='q')
            break;
    }
    return 0;
}