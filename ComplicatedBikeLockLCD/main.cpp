#include <iostream>
#include <PasswordThread.h>
#include <RFIDThread.h>
#include <FaceRecognitionThread.h>
#include <wiringPi.h>
#include <lcd.h>

//USE WIRINGPI PIN NUMBERS
#define LCD_RS  25               //Register select pin  physical pin 37
#define LCD_E   24               //Enable Pin           physical pin 35
#define LCD_D4  23               //Data pin 4           physical pin 33
#define LCD_D5  22               //Data pin 5           physical pin 31
#define LCD_D6  21               //Data pin 6           physical pin 29
#define LCD_D7  14               //Data pin 7           physical pin 23
#define LED_R  28
#define LED_G  27


/* DISCLAIMER

make sure you add "-pthread" option to Project->Build Options... in Compiler Settings->Other options and Linker Settings->Other linker options

*/

// threading logic and class wrappers come courtesy of Professor Bernd Porr and his GitHub repo showing an example of threading logic.
// The repository can be found at https://github.com/berndporr/cppthread


using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    int lcd;
    wiringPiSetup();
    lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);

    lcdPuts(lcd, "Locked");
    digitalWrite(LED_R, HIGH);


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

        digitalWrite(LED_G, HIGH);
        digitalWrite(LED_R, LOW);
        lcdClear(lcd);
        lcdPuts(lcd, "Unlocked");
        delay(3000);
        digitalWrite(LED_G, LOW);
        lcdClear(lcd);
    }


    return 0;
}
