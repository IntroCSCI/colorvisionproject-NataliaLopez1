//Author: Natalia Lopez
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "color.h"
using namespace std;

void distinguishColors(vector<string> &);

int main()
{
  string fileName = "";
  ifstream reader;
  string line = "";
  int position;
  vector<string>hexValues;
  color hexColor;
 
  do
  {
    cout<<"Please enter the file to be opened:\n";
    cin>>fileName;
    reader.open(fileName, ios::in);
  }
  while(!reader.is_open());

  if( reader.is_open() )
  {
    while( !reader.eof() )
    { 
      getline(reader,line);
      position = line.find("#");

      while(position<line.size())
      {
        string hexString = line.substr(position);
        hexColor.isHexColor(hexString);
        
        if(hexColor.isUnique(hexValues) != "" )
        {
          hexValues.push_back(hexColor.isUnique(hexValues));
        }
        
        position=line.find("#",position+1);
      }   
    }  
  }
  reader.close();
  
  cout<<"There are "<<hexValues.size()<<" unique Hexadecimal colors in "<<fileName<<":"<<endl;
  
  for(int counter = 0; counter < hexValues.size(); counter++)
  {
    cout<<hexValues[counter]<<endl;
  }

  cout<<"The following Hexadecimal colors are difficult to distinguish from one another:"<<endl;
  
  distinguishColors(hexValues);

  return 0;
}

void distinguishColors(vector<string> & hexColors)
{
  string redHex;
  string greenHex;
  string blueHex;
  int red;
  int green;
  int blue;

  for(int index = 0; index < hexColors.size(); index++)
  {
    if(hexColors[index] == "#fff")
    {
      hexColors[index] = "#ffffff";
    }
    else if(hexColors[index] == "#000")
    {
      hexColors[index] = "#000000";
    }

    redHex = hexColors[index].substr(1,2);
    greenHex = hexColors[index].substr(3,2);
    blueHex = hexColors[index].substr(5,2);
    
    stringstream redValue;
    redValue << hex << redHex;
    redValue >> red;

    stringstream greenValue;
    greenValue << hex << greenHex;
    greenValue >> green;

    stringstream blueValue;
    blueValue << hex << blueHex;
    blueValue >> blue;

    if(red - green <= 90 && green - blue <= 90 && 
      hexColors[index] != "#ffffff")
    {
      cout<<hexColors[index]<<endl;
    }
  }
}



