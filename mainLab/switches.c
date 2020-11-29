#include <msp430.h>

#include "switches.h"

#include "led.h"

#include "stateMachines.h"



char switch_state_down, switch_state_changed; /* effectively boolean */



static char

switch_update_interrupt_sense()

{

  char p1val = P1IN;

  /* update switch interrupt to detect changes from current buttons */

  P1IES |= (p1val & SWITCHES);/* if switch up, sense down */

  P1IES &= (p1val | ~SWITCHES);/* if switch down, sense up */

  return p1val;

}



void

switch_init()/* setup switch */

{

  P1REN |= SWITCHES;/* enables resistors for switches */

  P1IE |= SWITCHES;/* enable interrupts from switches */

  P1OUT |= SWITCHES;/* pull-ups for switches */

  P1DIR &= ~SWITCHES;/* set switches' bits for input */

  switch_update_interrupt_sense();

  led_update();

}


/*Interrupt handler for the switch on the red board.*/
void

switch_interrupt_handler()

{
  char state = 0;

  char p1val = switch_update_interrupt_sense();

  switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when switch on red board is up */

  switch_state_changed = 1;

  state_off();

}
