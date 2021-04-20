#include "FaceRecognitionThread.h"
#include "FaceScanner.h"
#include <wiringPi.h>

#include <iostream>
#include <thread>

#define LED_G  27



FaceRecognitionThread::FaceRecognitionThread(bool* isCorrect)
{
    isFaceCorrect = isCorrect;
    std::cout << "\nPlease show your face" << std::endl;
    pinMode(LED_G, OUTPUT);
}

void FaceRecognitionThread::run() {
    //std::cout << "\nRunning face recognition thread" << std::endl;
    while(true){
        if(scanner.check_for_correct_face() == 1) { break; }
    }
    std::cout << "Face has been detected successfully\n" << std::endl;
    digitalWrite(LED_G, HIGH);
    delay(1000);
    digitalWrite(LED_G, LOW);
    *isFaceCorrect = 1;
}

FaceRecognitionThread::~FaceRecognitionThread()
{
    //dtor
}
