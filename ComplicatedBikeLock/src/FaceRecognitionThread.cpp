#include "FaceRecognitionThread.h"

#include <iostream>
#include <thread>

FaceRecognitionThread::FaceRecognitionThread(bool* isCorrect)
{
    isFaceCorrect = isCorrect;
    std::cout << "\nPlease show your face" << std::endl;
}

void FaceRecognitionThread::run() {
    std::cout << "\nRunning face recognition thread" << std::endl;
    *isFaceCorrect = 1;
}

FaceRecognitionThread::~FaceRecognitionThread()
{
    //dtor
}
