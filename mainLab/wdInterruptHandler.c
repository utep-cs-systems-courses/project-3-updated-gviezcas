#include <msp430.h>

#include "stateMachines.h"

#include "switches.h"

#include "buzzer.h"

#include "led.h"



void __interrupt_vec(WDT_VECTOR) WDT()
{/* 250 interrupts/sec */

  static char count = 0;

  if (++count == 125){
    
    pacManOpen();
    //buzzer_set_period(2000);

    }
  if(++count == 250)
    {
      pacMan();
      //buzzer_set_period(1000);
    }

}
