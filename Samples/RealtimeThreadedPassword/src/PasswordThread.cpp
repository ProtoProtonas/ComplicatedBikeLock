#include "PasswordThread.h"

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>

/*PasswordThread::PasswordThread(int* pass_correct)
{
    correct_password = pass_correct;

    password[0] = {'p'};
    password[1] = {'a'};
    password[2] = {'s'};
    password[3] = {'s'};
    password[4] = {'w'};
    password[5] = {'o'};
    password[6] = {'r'};
    password[7] = {'d'};
    pass_attempts[0] = {0x0};
}

void PasswordThread::read_character(char new_character) {

    for (int i = 1; i < 8; i++) {
        pass_attempts[i-1] = pass_attempts[i];
    }
    pass_attempts[PASS_LENGTH-1] = new_character;


    std::cout << "pass_attempts: ";
    for (int i = 0; i < PASS_LENGTH; i++) {
        std::cout << pass_attempts[i];
    }
    std::cout << std::endl;

    std::cout << "password: ";
    for (int i = 0; i < PASS_LENGTH; i++) {
        std::cout << password[i];
    }
    std::cout << std::endl;
}

bool PasswordThread::check_password() {
    for (int i = 0; i < PASS_LENGTH; i++) {
        if (password[i] != pass_attempts[i]) { return false; }
    }
    return true;
}

void PasswordThread::run() {
    for(int i = 0; i < 10; i++) {
        printf("%d\n", i + 6000);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    *correct_password = 1;
}*/

PasswordThread::PasswordThread(bool* _isCorrect)
{
    // init
    isPasswordCorrect = _isCorrect;
    std::cout << "Please type in your password: " << std::endl;
}

// code that's actually executing
void PasswordThread::run() {
    char new_char;

    while(true) {
        system("stty raw");
        new_char = getchar();
        system("stty cooked");

        lock.read_character(new_char);
        if (lock.check_password()) { break; }
    }
    *isPasswordCorrect = 1;
}


PasswordThread::~PasswordThread()
{
    //dtor
}
