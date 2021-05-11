#ifndef COLOR_H
#define COLOR_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class color
{
  private:
    string line;
    vector <string> hexColors;


  public:
    void isHexColor(string);
    bool isUnique(string, vector<string>);
};

#endif