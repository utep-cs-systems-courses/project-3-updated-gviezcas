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
  /*
  r = (screenHeight/2)-5;
  c = screenWidth/10;

  
  for(int offc = 0; offc < 18; offc++)
    {
      for(int offr = 0; offr <= offc-5; offr++)
	{
	  
	  drawPixel(c+offc, r-offr, COLOR_BLACK);
	  
	}
      
    }
  */
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
