#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <iostream>
#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

class FaceDetector
{
    public:
        FaceDetector();
        virtual ~FaceDetector();

        bool detect_faces();

        cv::CascadeClassifier face_cascade;
        cv::VideoCapture cap = cv::VideoCapture(0);
        cv::Mat color_frame;

    protected:

    private:
};

#endif // FACEDETECTOR_H
