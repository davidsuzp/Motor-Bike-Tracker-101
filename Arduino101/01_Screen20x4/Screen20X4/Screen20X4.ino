#include <Wire.h>
#include "LiquidCrystal_I2C.h"

#include <hd44780.h>
// Calculate the inclination over Y axis
//  Inclination RIGHT To LEFT --> - (NEG)
//  Inclination LEFT To RIGHT --> + (POS)
#include "CurieIMU.h"
 double x;
 double y;
 double z;
 int calibPos = 36; //compensating positive Inclination
LiquidCrystal_I2C lcd(0x27, 20, 4);  // Initializing LCD on 0x27 Address, with 20 chars and 4 lines

void setup() {
  // Starting functions
  startingSerial();
  startingCurieIMU();
  startingLCD20x4();

}

void loop() {
  readInclination();
  delay(250);
}

void startingSerial(){
  //Initializing Serial Port
  Serial.begin(9600);
  //while(!Serial); // not neccesary to wait till the port it's open
  Serial.println("Initializing Serial - 9600)");

}

void startingCurieIMU(){
  // Initializing IMU device IMU (controlling the inclination, for the Arduino 101 it's internal)
  Serial.println("Inicializando IMU ...");
  CurieIMU.begin();

}

void startingLCD20x4(){
  // Initializing 20X4 screen
  lcd.begin();
  lcd.backlight();
  for(int i=0; i<4;i++){
    lcd.setCursor(0, i);
    lcd.print("Testing Screen");
    delay(250);
  }
  lcd.clear();
}

void readInclination(){
  int ax, ay, az;

  CurieIMU.readAccelerometer(ax, ay, az);
  // Maaping reading values from -90 to 90 grades (-π  to  π )
  float xAng = map(ax, (-32768), (32768), -90, 90);
  float zAng = map(az, (-32768), (32768), -90, 90);

  //Converting from radians to grades
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);

  Serial.print(" y: "); Serial.println(abs(y));
  int val =0;
  int yy=abs(y);
  if (yy>=1 && yy<=90)
  {
    Serial.print("NEG:");
    val = yy/2.25;
    Serial.println(val);
    printInclNeg(val,false);
  }
  else if(yy>=270 && yy<=360)
  {
    Serial.print("POS:");
    val =(-1 * ((yy-270)/2.25)+36);
    Serial.println(val);
    printInclPos(val,true);
  }

}

void printInclPos(int val, bool orien){
  String literal;

  lcd.clear();
  if (val>19) val=19;

  if (orien){literal = "+";}

  for(int i=1; i<val+1;i++){
    literal=literal+"|";
  }

  lcd.setCursor(0, 3);
  lcd.print(literal);
}

void printInclNeg(int val, bool orien){
  String literal;

  lcd.clear();
  if (val>19) val=19;

  for(int j=1; j<val+1;j++){
    literal=literal+"|";
  }
  Serial.println(literal);
  if (!orien){literal = literal + "-";}
  Serial.println(literal);
  lcd.setCursor((20-literal.length()), 3);
  lcd.print(literal);
}

// Not used
void printIncl(int val, bool orien){
  String literal;

  lcd.clear();
  if (orien){literal = "+";}
  Serial.print(val);
  Serial.print("::");
  Serial.println(literal);
  Serial.println("----Before Iter--------");
  for(int i=1; i<val;i++){
    literal=literal+"|";
  }
  Serial.println("----After Iter-------");
  if (!orien){literal = "-";}
  Serial.print(val);
  Serial.print(":");
  Serial.println(literal);
  lcd.setCursor((20-literal.length()), 3);
  lcd.print(literal);

}
