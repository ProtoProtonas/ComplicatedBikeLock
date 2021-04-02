#include "DemoThread.h"

#include <stdio.h>
#include <chrono>
#include <thread>


DemoThread::DemoThread(int _offset, int* dr)
{
    offset = _offset;
    ptr_to_dr = dr;
}

// code that's actually executing
void DemoThread::run() {
    // just print 10 numbers starting from the offset
    for(int i = 0; i < 10; i++) {
        printf("%d\n", i + offset);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    *ptr_to_dr = 1;
}

DemoThread::~DemoThread()
{
    //dtor
}
