#include "config.h"
void configPorts(void)
{
    //********TURN OFF ANALOGUE INPUTS**********************
    ANSELA = 0x00;                  // turn off all ADC inputs on PORTA
    ANSELB = 0x00;                  // turn off all ADC inputs on PORTB
    ANSELC = 0x00;                  // turn off all ADC inputs on PORTC
    CM1CON0 = 0x00;                 // all COMPARATORS off
    CM2CON0 = 0x00;
    CM1CON1 = 0x00;
    CM2CON1 = 0x00;
   TRISCbits.TRISC5 = LOW;      // RED_LED output RC5 pin 5 
   
   TRISCbits.TRISC4 = LOW;      // RS pin 6
   TRISCbits.TRISC3 = LOW;      // EN pin 7
   TRISCbits.TRISC6 = LOW;      // D4 pin 8
   TRISCbits.TRISC7 = LOW;      // D5 pin 9
   TRISAbits.TRISA5 = LOW;      // D6 pin 2
   TRISBbits.TRISB5 = LOW;      // D7 pin 12
   TRISBbits.TRISB6 = LOW;      // SCL i2C pin 11
   TRISBbits.TRISB4 = LOW;      // SDA i2c pin 13
}
