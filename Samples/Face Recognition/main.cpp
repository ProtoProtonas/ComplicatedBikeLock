#include <iostream>
#include <FaceScanner.h>


using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    FaceScanner scanner;

    while(true) {
        cout << scanner.check_for_correct_face() << endl;
    }

    //cout << scanner.check_for_correct_face() << endl;

    return 0;
}
