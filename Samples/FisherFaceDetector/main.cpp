
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <fstream>
#include <sstream>
#include <iostream>

#include <cstdlib>
#include <time.h>

using namespace cv;
using namespace cv::face;
using namespace std;


static Mat norm_0_255(InputArray _src) {
    Mat src = _src.getMat();
    // Create and return normalized image
    Mat dst;

    switch(src.channels()) {
        case 1:
            cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
            break;

        case 3:
            cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
            break;

        default:
            src.copyTo(dst);
            break;
    }
    return dst;

}


static void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
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

int main(int argc, const char *argv[])
{
    cout << "Hello world!" << endl;

    // check for valid cli arguments, print usage if no args given
    if(argc < 2) {
        cout << "usage: " << argv[0] << " <csv.ext> <output_folder>" << endl;
        exit(1);
    }

    string output_folder = ".";
    if(argc == 3) {
        output_folder = string(argv[2]);
    }

    // get the path to a .csv
    string fn_csv = string(argv[1]);

    // these vectors hold the images and the corresponding labels
    vector<Mat> images;
    vector<int> labels;

    // read in the data. This can fail if no valid input filename is given
    try {
        read_csv(fn_csv, images, labels);
    } catch (const cv::Exception& e) {
        cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl;
        exit(1); // not much else can be done
    }

    // quit if there are not enough images
    if(images.size() <= 1) {
        string error_message = "This demo needs at least 2 images to work. Please add more to the dataset";
        CV_Error(Error::StsError, error_message);
    }

    // get the height of the first image to be able to reshape other images to their original size
    int height = images[0].rows;

    // remove the last images from the vector to make sure test and training data do not overlap

    srand(time(0));
    int random_index = rand() % 24;
    cout << random_index << endl;
    Mat testSample = images[random_index];
    int testLabel = labels[random_index];
    //images.pop_back();
    //labels.pop_back();

    Ptr<FisherFaceRecognizer> model = FisherFaceRecognizer::create();
    model->train(images, labels);

    // do the actual prediction
    int predictedLabel = model->predict(testSample);

    cout << format("Predicted class = %d / Actual class = %d.", predictedLabel, testLabel) << endl;

    Mat eigenvalues = model->getEigenValues();
    Mat W = model->getEigenVectors();
    Mat mean = model->getMean();

    // display or save
    if(argc == 2) {
        imshow("mean", norm_0_255(mean.reshape(1, images[0].rows)));
    } else {
        imwrite(format("%s/mean.jpg", output_folder.c_str()), norm_0_255(mean.reshape(1, images[0].rows)));
    }

    // display or save 16 faces at most
    for (int i = 0; i < min(16, W.cols); i++) {
        cout << format("Eigenvalue #%d = %.5f", i, eigenvalues.at<double>(i)) << endl;

        Mat ev = W.col(i).clone();
        Mat grayscale = norm_0_255(ev.reshape(1, height));
        // show the image and apply a Bone colormap for better sensing
        Mat cgrayscale;
        applyColorMap(grayscale, cgrayscale, COLORMAP_BONE);

        // display or save
        if(argc == 2) {
            imshow(format("fisherface_%d", i), cgrayscale);
        } else {
            imwrite(format("%s/fisherface_%d.png", output_folder.c_str(), i), norm_0_255(cgrayscale));
        }
    }

    for(int num_component = 0; num_component < min(16, W.cols); num_component++) {
        // slice the Fisherface from the model
        Mat ev = W.col(num_component);
        Mat projection = LDA::subspaceProject(ev, mean, images[0].reshape(1, 1));
        Mat reconstruction = LDA::subspaceReconstruct(ev, mean, projection);
        // normalize the result
        reconstruction = norm_0_255(reconstruction.reshape(1, images[0].rows));

        // display or save
        if(argc == 2) {
            imshow(format("fisherface_reconstruction_%d", num_component), reconstruction);
        } else {
            imwrite(format("%s/fisherface_reconstruction_%d.png", output_folder.c_str(), num_component), reconstruction);
        }
    }

    if(argc == 2) {
        waitKey(0);
    }
    return 0;
}
