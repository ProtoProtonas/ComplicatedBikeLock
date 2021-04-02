#ifndef DEMOTHREAD_H
#define DEMOTHREAD_H

#include "../CppThread.h"


class DemoThread : public CppThread {
    public:
        DemoThread(int _offset, int* dr);

        virtual ~DemoThread();

    protected:
        int offset;
        int *ptr_to_dr;

    private:
        void run();
};

#endif // DEMOTHREAD_H
