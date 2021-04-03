#ifndef FACERECOGNITIONTHREAD_H
#define FACERECOGNITIONTHREAD_H


#include <CppThread.h>

class FaceRecognitionThread : public CppThread
{
    public:
        FaceRecognitionThread(bool* isCorrect);
        virtual ~FaceRecognitionThread();

        //init face recognition object here

    protected:
        bool *isFaceCorrect;

    private:
        void run();
};


#endif // FACERECOGNITIONTHREAD_H
