/*
This is a test for the "Board" department that represents a bulletin board
Author : Shlomo Glick
*/


#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;



TEST_CASE("Ordinary cases") {
    ariel::Board board;

    board.post(400, 500, Direction::Horizontal, "abcd"); 
    board.post(401, 503, Direction::Vertical, "shlomo");
    board.post(403, 502, Direction::Horizontal, "shira");
    CHECK (board.read(399, 501, Direction::Vertical, 3) == "_b_");
    CHECK (board.read(398, 502, Direction::Vertical, 4) == "__c_");
    CHECK (board.read(404, 503, Direction::Vertical, 3) == "omo");
    board.post(405, 500, Direction::Horizontal, "12345");
    CHECK (board.read(404, 503, Direction::Vertical, 3) == "o4o");
    CHECK (board.read(387, 497, Direction::Horizontal, 6) == "______");
    CHECK (board.read(387, 497, Direction::Vertical, 6) == "______");
    board.post(399, 500, Direction::Horizontal, "ABCD");
    board.post(398, 500, Direction::Horizontal, "1234");
    CHECK (board.read(398, 500, Direction::Vertical, 5) == "1Aa__");
    CHECK (board.read(398, 501, Direction::Vertical, 5) == "2Bb__");
    CHECK (board.read(398, 502, Direction::Vertical, 5) == "3Cc__");
    CHECK (board.read(398, 503, Direction::Vertical, 5) == "4Ddsh");
    CHECK (board.read(398, 503, Direction::Vertical, 9) == "4Ddshho4o");
    CHECK (board.read(398, 506, Direction::Vertical, 6) == "_____a");
    CHECK (board.read(403, 502, Direction::Vertical, 3) == "s_3");
    CHECK (board.read(403, 504, Direction::Vertical, 3) == "i_5");
    CHECK (board.read(403, 503, Direction::Horizontal, 4) == "hira");
    board.post(398, 500, Direction::Horizontal, "tttt");
    CHECK (board.read(398, 500, Direction::Vertical, 5) == "tAa__");
    CHECK (board.read(398, 501, Direction::Vertical, 5) == "tBb__");
    CHECK (board.read(398, 502, Direction::Vertical, 5) == "tCc__");
    CHECK (board.read(398, 503, Direction::Vertical, 5) == "tDdsh");
    CHECK (board.read(398, 503, Direction::Vertical, 9) == "tDdshho4o");
    board.post(398, 500, Direction::Horizontal, "____");
    CHECK (board.read(398, 500, Direction::Vertical, 5) == "_Aa__");
    CHECK (board.read(398, 501, Direction::Vertical, 5) == "_Bb__");
    CHECK (board.read(398, 502, Direction::Vertical, 5) == "_Cc__");
    CHECK (board.read(398, 503, Direction::Vertical, 5) == "_Ddsh");
    CHECK (board.read(398, 503, Direction::Vertical, 9) == "_Ddshho4o");
    board.post(408, 500, Direction::Horizontal, "hello my name is bob");
    CHECK (board.read(408, 500, Direction::Horizontal, 20) == "hello my name is bob");
    CHECK (board.read(408, 503, Direction::Horizontal, 8) == "lo my na");
    CHECK (board.read(408, 505, Direction::Horizontal, 8) == " my name");
    CHECK (board.read(408, 515, Direction::Horizontal,13 ) == "s bob________");
    CHECK (board.read(398, 503, Direction::Vertical, 12) == "_Ddshho4o_l_");
    board.post(408, 503, Direction::Horizontal, "Successfully!!");
    CHECK (board.read(408, 500, Direction::Horizontal, 20) == "helSuccessfully!!bob");
    CHECK (board.read(408, 503, Direction::Horizontal, 8) == "Successf");
    CHECK (board.read(408, 505, Direction::Horizontal, 8) == "ccessful");
    CHECK (board.read(408, 515, Direction::Horizontal,13 ) == "!!bob________");
    CHECK (board.read(408, 512, Direction::Horizontal,13 ) == "lly!!bob_____");
    CHECK (board.read(398, 503, Direction::Vertical, 12) == "_Ddshho4o_S_");
  
}




TEST_CASE("Test for extreme cases") {
    ariel::Board board;
    board.post(10, 10, Direction::Horizontal, "this is my test"); 
    board.post(11, 10, Direction::Horizontal, "TEST");
    board.post(12, 10, Direction::Horizontal, "00000000");

    CHECK (board.read(10, 10, Direction::Vertical, 0) == "");
    CHECK (board.read(10, 10, Direction::Horizontal,0 ) == "");


    CHECK (board.read(13, 10, Direction::Vertical, 0) == "");
    CHECK (board.read(13, 10, Direction::Vertical, 1) == "_");
    CHECK (board.read(13, 10, Direction::Vertical, 2) == "__");
    CHECK (board.read(13, 10, Direction::Vertical, 3) == "___");
    CHECK (board.read(13, 10, Direction::Vertical, 10) == "__________");

    CHECK (board.read(13, 10, Direction::Horizontal,0 ) == "");
    CHECK (board.read(13, 10, Direction::Horizontal, 1) == "_");
    CHECK (board.read(13, 10, Direction::Horizontal, 2) == "__");
    CHECK (board.read(13, 10, Direction::Horizontal, 3) == "___");
    CHECK (board.read(13, 10, Direction::Horizontal, 10) == "__________");


    ariel::Board board_large;


    board_large.post(99999999, 99999999, Direction::Horizontal, "abcdefg"); 
    CHECK (board_large.read(99999999, 99999999, Direction::Vertical,5) == "a____");
    CHECK (board_large.read(99999999, 99999999, Direction::Horizontal,5) == "abcde");

    
    CHECK (board_large.read(99999999, 99999999, Direction::Vertical,30) == "a_____________________________");
    CHECK (board_large.read(99999999, 99999999, Direction::Horizontal,30) == "abcdefg_______________________");
    

    
    
    board.post(20, 20, Direction::Horizontal, "1234567890-="); 
    board.post(21, 20, Direction::Horizontal, "!@#$%^&*()_+");
    board.post(22, 20, Direction::Horizontal, "____________");
    board.post(23, 20, Direction::Horizontal, "][/.,`~");

    CHECK (board.read(20, 20, Direction::Horizontal,13) == "1234567890-=_");
    CHECK (board.read(21, 20, Direction::Horizontal,13) == "!@#$%^&*()_+_");
    CHECK (board.read(22, 20, Direction::Horizontal,13) == "_____________");
    CHECK (board.read(23, 20, Direction::Horizontal,13) == "][/.,`~______");

    CHECK (board.read(20, 20, Direction::Vertical,5) == "1!_]_");
    CHECK (board.read(20, 21, Direction::Vertical,5) == "2@_[_");
    CHECK (board.read(20, 22, Direction::Vertical,5) == "3#_/_");
    CHECK (board.read(20, 23, Direction::Vertical,5) == "4$_._");
    CHECK (board.read(20, 24, Direction::Vertical,5) == "5%_,_");
    CHECK (board.read(20, 25, Direction::Vertical,5) == "6^_`_");
    CHECK (board.read(20, 26, Direction::Vertical,5) == "7&_~_");
    CHECK (board.read(20, 27, Direction::Vertical,5) == "8*___");
    CHECK (board.read(20, 28, Direction::Vertical,5) == "9(___");
    CHECK (board.read(20, 29, Direction::Vertical,5) == "0)___");
    CHECK (board.read(20, 30, Direction::Vertical,5) == "-____");
    CHECK (board.read(20, 31, Direction::Vertical,5) == "=+___");
    CHECK (board.read(20, 32, Direction::Vertical,5) == "_____");

   }







TEST_CASE("Test for two boards in parallel") {

    ariel::Board board1;
    ariel::Board board2;


    board1.post(10, 10, Direction::Horizontal, "this is my test"); 
    board1.post(11, 10, Direction::Horizontal, "TEST");
    board1.post(12, 10, Direction::Horizontal, "00000000");
    board1.post(13, 10, Direction::Horizontal, "Systems Programming Course b");
    board1.post(14, 10, Direction::Horizontal, "cpp");


    CHECK (board1.read(13, 10, Direction::Horizontal, 1) == "S");
    CHECK (board2.read(13, 10, Direction::Horizontal, 1) == "_");

    CHECK (board1.read(13, 10, Direction::Horizontal, 2) == "Sy");
    CHECK (board2.read(13, 10, Direction::Horizontal, 2) == "__");

    CHECK (board1.read(13, 10, Direction::Horizontal, 3) == "Sys");
    CHECK (board2.read(13, 10, Direction::Horizontal, 3) == "___");

    CHECK (board1.read(13, 10, Direction::Horizontal, 4) == "Syst");
    CHECK (board2.read(13, 10, Direction::Horizontal, 4) == "____");

    CHECK (board1.read(13, 10, Direction::Horizontal, 5) == "Syste");
    CHECK (board2.read(13, 10, Direction::Horizontal, 5) == "_____");


    CHECK (board1.read(10, 10, Direction::Vertical, 1) == "t");
    CHECK (board2.read(10, 10, Direction::Vertical, 1) == "_");

    CHECK (board1.read(10, 10, Direction::Vertical, 2) == "tT");
    CHECK (board2.read(10, 10, Direction::Vertical, 2) == "__");

    CHECK (board1.read(10, 10, Direction::Vertical, 3) == "tT0");
    CHECK (board2.read(10, 10, Direction::Vertical, 3) == "___");

    CHECK (board1.read(10, 10, Direction::Vertical, 4) == "tT0S");
    CHECK (board2.read(10, 10, Direction::Vertical, 4) == "____");

    CHECK (board1.read(10, 10, Direction::Vertical, 5) == "tT0Sc");
    CHECK (board2.read(10, 10, Direction::Vertical, 5) == "_____");


    board2.post(10, 10, Direction::Horizontal, "My name is board2"); 
    board2.post(11, 10, Direction::Horizontal, "Ariel University");
    board2.post(12, 10, Direction::Horizontal, "hello");
    board2.post(13, 10, Direction::Horizontal, "Computer Science");
    board2.post(14, 10, Direction::Horizontal, "Good Day!!");


    CHECK (board1.read(13, 10, Direction::Horizontal, 1) == "S");
    CHECK (board2.read(13, 10, Direction::Horizontal, 1) == "C");

    CHECK (board1.read(13, 10, Direction::Horizontal, 2) == "Sy");
    CHECK (board2.read(13, 10, Direction::Horizontal, 2) == "Co");

    CHECK (board1.read(13, 10, Direction::Horizontal, 3) == "Sys");
    CHECK (board2.read(13, 10, Direction::Horizontal, 3) == "Com");

    CHECK (board1.read(13, 10, Direction::Horizontal, 4) == "Syst");
    CHECK (board2.read(13, 10, Direction::Horizontal, 4) == "Comp");

    CHECK (board1.read(13, 10, Direction::Horizontal, 5) == "Syste");
    CHECK (board2.read(13, 10, Direction::Horizontal, 5) == "Compu");



    CHECK (board1.read(10, 10, Direction::Vertical, 1) == "t");
    CHECK (board2.read(10, 10, Direction::Vertical, 1) == "M");

    CHECK (board1.read(10, 10, Direction::Vertical, 2) == "tT");
    CHECK (board2.read(10, 10, Direction::Vertical, 2) == "MA");

    CHECK (board1.read(10, 10, Direction::Vertical, 3) == "tT0");
    CHECK (board2.read(10, 10, Direction::Vertical, 3) == "MAh");

    CHECK (board1.read(10, 10, Direction::Vertical, 4) == "tT0S");
    CHECK (board2.read(10, 10, Direction::Vertical, 4) == "MAhC");

    CHECK (board1.read(10, 10, Direction::Vertical, 5) == "tT0Sc");
    CHECK (board2.read(10, 10, Direction::Vertical, 5) == "MAhCG");

}
