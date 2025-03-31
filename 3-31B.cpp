/*
Write a struct template Point2D that has x and y member variables of any (same) type. Overload the + and << operators for 
Point2D.
*/

#include <iostream>
using namespace std;

// TODO
template <typename T>

struct Point2D {
  // TODO
  T x, y;
  Point2D operator+(const Point2D& other) const {
    return { x + other.x, y + other.y };
  }
};

// TODO
template <typename T>

Point2D<T> operator+(/* TODO */ const Point2D<T>& a, const Point2D<T>& b) {
  // TODO
  return { a.x + b.x, a.y + b.y };
}

// TODO
template <typename T>

ostream& operator<<(/* TODO */ ostream& os, const Point2D<T>& point) {
  // TODO
  os << "(" << point.x << ", " << point.y << ")";
  return os;
}

int main() {
  Point2D<double> a = { 1.1, 2.2 };
  Point2D<double> b = { 3.3, 4.4 };
  cout << a + b << endl;

  Point2D<int> c = { 1, 2 };
  Point2D<int> d = { 3, 4 };
  cout << c + d << endl;
}