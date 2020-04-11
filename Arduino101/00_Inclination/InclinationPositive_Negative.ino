// Calculate the inclination over Y axis
//  Inclination RIGHT To LEFT --> - (NEG)
//  Inclination LEFT To RIGHT --> + (POS)
#include "CurieIMU.h"
 double x;
 double y;
 double z;
 int calibPos = 36; //compensating positive Inclination
void setup() {
  Serial.begin(9600);    //Starting serial port
  while(!Serial); // Waiting the serial port will be open, so, I can see the first measurement

  // Initializing device IMU
  Serial.println("Initializing IMU ...");
  CurieIMU.begin();

}

void loop() {

  int ax, ay, az;

  CurieIMU.readAccelerometer(ax, ay, az);
  // Maaping reading values from -90 to 90 grades (-π  to  π )
  float xAng = map(ax, (-32768), (32768), -90, 90);
  float yAng = map(ay, (-32768), (32768), -90, 90);
  float zAng = map(az, (-32768), (32768), -90, 90);

  //Converting from radians to grades
  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);

  Serial.print(" y: "); Serial.println(abs(y));

  int val =0;
  int yy=abs(y);
  if (yy>=1 && yy<=90){
    Serial.print("NEG:");
    val = yy/2.25;
    Serial.println(val);
    }
  if (yy>=270 && yy<=360){
    Serial.print("POS:");
    val =-1 * ((yy-270)/2.25)+calibPos;
    Serial.println(val);
    }
  delay(500);
}
