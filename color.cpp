#include "color.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

string color::isHexColor(string hexString)
{
 int counter = 0;
 for(int i = 1; i < hexString.size(); i++)
    {
      if((hexString[i] >= 'a' && hexString[i] <= 'f') ||
        (hexString[i] >= '0' && hexString[i] <= '9'))
      {
        counter = counter+=1;
      }
      else
      {
        break;
      }
    }
  if(counter>=6)
  {
    return hexString.substr(0,7);
  }
  else if(counter>=3)
  {
    return hexString.substr(0,4);
  }
  else
  {
    return "";
  }
}