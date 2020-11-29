#include <msp430.h>

#include "led.h"

#include "switches.h"



unsigned char red_on = 0, green_on = 0;

unsigned char led_changed = 0;



static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()

{
  P1DIR |= LEDS;// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}


/*Turns on red LED with button.*/
void led_update()

{ 
  if(switch_state_changed)
    {
    char ledFlags = redVal[red_on];

    
    ledFlags |= switch_state_down ? LED_RED : 0;     // When switch 1 is down turn on red.
    
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bit for off leds

    P1OUT |= ledFlags;     // set bit for on leds
    }
  switch_state_down = 0;
}
