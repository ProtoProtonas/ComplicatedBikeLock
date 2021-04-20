#ifndef FACERECOGNITIONTHREAD_H
#define FACERECOGNITIONTHREAD_H


#include <CppThread.h>
#include <FaceScanner.h>

class FaceRecognitionThread : public CppThread
{
    public:
        FaceRecognitionThread(bool* isCorrect);
        virtual ~FaceRecognitionThread();

        FaceScanner scanner;

    protected:
        bool *isFaceCorrect;

    private:
        void run();
};


#endif // FACERECOGNITIONTHREAD_H
