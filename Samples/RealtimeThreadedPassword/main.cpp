#include <iostream>
#include <DemoThread.h>
#include <PasswordThread.h>


/* DISCLAIMER

make sure you add "-pthread" option to Project->Build Options... in Compiler Settings->Other options and Linker Settings->Other linker options

*/

// threading logic and class wrappers come courtesy of Professor Bernd Porr and his GitHub repo showing an example of threading logic.
// The repository can be found at https://github.com/berndporr/cppthread

using namespace std;

int main(int argc, const char* argv[])
{
    cout << "Hello world!" << endl;

    int done_running1 = 0;
    int done_running2 = 0;
    int done_running3 = 0;

    DemoThread demoThr1(10, &done_running1);
    DemoThread demoThr2(20, &done_running2);
    DemoThread demoThr3(30, &done_running3);

    demoThr1.start();
    demoThr2.start();
    demoThr3.start();

    demoThr1.join();
    demoThr2.join();
    demoThr3.join();

    cout << done_running1 << endl;
    cout << done_running2 << endl;
    cout << done_running3 << endl;

    bool correct_password = false;
    PasswordThread pass_thr(&correct_password);

    pass_thr.start();
    pass_thr.join();

    cout << "\nThe password is correct!" << endl;

    return 0;
}
