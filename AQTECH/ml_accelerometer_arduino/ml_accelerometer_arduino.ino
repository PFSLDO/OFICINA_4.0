/*
  IMU Capture
  This example uses the on-board IMU to start reading acceleration and gyroscope
  data from on-board IMU and prints it to the Serial Monitor for one second
  when the significant motion is detected.
  You can also use the Serial Plotter to graph the data.
  The circuit:
  - Arduino Nano 33 BLE or Arduino Nano 33 BLE Sense board.
  Created by Don Coleman, Sandeep Mistry
  Modified by Dominic Pajak, Sandeep Mistry
  This example code is in the public domain.
*/
#include<Wire.h>

#define CONVERT_G_TO_MS2    9.80665f
#define FREQUENCY_HZ        50
#define INTERVAL_MS         (1000 / (FREQUENCY_HZ + 1))

const int MPU=0x68;
float aX, aY, aZ;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(115200);
  Serial.println("Started");;
  
  // print the header
  Serial.println("aX,aY,aZ");
}

void loop() {
  
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);   

  // read the acceleration and gyroscope data
  aX=Wire.read()<<8|Wire.read();    
  aY=Wire.read()<<8|Wire.read();  
  aZ=Wire.read()<<8|Wire.read();   

  // print the data in CSV format
  Serial.print(aX * CONVERT_G_TO_MS2);
  Serial.print('\t');
  Serial.print(aY * CONVERT_G_TO_MS2);
  Serial.print('\t');
  Serial.println(aZ * CONVERT_G_TO_MS2);
}
