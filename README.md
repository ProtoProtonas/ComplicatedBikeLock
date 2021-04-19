# ComplicatedBikeLock


![GitHub Logo](/Resources/pilock.png)


## About the project
This project is done as a part of the Real Time Embedded Programming course in the University of Glasgow.
We will attempt to make a smart bike lock with face recognition, RFID authenticator and a keypad.
The whole system will be running locally on a RaspberryPi.

## Prerequisites
Anyone compiling the project should have OpenCV installed on their machine. The version used for this project is 4.5.1.
It is not an easy and straightforward process to install OpenCV so following this tutorial is recommended: https://qengineering.eu/install-opencv-4.5-on-raspberry-pi-4.html

## Hardware used

<ul>
  <li>Raspberry Pi 3B and 4B (tested on both)</li>
  <li>Raspberry Pi Camera V2</li>
  <li>RC522 RFID module</li>
  <li>Computer keyboard</li>
</ul>

## MFRC522 Install Guide
MRFC522 Library for Raspberry Pi
First of all we have to install the C library for Broadcom BCM 2835
`wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.xx.tar.gz
tar -zxf bcm2835-1.xx.tar.gz
cd bcm2835-1.xx
./configure
make
sudo make check
sudo make install`

## Pin Layouts
![Connection](https://user-images.githubusercontent.com/77743131/115311606-d314ef00-a167-11eb-9365-c87091a8fba3.png)
![Pin Layout](https://user-images.githubusercontent.com/77743131/113899392-ac98a080-97c4-11eb-9763-6e3b3c75fe24.PNG)

## License

Project is distributed under GNU General Public License v3.0

## Contributors

Augustas Sereika [@au6155](https://github.com/au6155) - 2240329S@student.gla.ac.uk
<br />
Haris Khan [@khan-haris](https://github.com/khan-haris) - 2515165K@student.gla.ac.uk
<br />
Radovan Sramek [@HOMELE55](https://github.com/HOMELE55) - 2265715S@student.gla.ac.uk
<br />

## Marketing
<!-- Twitter page [@BikeComplicated](https://twitter.com/BikeComplicated) -->

This project is marketed on Twitter [@BikeComplicated](https://twitter.com/BikeComplicated) and Instagram [@complicatedlock](https://www.instagram.com/complicatedlock/)
<p align="center">
  <a href="https://twitter.com/BikeComplicated"><img height=100 src="Resources/twitter.png"></img></a>
  <a></a>
  <a href="https://www.instagram.com/complicatedlock/"><img height=100 src="Resources/insta.png"></img></a>
</p>
