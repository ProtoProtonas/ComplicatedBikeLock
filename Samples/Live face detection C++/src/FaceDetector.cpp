#include "FaceDetector.h"

#include <iostream>
#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

FaceDetector::FaceDetector()
{
    // Haar face detector setup

    if (!face_cascade.load("haar.xml")) {
        std::cerr << "ERROR! Could not load cascade file\n";
    }

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 320);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 240);
    cap.set(cv::CAP_PROP_FPS, 5);

    // FisherFace recognizer setup

}

bool FaceDetector::detect_faces() {

    cap.read(color_frame);
    if (color_frame.empty()) {
        std::cerr << "ERROR! Blank frame grabbed \n";
        return false;
    }

    cv::Mat frame_gray;
    cv::cvtColor(color_frame, frame_gray, cv::COLOR_BGR2GRAY);

    std::vector<cv::Rect> faces;

    face_cascade.detectMultiScale(frame_gray, faces);

    for(uint8_t i = 0; i < faces.size(); i++) {
            // calculate the position of the center and the dimensions of the face and draww an ellipse to mark the face
            cv::Point center(faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2);
            cv::Size radii(faces[i].width/2, faces[i].height/2);

            // draw the ellipse on the frame
            ellipse(color_frame, center, radii, 0, 0, 360, cv::Scalar(255, 255, 0), 4);
        }

        // show live output
        cv::imshow("Live", color_frame);


    if (faces.size() > 0) { return true;}
    return false;
}



FaceDetector::~FaceDetector()
{
    // this method runs when an object of this class is destroyed
}
