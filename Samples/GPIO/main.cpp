#include <iostream>
#include <wiringPi.h>

//#define LED_PIN 24 // corresponds to GPIO11
#define LED_PIN 25 // corresponds to GPIO26


using namespace std;

int main()
{

    wiringPiSetup();
    pinMode(LED_PIN, OUTPUT);

    while(1)
    {
        digitalWrite(LED_PIN, HIGH);
        delay(500);
        cout << "Written LOW" << endl;
        digitalWrite(LED_PIN, LOW);
        delay(500);
        cout << "Written HIGH" << endl;
    }



    return 0;
}
