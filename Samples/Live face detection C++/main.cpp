/* the code is copied from these following sources and adapted to our needs
https://docs.opencv.org/3.4/db/d28/tutorial_cascade_classifier.html
https://www.rs-online.com/designspark/beginners-guide-to-computer-vision-with-raspberry-pi-4

*/


#include <iostream>
#include <stdio.h>

#include <FaceDetector.h>

using namespace std;

int main(int argv, char** argc)
{

    FaceDetector detector;
    bool detected = false;

    while(true) {

        detected = detector.detect_faces();
        if (detected == true) {
            cout << "Face has been detected" << endl;
        } else {
            cout << "Face has not been detected" << endl;
        }

    }





    /*

    // create a classifier instance
    CascadeClassifier face_cascade;

    // create fram instances
    Mat frame, frame_gray;

    // create video stream instance and set the resolution (if not set then maximum available is used)
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    // set parameters of video stream
    cap.set(CAP_PROP_FRAME_WIDTH, 320);
    cap.set(CAP_PROP_FRAME_HEIGHT, 240);
    cap.set(CAP_PROP_FPS, 5);


    cout << "Start grabbing" << endl << "Press any key to terminate" << endl;

    for(;;) {
        cap.read(frame);
        if (frame.empty()) {
            cerr << "ERROR! Blank frame grabbed \n";
            break;
        }


        // Prepare data and apply the cascade classifier to detect face(s)


        // convert to grayscale and increase contrast
        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
        equalizeHist(frame_gray, frame_gray);

        // apply the actual cascade classifier
        vector<Rect> faces;
        face_cascade.detectMultiScale(frame_gray, faces);

        for(uint8_t i = 0; i < faces.size(); i++) {
            // calculate the position of the center and the dimensions of the face and draww an ellipse to mark the face
            Point center(faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2);
            Size radii(faces[i].width/2, faces[i].height/2);

            // draw the ellipse on the frame
            ellipse(frame, center, radii, 0, 0, 360, Scalar(255, 255, 0), 4);
        }

        // show live output
        imshow("Live", frame);
        if (waitKey(5) >= 0) {
        // save the last frame as a JPEG
            imwrite("detected.jpg", frame);
            break;
        }
    }

    */

    return 0;
}
