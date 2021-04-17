#include "FaceRecognitionThread.h"
#include "FaceScanner.h"

#include <iostream>
#include <thread>

FaceRecognitionThread::FaceRecognitionThread(bool* isCorrect)
{
    isFaceCorrect = isCorrect;
    std::cout << "\nPlease show your face" << std::endl;
}

void FaceRecognitionThread::run() {
    //std::cout << "\nRunning face recognition thread" << std::endl;
    while(true){
        if(scanner.check_for_correct_face() == 1) { break; }
    }
    std::cout << "Face has been detected successfully\n" << std::endl;
    *isFaceCorrect = 1;
}

FaceRecognitionThread::~FaceRecognitionThread()
{
    //dtor
}
