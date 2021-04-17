#include "PasswordThread.h"
#include <iostream>

PasswordThread::PasswordThread(bool* _isCorrect)
{
    // init
    isPasswordCorrect = _isCorrect;
}

// code that's actually executing
void PasswordThread::run() {

    std::cout << "Please type in your password: " << std::endl;
    char new_char;

    while(true) {
        system("stty raw");
        new_char = getchar();
        system("stty cooked");

        lock.read_character(new_char);
        if (lock.check_password()) { break; }
    }
    std::cout << std::endl << "Password is correct" << std::endl;
    *isPasswordCorrect = 1;
}


PasswordThread::~PasswordThread()
{
    //dtor
}
