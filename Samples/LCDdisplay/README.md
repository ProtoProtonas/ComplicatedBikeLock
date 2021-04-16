# LCD display




This code is for experimentation with an LCD screen. To connect an LCD screen to a Raspberry Pi, follow this guide. 

![LCD](/Resources/LCDguide.png)

## Guide
https://www.circuitbasics.com/raspberry-pi-lcd-set-up-and-programming-in-c-with-wiringpi/

## Notes
Unlike just using GPIO, the LCD screen requires one more option so add "-lwiringPi - lwiringPiDev" option to Project->Build Options... in Compiler Settings->Other options and Linker Settings->Other linker options.

If you are using Raspberry Pi 4b, there's a chance wiringPi might not work for you out of the box. Here is a guide on how to update to the newest version: http://wiringpi.com/wiringpi-updated-to-2-52-for-the-raspberry-pi-4b/
