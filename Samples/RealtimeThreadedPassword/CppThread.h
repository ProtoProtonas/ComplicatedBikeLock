// taken from https://github.com/berndporr/cppthread

#ifndef CPPTHREAD_H_INCLUDED
#define CPPTHREAD_H_INCLUDED


#include <thread>

class CppThread {
    public:
        void start() {
            uthread.reset(new std::thread(CppThread::exec, this));
        }

        inline void join() {
            if (nullptr != uthread) {
                uthread->join();
                uthread = nullptr;
            }
        }

    protected:
        virtual void run() = 0;

    private:
        // pointer to the thread
        std::unique_ptr<std::thread> uthread = nullptr;

        // static function which points back to the instance
        static void exec(CppThread* cppThread) {
            cppThread->run();
        }
};

#endif // CPPTHREAD_H_INCLUDED
