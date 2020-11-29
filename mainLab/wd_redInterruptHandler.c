#include <msp430.h>

#include "stateMachines.h"

#include "switches.h"



void redLEDInterrupt(){/* 250 interrupts/sec */

  static char blink_count = 0;

  if (++blink_count == 250) {

    switch_state_changed = toggle_red();

    led_update();

    blink_count = 0;

  }
  
}
