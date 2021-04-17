#include "FaceScanner.h"

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>

#include <fstream>
#include <sstream>
#include <iostream>

using namespace cv;
using namespace cv::face;
using namespace std;


FaceScanner::FaceScanner()
{
    // setup video capture
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera" << endl;
    }
    cap.set(CAP_PROP_FRAME_WIDTH, 320);
    cap.set(CAP_PROP_FRAME_HEIGHT, 240);
    cap.set(CAP_PROP_FPS, 10);

    // setup haar cascade face detector
    if(!face_cascade.load("resources/haar.xml")) {
        cerr << "ERROR! Could not load Haar face cascade file" << endl;
    }

    // setup FisherFace recognizer
    string fn_csv = "resources/tree.csv";
    vector<Mat> images;
    vector<int> labels;

    // read pictures and store them in variables
    try { read_csv(fn_csv, images, labels); }
    catch(const cv::Exception& e) { cerr << "Error opening .csv file. Reason: " << e.msg << endl; }
    if(images.size() <= 1) { CV_Error(Error::StsError, "This algorithm needs at least two images to work. Please expand the dataset"); }

    // actaully train the model
    FisherFaceModel->train(images, labels);
}


Mat FaceScanner::norm_0_255(InputArray _src) {

    Mat src = _src.getMat();
    // Create and return normalized image
    Mat dst;

    switch(src.channels()) {
        case 1:
            normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
            break;

        case 3:
            normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
            break;

        default:
            src.copyTo(dst);
            break;
    }
    return dst;
}

void FaceScanner::read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator) {
    ifstream file(filename.c_str(), ifstream::in);
    if(!file) {
        string error_message = "No valid input file was given. Check the filename.";
        CV_Error(Error::StsBadArg, error_message);
    }

    string line, path, classlabel;
    while(getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);

        if(!path.empty() && !classlabel.empty()) {
            images.push_back(imread(path, 0));
            labels.push_back(atoi(classlabel.c_str()));
        }
    }
}

// checks the current frame for a known face
// returns -1 if no face is recognized
int FaceScanner::check_for_correct_face()
{
    // read video stream
    cap.read(color_frame);
    if(color_frame.empty()) {
        cerr << "ERROR: Blank frame grabbed" << endl;
        return -1;
    }

    // Haar cascade
    cvtColor(color_frame, gray_frame, COLOR_BGR2GRAY); // convert current frame to grayscale

    vector<Rect> faces; // placeholder for coordinates of all faces in the current frame

    face_cascade.detectMultiScale(gray_frame, faces); // actually detects the faces using Haar cascade

    if(faces.size() == 0) { return -1; } // if no face is detected the obviously no positive faces will be found and the method can return

    int predictedLabel = -1;

    for(uint8_t i = 0; i < faces.size(); i++) {
        // crop out a section of the original frame with the face
        face_frame = gray_frame(Rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height));

        if(!face_frame.empty()) {
            try {
                resize(face_frame, face_frame, Size(128, 128), 1.0, 1.0, INTER_AREA);

                // apply FisherFace detector here
                predictedLabel = FisherFaceModel->predict(face_frame);
                //cout << "predicted label " << predictedLabel << endl;
                return predictedLabel;
            } catch(const cv::Exception& e) { cout << "Something went wrong while recognizing a face\n";}
        }
    }

    return -1;
}

FaceScanner::~FaceScanner()
{
    //dtor
}
