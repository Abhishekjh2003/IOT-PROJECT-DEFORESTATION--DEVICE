#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Wire.begin();
  mpu.initialize();
  Serial.begin(9600);
}

void loop() {
  float gyroX, gyroY, gyroZ;
  mpu.getRotation(&gyroX, &gyroY, &gyroZ);
  
  Serial.print("Gyro X: ");
  Serial.print(gyroX);
  Serial.print(" | Gyro Y: ");
  Serial.print(gyroY);
  Serial.print(" | Gyro Z: ");
  Serial.println(gyroZ);
  
  delay(1000);
}
