#include "Lock.h"
#include <iostream>

Lock::Lock()
{
    //ctor

    // need to manually set teh value of the array here
    // also remember to update PASS_LENGTH definition in the header file Lock.h
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

void Lock::read_character(char new_character) {

    for (int i = 1; i < PASS_LENGTH; i++) {
        pass_attempts[i-1] = pass_attempts[i];
    }
    pass_attempts[PASS_LENGTH-1] = new_character;


    /*std::cout << "pass_attempts: ";
    for (int i = 0; i < PASS_LENGTH; i++) {
        std::cout << pass_attempts[i];
    }
    std::cout << std::endl;

    std::cout << "password: ";
    for (int i = 0; i < PASS_LENGTH; i++) {
        std::cout << password[i];
    }
    std::cout << std::endl;*/
}

bool Lock::check_password() {
    for (int i = 0; i < PASS_LENGTH; i++) {
        if (password[i] != pass_attempts[i]) { return false; }
    }
    return true;
}


Lock::~Lock()
{
    //dtor
}
