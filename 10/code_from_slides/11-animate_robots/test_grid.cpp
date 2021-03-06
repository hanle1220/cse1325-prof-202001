#include "grid.h"
#include <iostream>
#include <sstream>

/*
 Test Grid class

 @author      George F. Rice
 @copyright   Copyright 2017-2019
 @version     2.0

 This file is part of Roving Robots.

 Roving Robots is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Roving Robots is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
*/ 
 
int main() {
  int result = 0;      // Set to non-zero code if failed
  int test_vector = 1; // Bitmask for calculating codes

  {
  ///////////////////////////////////
  // Grid static initialization
  std::string expected = 
R"(.....X........................
.........X......X.............
..............................
.........X................X...
..............................
.....R........................
X.............................
..X...........X...............
...........X..................
...........................X..
..............................
..............................
................X............X
..X...........................
........X.....................
..............................
.............X........XX......
..............................
............X.................
....................X.........
.XX...........................
..............................
.X............................
..............................
..............................
.......X...............X...X..
..............................
.............................X
..............................
.....................X........
)";
  std::ostringstream actual;

  Robot r{"Marvin", Coordinate{5, 5}};
  actual << Grid{r};

  if (expected != actual.str()) {
    std::cerr << "FAIL: Grid static initialization" << std::endl;
    std::cerr << "  Expected: \"" << expected << '"' << std::endl;
    std::cerr << "  Actual:   \"" << actual.str() << '"' << std::endl << std::endl;
    result |= test_vector;  // Fail this test vector
  }
  test_vector <<= 1;
  }{
  ///////////////////////////////////
  // Grid random initialization
  std::string expected = 
R"(............X.................
..........................X...
.................X............
..............................
..............................
..........................X...
................X.............
..............................
......X.......................
..........X.....X.............
...............X..............
...X..........................
...........................X..
..............................
..............X...............
............X..R........X.....
..............................
.............X................
.......X..................X...
..............X...............
.X.X..........................
.................X............
...................X..........
..............................
........X.....................
..............................
......................X.......
..............X...............
..............X...............
....X..........X........X.....
)";
  std::ostringstream actual;

  Robot r;
  actual << Grid{r};

  if (expected != actual.str()) {
    std::cerr << "FAIL: Grid random initialization" << std::endl;
    std::cerr << "  Expected: \"" << expected << '"' << std::endl;
    std::cerr << "  Actual:   \"" << actual.str() << '"' << std::endl << std::endl;
    result |= test_vector;  // Fail this test vector
  }
  test_vector <<= 1;
  }
}
