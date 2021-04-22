//Author: Natalia Lopez
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool isUnique(string, vector<string> &);
void HextoDecimal(vector<string> hexColors);

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
            if(isUnique(line.substr(position,3), hexValues) == true){
            hexValues.push_back(line.substr(position, 3));
            break;
            } 
          }
          else
          {
            if(isUnique(line.substr(position, 6), hexValues)== true){
            hexValues.push_back(line.substr(position, 6));
            break;
            } 
          } 
        }  
       }
    }  
  }
  reader.close();
  
  cout<<"There are "<< hexValues.size() << " unique Hexadecimal colors in "<< fileName << ":"<<endl;
  
  for(int counter = 0; counter < hexValues.size(); counter++)
  {
    cout<< "#" <<hexValues[counter]<<endl;
  }

  HextoDecimal(hexValues);

  return 0;
}

bool isUnique(string hexColor, vector<string> & compareColors){
  for(int index = 0; index < compareColors.size(); index++){
    if(compareColors[index] == hexColor){
      return false;
    }   
  }
  return true;
}

void HextoDecimal(vector<string> hexColors){
  for(int index = 0; index < hexColors.size(); index++){
  
unsigned int x;   
stringstream my_ss;
my_ss << hex << hexColors[index];
my_ss >> x;
cout << static_cast<int>(x) <<endl;
  }
}


