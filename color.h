#ifndef COLOR_H
#define COLOR_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class color
{
  private:
    string hexString;
    vector <string> hexColors;
    int position;


  public:
    string isHexColor(string);
    bool isUnique(string, vector<string>);
};

#endif