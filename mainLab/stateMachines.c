#include <msp430.h>

#include "stateMachines.h"

#include "led.h"

#include "switches.h"

#include "buzzer.h"

#include "lcdutils.h"

#include "lcddraw.h"

#include "shape.h"

char song;
int i;
extern char F();


/*Toggles the red LED on and off.*/
char toggle_red()/* always toggle! */

{

  static char state = 0;



  switch (state) {

  case 0:

    red_on = 1;

    state = 1;

    break;

  case 1:

    red_on = 0;

    state = 0;

    break;

  }

  return 1;/* always changes an led */

}

/*Advances the state to toggle the red LED.*/
void state_advance()
{

  char changed = 0;

  changed = toggle_red();



  switch_state_changed = changed;

  led_update();

}

/*Turns off the buzzer.*/
void state_off()
{

  if(switch_state_down)
  {

    buzzer_set_period(0);

  }

  switch_state_changed = 0;

}

/*Reads the bits being displayed on the screen and returns the binary representation.*/
char* readBits(char *bits, char str[])

{

  if(str[0] == '1' && str[1] == '1' && str[2] == '1' && str[3] == '1')

    {

      return bits = "15";

    }

  if(str[0] == '1' && str[1] == '1' && str[2] =='1')

    {

      return bits = "14";

    }

  else if(str[0] == '1' && str[1] == '1' && str[3] == '1')

    {

      return bits = "13";

    }

  else if(str[0] == '1' && str[2] == '1' && str[3] == '1')

    {

      return bits = "11";

    }

  else if(str[1] == '1' && str[2] == '1' && str[3] == '1')

    {

      return bits = "07";

    }

  else if(str[0] == '1' && str[1] == '1')

    {

      return bits = "12";

    }

  else if(str[0] == '1' && str[2] == '1')

    {

      return bits = "10";

    }

  else if(str[0] == '1' && str[3] == '1')

    {

      return bits = "09";

    }

  else if(str[1] == '1' && str[2] == '1')

    {

      return bits = "06";

    }

  else if(str[1] == '1' && str[3] == '1')

    {

      return bits = "05";

    }

  else if(str[2] == '1' && str[3] == '1')

    {

      return bits = "03";

    }

  else if(str[0] == '0' && str[1] == '0' && str[2] == '0' && str[3] == '0')
    
    {
      
      return bits = "00";
      
    }
  
  do
    {
    if(str[i] == '1')
      {
	bits = F();
	/*
	  switch(i)
	    {
	    case 0:
	      bits = "08";
	      break;
	    case 1:
	      bits = "04";
	      break;
	    case 2:
	      bits = "02";
	      break;
	    case 3:
	      bits = "01";
	      break;
	    }
	*/
      }
    i++;
    }while(i < 4);

  return bits;
	  
 }

/*Draws a yellow rectangle shape with a line representing a closed mouth.*/
void pacMan()

{

  fillRectangle(0, screenHeight/3, 30, 30, COLOR_YELLOW);

  int r = (screenHeight/2)-5;

  int c = screenWidth/10+5;



  for(int i = 0; i < 13; i++)

    {

      drawPixel(c, r, COLOR_BLACK);

      c++;

    }
}

/*Draws the open mouth for the pacman.*/
void pacManOpen()

{

  int r = (screenHeight/2)-5;

  int c = screenWidth/10;



  for(int offc = 0; offc < 18; offc++)

    {

      for(int offr = 0; offr <= offc-5; offr++)

	{

	  drawPixel(c+offc, r-offr, COLOR_BLACK);

	}

    }

}
