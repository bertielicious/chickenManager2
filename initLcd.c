#include "config.h"
#include "clock.h"
void initLcd(void)
{
// step 1
__delay_ms(110); // power on, wait for 110ms
//step 2
RS = 0; 
D4 = 1;            
D5 = 1;
D6 = 0;
D7 = 0;
__delay_ms(5);
clock();
//step 3
RS = 0; // LCD is in command mode
D4 = 1;            
D5 = 1;
D6 = 0;
D7 = 0;
__delay_ms(1);
clock();
//step 4
RS = 0; // LCD is in command mode
D4 = 1;            
D5 = 1;
D6 = 0;
D7 = 0;  
__delay_ms(1);
clock();
//step 5
RS = 0; // LCD is in command mode
D4 = 0;            
D5 = 1;
D6 = 0;
D7 = 0;  
__delay_ms(1);
clock();
//step 6
RS = 0; // LCD is in 4 bit mode
D4 = 0;            
D5 = 1;
D6 = 0;
D7 = 0;  
__delay_ms(1);
clock();           // RS=0, D7 = 0, D6 = 0, D5 = 1, D4 = 0 - 4 bit mode (5a)
D4 = 0;
D5 = 0;
D6 = 1; // Font: F = 1 5x10 or F = 0 5x7
D7 = 1;  // Lines: N = 1 two lines or N = 0 one line display
__delay_ms(1);      // two nibble 4 bit functions set, send 0010 first then 1100
clock();           // (1100 = N F **) N = number of LCD lines (0 = 1, 1 = 2 lines)
                    // F = font size (0 = small, 1 = big)
//step 7
RS = 0; // display Off, cursor off, blink off
D4 = 0;  
D5 = 0;
D6 = 0;
D7 = 0;
__delay_ms(1);
clock();

D4 = 0;
D5 = 0;
D6 = 0;
D7 = 0;
__delay_ms(1);     
clock();
//step 8
RS = 0; // display clear
D4 = 0;
D5 = 0;
D6 = 0;
D7 = 0;
__delay_ms(1);
clock();

D4 = 1;
D5 = 0;
D6 = 0;
D7 = 0;
__delay_ms(5);      // display ON/ OFF control
clock();
//step 9
RS = 0;
D4 = 0;
D5 = 0;
D6 = 0;
D7 = 0;
__delay_ms(1);
clock();

D4 = 0;
D5 = 0;
D6 = 0;
D7 = 0;
__delay_ms(1);
clock();
//step 10 - end of initialisation
//step 11
D4 = 0;
D5 = 0;
D6 = 0;
D7 = 0;
__delay_ms(1);
clock();

D4 = 0;     // cursor blinking off  B
D5 = 0;     // cursor off           C
D6 = 1;     // display on           D
D7 = 1;
__delay_ms(1);      // display ON/ OFF control
clock();
    
}

