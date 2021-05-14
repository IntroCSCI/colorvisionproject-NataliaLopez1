#include "color.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

color::color():hexColor{""}{}

void color::isHexColor(string hexString)
{
  counter = 0;
  for(int index = 1; index < hexString.size(); index++)
  {
    if((hexString[index] >= 'a' && hexString[index] <= 'f') ||
      (hexString[index] >= '0' && hexString[index] <= '9'))
    {
      counter = counter+=1;
    }
    else
    {
      break;
    }
  }
  if(counter==6)
  {
    hexColor = hexString.substr(0,7);
  }
  else if(counter==3)
  {
    hexColor = hexString.substr(0,4);
  }
}

string color::uniqueHex(const vector<string> & compareColors)
{
  for(int index = 0; index < compareColors.size(); index++)
  {
    if(compareColors[index] == hexColor)
    {
      return "";
    }   
  }
  return hexColor;
}

