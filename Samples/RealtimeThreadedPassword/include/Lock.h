#ifndef LOCK_H
#define LOCK_H

#define PASS_LENGTH 8

class Lock
{
    public:
        Lock();

        void read_character(char new_character);
        bool check_password();
        char pass_attempts[PASS_LENGTH];

        virtual ~Lock();

    protected:

    private:

        char password[PASS_LENGTH];
};

#endif // LOCK_H
