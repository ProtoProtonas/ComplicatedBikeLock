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
        cin >> new_char;
        // the problem is that after a character is entered ENTER key needs to be pressed

        locker.read_character(new_char);

        if (locker.check_password()) { break; }
    }
    return 0;
}
