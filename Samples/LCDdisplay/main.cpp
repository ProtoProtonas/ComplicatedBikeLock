#include <wiringPi.h>
#include <lcd.h>

//USE WIRINGPI PIN NUMBERS
#define LCD_RS  25               //Register select pin  physical pin 37
#define LCD_E   24               //Enable Pin           physical pin 35
#define LCD_D4  23               //Data pin 4           physical pin 33
#define LCD_D5  22               //Data pin 5           physical pin 31
#define LCD_D6  21               //Data pin 6           physical pin 29
#define LCD_D7  14               //Data pin 7           physical pin 23

//Remember to add "-lwiringPi -lwiringPiDev" option to Project->Build Options... in Compiler Settings->Other options and Linker Settings->Other linker options


int main()
{
    int lcd;
    wiringPiSetup();
    lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);

    lcdPuts(lcd, "Locked");
    delay(1000);
    lcdClear(lcd);

    lcdPuts(lcd, "Unlocked");
    delay(1000);
    lcdClear(lcd);

    return 0;
}
