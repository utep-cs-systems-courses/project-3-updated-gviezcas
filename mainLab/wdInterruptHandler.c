#include "stateMachines.h"

void



__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */



  static char count = 0;

  if (++blink_count == 125){



    pacManOpen();



    count = 0;



  }

}
