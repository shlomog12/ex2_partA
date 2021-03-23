
#include <vector>
#include <string>
#include <iostream>
#include "Direction.hpp"

using namespace std;

namespace ariel{


class Board {
  public:

   
    void post(unsigned int line,unsigned int col, ariel::Direction direction ,const string ad );
    string read(unsigned int line,unsigned int col, ariel::Direction direction ,unsigned int length);
    void show();



};

}