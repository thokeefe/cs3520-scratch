/*
Complete the implementation of MyDynamicTestArray, using unique_ptr, so that it creates and destroys 3 Test objects in 
this program.
*/

#include <iostream>
#include <memory>
using namespace std;

struct Test {
  Test() { cout << "ctor" << endl; }
  ~Test() { cout << "dtor" << endl; }
};

class MyDynamicTestArray {
public:
  explicit MyDynamicTestArray(size_t size):
    /* TODO */
    arr(make_unique<Test[]>(size))
  {
  }
private:
  /* TODO */
  unique_ptr<Test[]> arr;
};

int main() {
  MyDynamicTestArray testArray(3);
}