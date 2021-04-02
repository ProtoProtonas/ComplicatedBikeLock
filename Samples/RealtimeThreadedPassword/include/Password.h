#ifndef PASSWORD_H
#define PASSWORD_H


#define PASS_LENGTH 8

class Password
{
    public:
        Password();

        void read_character(char new_character);
        bool check_password();
        char pass_attempts[PASS_LENGTH];

        virtual ~Password();

    protected:

    private:

        char password[PASS_LENGTH];
};


#endif // PASSWORD_H
