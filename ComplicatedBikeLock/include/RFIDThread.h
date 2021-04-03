#ifndef RFIDTHREAD_H
#define RFIDTHREAD_H

#include <CppThread.h>

class RFIDThread : public CppThread
{
    public:
        RFIDThread(bool* isCorrect);
        virtual ~RFIDThread();

        //init RFID detector object here

    protected:
        bool *isRFIDCorrect;

    private:
        void run();
};

#endif // RFIDTHREAD_H
