#include <SPI.h>
#include "SOAM050.h"
#define SS_PIN 10
#define VDD 5.0
void setup() {
  Serial.begin(57600);
  SOAM050_init(SS_PIN,VDD);
}

void loop() {
  int d0 = SOAM050_readChannel(0);
  int d1 = SOAM050_readChannel(1);
  float a0=SOAM050_convertToVoltage(d0);
  float a1=SOAM050_convertToVoltage(d1);
  Serial.print("D0: "); Serial.print(d0);
  Serial.print("  D1: "); Serial.println(d1);
  Serial.println("----------------------------");
  Serial.print("A0: "); Serial.print(a0);
  Serial.print("  A1: "); Serial.println(a1);
  Serial.println("============================");
  
  delay(500);
}

