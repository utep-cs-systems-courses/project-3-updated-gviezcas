#include <msp430.h>

#include <libTimer.h>

#include "led.h"

#include "buzzer.h"

#include <lcdutils.h>

#include <lcddraw.h>

#include <p2switches.h>

#include "stateMachines.h"



void main()

{

  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  lcd_init();
  p2sw_init(15);
  //switch_init(); //Initializes the switches.
  // led_init();    //Initializes the LEDs.
   buzzer_init(); //Initializes the buzzer.

  enableWDTInterrupts();/* enable periodic interrupt */

  or_sr(0x8);

  u_char width = screenWidth, height = screenHeight;


  clearScreen(COLOR_BLACK);

  
  drawString8x12(10,10, "switches:", COLOR_GREEN, COLOR_BLACK);


  while (1)

    {
      
      u_int switches = p2sw_read(), i;

      char str[5];
      
      char *result = "0";

      for (i = 0; i < 4; i++)

	str[i] = (switches & (1<<i)) ? '0' : '1';

      str[4] = 0;

      result = readBits(result, str);

      drawString5x7(10,20, str, COLOR_GREEN, COLOR_BLACK);

      drawString5x7(40,20, result, COLOR_GREEN, COLOR_BLACK);

    }

  or_sr(0x18);/* CPU off, GIE on */

}
