#include "i2c_hal.h"
#include "MPU6050.h"

MPU6050 sensor1{0x68};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial) ;
  i2c::init();
  Serial.println("Init done");
  delay(1000);
  Serial.println(sensor1.begin());
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print("Received byte: ");
  //Serial.println(i2c::readFromAddr(0x68, 0x75), HEX);
  Serial.println("==================================");
  auto ret = sensor1.readRawGyro();
  Serial.print("X: ");
  Serial.println(ret.x);
  Serial.print("Y: ");
  Serial.println(ret.y);
  Serial.print("Z: ");
  Serial.println(ret.z);
  delay(1000);
}
