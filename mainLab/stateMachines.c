#include <msp430.h>

#include "stateMachines.h"

#include "led.h"

#include "switches.h"

#include "buzzer.h"

#include "lcdutils.h"

#include "lcddraw.h"

#include "shape.h"


char dim = 0, switch2_state_changed, switch4_state_changed, song;

extern char blink_dim;

/*Toggles between the Red and Green LEDs*/
char toggle()

{

  static char state = 0;


  switch(state) {
  case 0:

    red_on ^= 1;

    green_on ^= 0;

    state = 1;
    
    break;
    
  case 1:

    red_on ^= 0;

    green_on ^= 1;

    state = 0;

    break;

  }

  return state;/* always changes an led */

}

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

/*Advances the state to toggle the LEDs from red to green.*/
void state_advance()
{

  char changed = 0;

  changed = toggle();



  led_changed = changed;

  led_update();

}

/*Toggles between different buzzer pitches and both LEDs to create a siren.*/
void state_siren()
{

  switch(song)
  {

  case 0:
    
    buzzer_set_period(1000);

    switch1_state_down = 0;//LEDs rely on switch1, so need to change the state without pressing.

    state_advance();

    song++;

    break;

  case 1:
    
    buzzer_set_period(700);

    switch1_state_down = 1;

    state_advance();

    song = 0;

    break;
    

  }

}

/*Turns off the buzzer, siren and sets the brightness of the red LED back to default.*/
void state_off()
{

  if(switch4_state_down)
  {

    buzzer_set_period(0);
    switch2_state_changed = 0;

  }

  switch4_state_changed = 0;

}

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

  else if(str[0] == '1')

    {

      return bits = "08";

    }

  else if(str[1] == '1')

    {

      return bits = "04";

    }

  else if(str[2] == '1')

    {

      return bits = "02";

    }

  else if(str[3] == '1')

    {

      return bits = "01";

    }

  else

    {

      return bits = "00";

    }

}

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
