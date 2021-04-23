//Author: Natalia Lopez
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool isUnique(string, const vector<string> &);
void distinguishColors(vector<string> &);

int main()
{
  string fileName = "";
  ifstream reader;
  string line = "";
  size_t position;
 
  cout<<"Please enter the file to be opened:\n";
  cin>>fileName;

  reader.open(fileName, ios::in);
  vector<string>hexValues;

  if( reader.is_open() )
  {
    while( !reader.eof() )
    { 
      getline(reader,line);
      position = line.find("#");

       if( line[position] ) 
       {   
        for (int index = position += 1; index < line.size() && 
            (line[index] >= '0' && line[index] <= '9' || 
             line[index] >= 'a' && line[index] <= 'f'); index++ ) 
        {
          if (line[index+3] < '0' || line[index+3] > '9' && 
              line[index+3] < 'a' || line[index+3] > 'f')
          {
            if(isUnique(line.substr(position,3), hexValues) == true)
            {
              hexValues.push_back(line.substr(position, 3));
              break;
            } 
          }
          else
          {
            if(isUnique(line.substr(position, 6), hexValues)== true)
            {
              hexValues.push_back(line.substr(position, 6));
              break;
            } 
          } 
        }  
       }
    }  
  }
  reader.close();
  
  cout<<"There are "<<hexValues.size()<<" unique Hexadecimal colors in "<<fileName<<":"<<endl;
  
  for(int counter = 0; counter < hexValues.size(); counter++)
  {
    cout<<"#"<<hexValues[counter]<<endl;
  }

  cout<<"The following Hexadecimal colors are difficult to distinguish from one another:"<<endl;
  
  distinguishColors(hexValues);

  return 0;
}

bool isUnique(string hexColor, const vector<string> & compareColors)
{
  for(int index = 0; index < compareColors.size(); index++)
  {
    if(compareColors[index] == hexColor)
    {
      return false;
    }   
  }
  return true;
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
    if(hexColors[index] == "fff")
    {
      hexColors[index] = "ffffff";
    }
    else if(hexColors[index] == "000")
    {
      hexColors[index] = "000000";
    }

    redHex = hexColors[index].substr(0,2);
    greenHex = hexColors[index].substr(2,2);
    blueHex = hexColors[index].substr(4,2);
    
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
      hexColors[index] != "ffffff")
   {
     cout<<"#"<< hexColors[index]<<endl;
   }
  }
}


