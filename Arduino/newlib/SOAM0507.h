
#ifndef SOAM0507_H     
#define SOAM0507_H     

#include <Arduino.h>  
#include <SPI.h>      

void SOAM0507_init(int csPin, float vdd); 
int SOAM0507_readChannel(byte channel);   
float SOAM0507_convertToVoltage(int adcValue); 

#endif  
