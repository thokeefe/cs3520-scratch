/*
Write a scoped enumeration for the four cardinal directions (North, South, East, West).

Write a function that that will print out a direction.

Hint: enum class ... { ... };

Optional challenge: write a function takes a direction as an argument and returns the opposite direction; print out the opposite of a few directions.
*/

#include <iostream>
using namespace std;

// TODO
enum class Direction {
    north,
    south,
    east,
    west
};

void write(Direction d) {
    switch(d) {
        case Direction::north: cout << "north" << endl; break;
        case Direction::south: cout << "south" << endl; break;
        case Direction::east: cout << "east" << endl; break;
        case Direction::west: cout << "west" << endl; break;
    }
}

int main() {
  Direction d = Direction::north;
  write(d); // `north`
  d = Direction::south;
  write(d); // `south`
  d = Direction::east;
  write(d); // `east`
  d = Direction::west;
  write(d); // `west`
}