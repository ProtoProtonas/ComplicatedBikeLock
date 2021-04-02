#ifndef PASSWORDTHREAD_H
#define PASSWORDTHREAD_H

#include "../CppThread.h"
#include "Lock.h"

#define PASS_LENGTH 8

class PasswordThread : public CppThread {
    public:
        PasswordThread(bool* isCorrect);
        virtual ~PasswordThread();

        Lock lock;

    protected:
        bool *isPasswordCorrect;

    private:
        void run();
};

#endif // PASSWORDTHREAD_H
