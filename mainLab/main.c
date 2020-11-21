#include <libTimer.h>

#include <lcdutils.h>

#include <lcddraw.h>

#include <p2switches.h>

#include "stateMachines.h"





/** Initializes everything, clears the screen, draws "hello" and the circle */

void main()

{

  configureClocks();

  lcd_init();

  p2sw_init(15);

  or_sr(0x8);/* GIE (enable interrupts) */

  u_char width = screenWidth, height = screenHeight;



  clearScreen(COLOR_BLUE);



  drawString5x7(10,10, "switches:", COLOR_GREEN, COLOR_BLUE);

  pacMan();

  while (1)
    {

    u_int switches = p2sw_read(), i;

    char str[5];

    char *result = "0";

    for (i = 0; i < 4; i++)

      str[i] = (switches & (1<<i)) ? '0' : '1';
      
    str[4] = 0;

    result = readBits(result, str);
    
    drawString5x7(10,20, str, COLOR_GREEN, COLOR_BLUE);
    drawString5x7(40,20, result, COLOR_GREEN, COLOR_BLUE);
    
  }

}
