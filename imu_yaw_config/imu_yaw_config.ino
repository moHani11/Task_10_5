#include <Wire.h>

int MPU = 0x68; // MPU6050 default I2C address from the datasheet

float GyroZ;
float yaw = 0.0 ;
float timeDiffrence, cTime = 0.0, pTime = 0.0;

void setup() {
  Serial.begin(19200);               //setting a relatively high baud rate for realtmie readings 
  Wire.begin();                      
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);                  // talk to the register 6B (PWR_MGMT_1 register in the datasheet)
  Wire.write(0b10000000);                  // setting the device_reset bit(bit 7) to one so resets all internal registers to their default values.
  // resetting all registers at the beginning of the connection to avoid conflicting the readings with the readings from last time the code was run

  Wire.endTransmission(true);     
  delay(30);
}

void loop() {
 
  pTime = cTime;        
  cTime = millis();            
  timeDiffrence = (cTime - pTime) / 1000; // divide by 1000 to convert ms to s
  // time diffrence is calculated to get the yaw angle using integration as explained in the README

  Wire.beginTransmission(MPU);
  Wire.write(0x47); 
  // Gyro Z-axis data 16-bit data is stored in  registers address (0x47, 0x48)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 2, true); // Read 2 registers (0x47, 0x48)

  GyroZ = ((Wire.read() << 8) | Wire.read()) / 131.0;// For a 250deg/s range we have to divide the value by 131.0 according to the datasheet
  yaw =  yaw + GyroZ * timeDiffrence;
  // calculating yaw as explained in he README and adding the last yaw as 
  // the gyroZ is calculating just the diffrence from last instance 
  // so it should be accumaltive
  
  delay(30);
}
