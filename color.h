#ifndef COLOR_H
#define COLOR_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class color
{
  private:
    int counter;
    string hexColor;

  public:
    color();
    void isHexColor(string);
    string isUnique(const vector<string> & );
};

#endif