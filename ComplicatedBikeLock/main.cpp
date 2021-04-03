#include <iostream>
#include <PasswordThread.h>
#include <RFIDThread.h>
#include <FaceRecognitionThread.h>

/* DISCLAIMER

make sure you add "-pthread" option to Project->Build Options... in Compiler Settings->Other options and Linker Settings->Other linker options

*/

// threading logic and class wrappers come courtesy of Professor Bernd Porr and his GitHub repo showing an example of threading logic.
// The repository can be found at https://github.com/berndporr/cppthread


using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    bool passwordIsCorrect = false;
    bool faceIsCorrect = false;
    bool RFIDIsCorrect = false;

    PasswordThread pass_thr(&passwordIsCorrect);
    RFIDThread rfid_thr(&RFIDIsCorrect);
    FaceRecognitionThread face_thr(&faceIsCorrect);

    pass_thr.start();
    rfid_thr.start();
    face_thr.start();

    pass_thr.join();
    rfid_thr.join();
    face_thr.join();

    if(passwordIsCorrect && RFIDIsCorrect && faceIsCorrect) {
        cout << "\nBike is unlocked" << endl;
    }


    return 0;
}
