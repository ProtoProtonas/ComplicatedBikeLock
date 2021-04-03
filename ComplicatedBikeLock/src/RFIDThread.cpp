#include "RFIDThread.h"

#include <iostream>
#include <thread>

RFIDThread::RFIDThread(bool* isCorrect)
{
    isRFIDCorrect = isCorrect;
    std::cout << "\nRunning RFID thread" << std::endl;
}

void RFIDThread::run() {
    std::cout << "\nPlease present a valid RFID card" << std::endl;
    *isRFIDCorrect = 1;
}

RFIDThread::~RFIDThread()
{
    //dtor
}
