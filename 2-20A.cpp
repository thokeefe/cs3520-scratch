/*
Write a function element_of that takes a vector of strings and a string to search for as arguments. The function returns the 
index of that string in the vector, if it is there, otherwise it throws an runtime_error exception. (Don’t worry about catching 
the exception for this exercise.)
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

size_t index_of(const vector<string> & v, const string & s) {
  // TODO
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == s) {
      return i;
    }
  }
  throw runtime_error("String not found");
}

int main() {
  vector<string> vec = { "a", "b", "c", "d", "e", "f" };

  cout << index_of(vec, "a") << endl; // 0
  cout << index_of(vec, "d") << endl; // 3
  cout << index_of(vec, "g") << endl; // exception!
}