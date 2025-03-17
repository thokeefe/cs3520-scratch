/*
Complete the implementation of MovableInt. A MovableInt holds a pointer to a dynamically allocated int that can be moved from 
object to object (but not copied!).  An empty MovableInt has a null pointer.
*/

#include <iostream>
using namespace std;

class MovableInt {
public:
  // allocate new movable int (dynamically allocate a single int and give it the value i)
  MovableInt(int i) : m_int(new int(i)) /* TODO */ {}

  // move construct
  MovableInt(MovableInt && o) {
    // TODO
    o.m_int = nullptr;
  }

  // deallocate movable int
  ~MovableInt() {
    // TODO
    delete m_int;
  }

  // move assign
  MovableInt &operator=(MovableInt && o) {
    // TODO
    if (this != &o) {
        delete m_int;
        m_int = o.m_int;
        o.m_int = nullptr;
    }
    return *this;
  }

  bool has_value() const { return m_int; }

  int get_value() const { return *m_int; }

private:
  MovableInt(const MovableInt &) = delete;
  MovableInt &operator=(const MovableInt &) = delete;

  int * m_int;
};

int main() {
  cout << boolalpha;

  MovableInt m1(1);
  cout << m1.has_value() << " " << m1.get_value() << endl; // true 1
  
  MovableInt m2(2);
  cout << m2.has_value() << " " << m2.get_value() << endl;// true 2

  MovableInt m3 = std::move(m1);
  cout << m1.has_value() << endl; // false
  cout << m3.has_value() << " " << m3.get_value() << endl; // true 1

  m3 = std::move(m2);
  cout << m2.has_value() << endl; // false
  cout << m3.has_value() << " " << m3.get_value() << endl; // true 2
}