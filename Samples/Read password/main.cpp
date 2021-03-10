#include <iostream>
#include <Lock.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Lock locker;
    char new_char;

    cout << "Please enter your password: ";

    while (true) {
        // use some black linux magic to avoid pressing enter key after every character
        // source for the magic : https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
        system("stty raw");
        new_char = getchar();
        system("stty cooked");

        locker.read_character(new_char);
        if (locker.check_password()) { break; }
    }
    return 0;
}
