#include <msp430.h>

#include "stateMachines.h"

#include "switches.h"

#include "buzzer.h"

#include "led.h"

short redrawScreen = 1;


/*Interrupt handler for square pacman animation.*/
void wdt_c_handler()
{/* 250 interrupts/sec */

  static char count = 0;
  
  if (++count == 125)
    {
      pacManOpen();/*Opens mouth after half a second.*/
      if(switch_state_changed)/*Turns off buzzer of switch state changes.*/
	{
	  buzzer_set_period(2000);/*Sets buzzer.*/
	}

    }
  if(++count == 250)
    {
      pacMan();/*Closes mouth after one second.*/
      if(switch_state_changed)
	{
	  buzzer_set_period(1000);/*Sets buzzer.*/
	}
      redrawScreen = 1;
    }
}
