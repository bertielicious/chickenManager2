#include "config.h"
#include<stdbool.h>
//#include "clock.h"
void nibToBin(bool R, uchar byte)// command needs to indicate high or low byte selected
{
    
    RS = R;
    D7 = (byte & 0b10000000) >> 7;
    D6 = (byte & 0b01000000) >> 6;
    D5 = (byte & 0b00100000) >> 5;
    D4 = (byte & 0b00010000) >> 4;
   // clock();
    RS = R;
    D7 = (byte & 0b00001000) >> 3;
    D6 = (byte & 0b00000100) >> 2;
    D5 = (byte & 0b00000010) >> 1;
    D4 = (byte & 0b00000001) >> 0;
   // clock();   
}
