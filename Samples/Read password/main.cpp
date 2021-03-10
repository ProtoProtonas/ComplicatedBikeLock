#include <iostream>
#include <Lock.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Lock locker;
    char new_char;

    while (true) {
        cout << "Please enter a character: ";

        // use some black linux magic to avoid pressing enter key after every character
        system("stty raw");
        new_char = getchar();
        system("stty cooked");

        locker.read_character(new_char);
        if (locker.check_password()) { break; }
    }
    return 0;
}
