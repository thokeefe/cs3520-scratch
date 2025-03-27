/*
From the given implementation of TestList, implement the insert_after function for adding elements to the linked list using smart pointers.  Your implementation should not call new or delete directly, and should automatically deallocate all the objects allocated.
*/

#include <iostream>
#include <memory>
using namespace std;

struct Test {
  Test(int idi): id(idi) { cout << "+ " << id << endl; }
  ~Test() { cout << "- " << id << endl; }
  const int id;
};

class TestList {
public:
  TestList(int id): m_item(id), m_next(nullptr) {}

  void print() const {
    cout << m_item.id;
    if (m_next) { cout << " "; m_next->print(); }
    else { cout << endl; }
  }

  // insert a new TestList node between
  // this node and the next node with the given id.
  // return a pointer to the newly allocated node.
  shared_ptr<TestList> insert_after(int id) {
    // TODO
    auto new_node = make_shared<TestList>(id);
    new_node->m_next = m_next;
    m_next = new_node;
    return new_node;
  }

private:
  Test m_item;
  shared_ptr<TestList> m_next;
};

int main() {
  auto head = make_shared<TestList>(1);
  auto node = head->insert_after(3);
  head->insert_after(2);
  node->insert_after(4);
  // has constructed 1 through 4
  head->print(); // prints "1 2 3 4"
  // will destruct 4 through 1
}