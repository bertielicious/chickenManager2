#include "config.h"
void clock(void)
{
    EN = HIGH;
    __delay_ms(1);
    EN = LOW;
}
