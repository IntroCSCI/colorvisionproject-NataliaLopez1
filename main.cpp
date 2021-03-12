//Author: Natalia Lopez
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string fileName = "";
  ifstream reader;
  string line = "";
  size_t position;
 
  cout<<"Please enter the file to be opened:\n";
  getline(cin, fileName);

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
        for (int index = position += 1; index < line.size() && (line[index] >= '0' && line[index] <= '9' || line[index] >= 'a' && line[index] <= 'f') ; index++ ) 
        {
          if (line[index+3] < '0' || line[index+3] > '9' && line[index+3] < 'a' || line[index+3] > 'f')
          {
            hexValues.push_back(line.substr(position, 3));
            break; 
          }
          else
          {
            hexValues.push_back(line.substr(position, 6));
            break; 
          } 
        }  
       }
    }  
  }
  reader.close();
  
  cout<<"Hexadecimal color values:"<<endl;
  
  for(int counter = 0; counter < hexValues.size(); counter++)
  {
    cout<< "#" <<hexValues[counter]<<endl;
  }

  return 0;
}
