
/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 07 November 2019, 20:16
 */
/* Software Construction 27/10/19
 1. Problem definition
 * Control of a motorised door to the chicken coup where the door can be:
 a)  Open if the light level is daylight or the clock timer has been 
 * triggered to open the door, or if the manual open button has been pressed.
 b) Closed if the light level is night level or the clock timer has been 
 * triggered to close the door or the manual close button has been 
 * pressed
 2. Display on LCD the date, time, door open time, door close time, timer ON/OFF
 * light sensor ON/ OFF, manual OPEN/ CLOSE ON/ OFF and battery charge level on 
 * an LCD with three button keypad to control all of above. Confirm key presses
 *  via buzzer.
 3. Via blu-tooth connection, transmit all LCD display info to phone app, and 
 * also allow control of all door functions from the app.
 4. Microcontroller to be in sleep mode except when:
 * a) door needs to move from closed to open or open to closed due to timer or 
 * light sensor inputs or manual close/ open button.
 * b) someone presses a keypad button (time out back to sleep mode after 
 * 2 minutes without button activity)
 * 
 2. Sub systems
 * a) LCD
 * b) uC sleep
 * c) blu tooth
 * d) door
 * e) timer/ clock
 * f) light sensor
 * g) keypad
 * h) solar psu
 * i) motor
 * 
 3. Structs
 * a) LCD
 *  date(day, month, year)
 *  time (hour, minutes, seconds)
 *  door (open time, close time)
 *  timer(on, off)
 *  set time(door open time, door close time)
 *  light sensor (on, off)
 *  light sensor (adjust up time, adjust down time)
 *  manual door button (open, close)
 *  battery charge level display (o% - 100%)
 *  keypad with three buttons (up, down, enter)
 *  confirm key press with buzzer (key pressed, key not pressed)
 * 
 * b) uC sleep
 * if (button pressed or door needs to open or close (light sensor or timer))
 *    wake up
 *    else
 *    sleep
 * 
 * c) blu-tooth
 *    transmit
 *    receive
 * 
 * d) door
 *    open 
 *    close
 *    open or close door
 * 
 * e) clock/ timer
 *      check open
 *      check close
 *      open or close door
 * 
 * f) light sensor
 *      check light
 *      check dark
 *      open or close door
 * 
 * g) keypad
 *    check button press
 *       which button pressed
 *       take action or open / close door
 *  
 * 
 * h) solar psu
 *      display battery charge level
 * 
 * i) motor
 *    motor moves clockwise = open door
 *    motor moves anti-clockwise = close door
 * 
 * 
 *                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
 *    motor CW   2 |RA5   RA0| 19
 *    motor ACW  3 |RA4   RA1| 18
 *    MCLR/ RST  4 |RA3      | 17  MOTOR DIRECTION
 *    GREEN LED  5 |RC5   RC0| 16  LIGHT SENSOR (analog)
 *    RS         6 |RC4   RC1| 15  RTC INPUT
 *    EN         7 |RC3   RC2| 14  TOP LIMIT SWITCH
 *    LCD D4     8 |RC6   RB4| 13  BOTTOM LIMIT SWITCH
 *    LCD D5     9 |RC7   RB5| 12  LCD D7
 *    TX        10 |RB7   RB6| 11  LCD D6
 *                  ---------
 
 */
 

#include <xc.h>
#include "config.h"
#include "configOsc.h"
#include "configPorts.h"

#include "putch.h"
#include "set_usart.h"

#include <stdio.h>
//#include "clock.h"
#include "initLcd.h"

     
    
void main(void) 
{
    configOsc();
    configPorts();
    set_usart();
    initLcd();
    printf("4 bit LCD\n");
    RS = 1;
    D4 = 0;
    D5 = 0;
    D6 = 1;
    D7 = 0;
  //  clock();
    D4 = 1;
    D5 = 0;
    D6 = 0;
    D7 = 0;
 //   clock();
    

    
    
    
  while(1)
  {
      RC5 = 1;
      __delay_ms(100);
       RC5 = 0;
      __delay_ms(100);
    
  }
}