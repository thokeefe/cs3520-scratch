/*
Create a Counter class, with a member function inc(), that keeps track of both how often inc has been called on an instance, 
but also ho wmany times it has been called on all instances.alignas
Hint: use static members.
*/
#include <iostream>
using namespace std;

class Counter {
public:
  Counter(): m_count(0) {}
  /* TODO */

  void inc() {
    m_count++;
    o_count++;
  }

  int get_this_count() { return m_count; }
  /* TODO */
  static int get_total_count() { return o_count; }
private:
  int m_count;
  /* TODO */
  static int o_count;
};

int Counter::o_count = 0;

int main() {
  Counter c1;
  Counter c2;
  c1.inc();
  c2.inc();
  c2.inc();
  cout << c1.get_this_count() << endl;  // `1`
  cout << Counter::get_total_count() << endl; // `3`
  cout << c2.get_this_count() << endl;  // `2`
  cout << Counter::get_total_count() << endl; // `3`
}