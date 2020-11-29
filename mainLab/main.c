#include <msp430.h>

#include <libTimer.h>

#include "led.h"

#include "buzzer.h"

#include <lcdutils.h>

#include <lcddraw.h>

#include <p2switches.h>

#include "stateMachines.h"

#define LED_GREEN BIT6

void main()

{
  
  led_init();/* Initialize LED's*/
  switch_init();/*Initialize red board switch*/
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  lcd_init();/*Initialize LCD*/
  p2sw_init(15);/*Initialize green board switches*/
  buzzer_init(); /*Initializes the buzzer.*/

  enableWDTInterrupts();/* enable periodic interrupt */

  or_sr(0x8);/*GIE on*/

  u_char width = screenWidth, height = screenHeight;


  clearScreen(COLOR_BLACK);

  /*Draw an 11x16 string on LCD*/
  drawString11x16(5,5, "switches:", COLOR_GREEN, COLOR_BLACK);


  while (1)

    {
      
      u_int switches = p2sw_read(), i;

      char str[5];
      
      char *result = "0";

      for (i = 0; i < 4; i++)

	str[i] = (switches & (1<<i)) ? '0' : '1';

      str[4] = 0;
      /*Show resulting decimal from binary number.*/
      result = readBits(result, str);
      /*Draw the binary numbers.*/
      drawString5x7(10,30, str, COLOR_GREEN, COLOR_BLACK);
      /*Draw the decimal numbers.*/
      drawString5x7(40,30, result, COLOR_GREEN, COLOR_BLACK);
      
      P1OUT &= ~LED_GREEN;/*Turn off green LED*/
      or_sr(0x18);/*CPU off, GIE on*/
      P1OUT |= LED_GREEN;/*Turn on green LED*/
    }

}
