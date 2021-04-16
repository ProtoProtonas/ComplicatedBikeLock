# GPIO




The GPIO pins on the Raspberry Pi can be used quite easily thanks to the 'wiringPi.h' library. The raspberry Pi 4 is capable of digital input/output on any of its pins, with some of them even capable of PWM output. Unfortunately, an external module is needed for analogue input/output. 

## wiringPi documentation
The following page is a good guide for the library's core functions: http://wiringpi.com/reference/core-functions/

## Notes
Remember to add "-lwiringPi" option to Project->Build Options... in Compiler Settings->Other options and Linker Settings->Other linker options
