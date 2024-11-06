#include "SOAM0507.h" 
static int _ssPin;   
static float _vdd;   
void SOAM0507_init(int ssPin, float vdd) {
    _ssPin = ssPin;  
    _vdd = vdd;  
    SPI.begin(); 
    SPI.beginTransaction(SPISettings(500000, MSBFIRST, SPI_MODE0));
    pinMode(_ssPin, OUTPUT);  
}
int SOAM0507_readChannel(byte channel) {
    byte highByteA, lowByteA;  
    int adcValue;             

    digitalWrite(_ssPin, LOW); 
    SPI.transfer(0b01);  
    if(channel == 0)
        highByteA = SPI.transfer(0x60) & 0x0F; 
    else 
        highByteA = SPI.transfer(0xE0) & 0x0F; 
    
    lowByteA = SPI.transfer(0x00); 

    digitalWrite(_ssPin, HIGH); 

    adcValue = (highByteA << 8) | lowByteA;
    return adcValue; 
}

float SOAM0507_convertToVoltage(int adcValue) {
    return adcValue * _vdd / 4096; 
}
