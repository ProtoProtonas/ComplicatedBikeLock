MFRC522 RFID Library Installation
=================================

Raspberry PI library for MFRC522 RFID Tag.

Example program, Read.cpp, which will read rfid cards.

NOTE: xx' here in code below is the bmc2835 version which you can found its latest version on the website
https://www.airspayce.com/mikem/bcm2835/

On the website, e.g., if the latest version is 1.68, the bcm2835 library can be shown as:
http://www.airspayce.com/mikem/bcm2835/bcm2835-1.68.tar.gz 

Make sure the version is latest else it may not work. Replace the 'xx' in the codes given below.

Fetch the tar-file and install it by using below codes on your terminal:

  wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.xx.tar.gz

  tar zxvf bcm2835-1.xx.tar.gz

  cd bcm2835-1.xx

  ./configure

  make

  sudo make check

  sudo make install


To build :

  g++ MFRC522.cpp Read.cpp -std=c++11 -lbcm2835

or directly click the "Build" button on different editors or C/C++ IDE installed on your Raspberry Pi

Pin Layout
----------

The following table shows the pin layout used:

+-----------+----------+-------------+
|           | MFRC522  | Raspberry Pi|
+-----------+----------+-------------+
| Signal    | Pin      | Pin         |
+===========+==========+=============+
| RST/Reset | RST      | 22          |
+-----------+----------+-------------+
| SPI SS    | SDA      | 24          |
+-----------+----------+-------------+
| SPI MOSI  | MOSI     | 19          |
+-----------+----------+-------------+
| SPI MISO  | MISO     | 21          |
+-----------+----------+-------------+
| SPI SCK   | SCK      | 23          |
+-----------+----------+-------------+
| 3V        | 3v       | 1           |
+-----------+----------+-------------+
| GND       | GND      | 25          |
+-----------+----------+-------------+
