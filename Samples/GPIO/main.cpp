#include <iostream>
#include <wiringPi.h>


using namespace std;

int main()
{
    wiringPiSetup();
    pinMode(6, OUTPUT);

    while(1)
    {
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        delay(500);
    }



    return 0;
}
