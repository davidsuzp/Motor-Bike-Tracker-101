# Motor-Bike-Tracker-101
Repo for a personal project to implement a Motorcycle/Bike Tracker, based on Arduino 101, main features, writing to a SD Card, calculate inclinations, velocity and positioning.

The structure of this project it's based on the electronics, development and finally the enclosures with the stl files.
I hope you enjoy during the construction.

The design and implementation it's based an incremental techniques, so, will be very easy to incorporate different parts and features.

BOM:
    
    * Arduino Genuino 101 https://store.arduino.cc/arduino-101-619 (Retired :( )
    * LCD Display HD44780 (20 X 4) with PCF8574T
    * GPS Ublox NEO-6M-0-001
    
A.- Code and integrations of Arduino Genuino 101 with components:

    0.- Starting with the IMU
        The Arduino 101, contains internally a IMU (https://www.arduino.cc/en/Tutorial/Genuino101CurieIMURawImuDataSerial)
        TODO: comments related to the calculus, several questions appears on this point
        
    1.- Adding a LCD 20X4
        The first approach was with LCD 20X4, including Libraries (I'm trying to recover the original source, for mentioning purposes, but not found the original) due I remembered changes over the original to function propertly.
    
    2.- Adding a GPS NEO 6M
        Different versions starting on 02_GPS/GPSV2, initial testing, a good moment to know the information returned by GPS and also to know the way to initiate the GPS

B.- Electronics and Connections:
    
    * Arduino Genuino 101 + LCD:
    (TODO: Include Fritzing)
    
C.- 3D Printing: 

    * .FCStd --> Freecad file original
    * .stls ---> Files to print directly with slicers
    
At this moment the repo it's under construction, but all the codes and 3d Files to print are ready to use, will be published periodically.

David
