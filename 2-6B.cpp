/*
Write a struct named Point2D that represents a two-dimensional integer point.

Write a (non-member) function that will add two of these points (passed by const reference), returning the result.

Hint: struct ... { ... };
*/

#include <iostream>
using namespace std;

// TODO
struct Point2D {
    int x, y;
};

Point2D addPoints(const Point2D & a, const Point2D & b) {
    return { a.x + b.x, a.y + b.y };
}

int main() {
  Point2D a = { 1, 2 };
  Point2D b = { 3, 4 };
  Point2D c = addPoints(a, b);
  cout << c.x << " " << c.y << endl; // 4 6
}