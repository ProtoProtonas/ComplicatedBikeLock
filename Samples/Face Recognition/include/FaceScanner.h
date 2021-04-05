#ifndef FACESCANNER_H
#define FACESCANNER_H


//#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>


class FaceScanner
{
    public:
        FaceScanner();
        virtual ~FaceScanner();

        int check_for_correct_face();

    protected:

    private:

        // Video capture stuff
        cv::VideoCapture cap = cv::VideoCapture(0);
        cv::Mat color_frame;
        cv::Mat gray_frame;
        cv::Mat face_frame;

        // Haar cascade stuff
        cv::CascadeClassifier face_cascade;

        // FisherFace recognizer stuff
        static cv::Mat norm_0_255(cv::InputArray _src);
        static void read_csv(const std::string& filename, std::vector<cv::Mat>& images, std::vector<int>& labels, char separator = ';');
        std::string fn_csv;
        cv::Ptr<cv::face::FisherFaceRecognizer> FisherFaceModel = cv::face::FisherFaceRecognizer::create(2, DBL_MAX);
};

#endif // FACESCANNER_H
