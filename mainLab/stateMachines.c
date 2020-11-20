#include "lcdutils.h"
#include "lcddraw.h"
#include "abCircle.h"
#include "shape.h"

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
      fillRectangle(20, 40, 30, 30, COLOR_RED);
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
/*
void pacMan()
{
  AbCircle circle14;
  
  Layer layer0 = {
    (AbShape *)&circle14,
    {(screenWidth/2)+10, (screenHeight/2)+5},
    {0,0}, {0,0}, COLOR_ORANGE, };

  layerDraw(&layer0);
}
*/
