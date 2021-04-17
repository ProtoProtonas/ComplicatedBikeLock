#include "RFIDThread.h"

#include <iostream>
#include <thread>

RFIDThread::RFIDThread(bool* isCorrect)
{
    isRFIDCorrect = isCorrect;
}

void RFIDThread::run() {
    std::cout << "Please present a valid RFID card" << std::endl;
    *isRFIDCorrect = 1;
}

RFIDThread::~RFIDThread()
{
    //dtor
}
