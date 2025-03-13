/*
Write a program that dynamically allocates and deallocates Test objects to produce the given output.
*/

#include <iostream>
using namespace std;

class Test {
public:
  Test(int id): m_id(id) {
    cout << "+ " << m_id << endl;
  }
  ~Test() {
    cout << "- " << m_id << endl;
  }
private:
  const int m_id;
};

int main() {
  // TODO
  Test* t1 = new Test(1); // + 1
  Test* t2 = new Test(2); // + 2
  delete t1;              // - 1
  Test* t3 = new Test(3); // + 3
  delete t2;              // - 2
  delete t3;              // - 3
  
  return 0;
}