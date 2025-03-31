/*
Write a function template named compare that takes two arguments of any (potentially different) types and returns an int.  
The return value is <0 if the first argument is less than the second, >0 if the second argument is less than the first, and 0 
otherwise.

Optional challenge: Overload the function so that it works for two (const and non-const) C-strings.
(Hint: use strcmp, and check for a different return value to confirm.)
*/

#include <iostream>
#include <cstring>
using namespace std;

// TODO
template <typename T1, typename T2>
int compare(T1 a, T2 b) {
    if (a < b) return -1;
    if (b < a) return 1;
    return 0;
}

int compare(/* TODO */ const char* a, const char* b) {
  // TODO
  return strcmp(a, b);
}

int main() {
  cout << compare(1, 2) << endl; // <0
  cout << compare(1, 2.0) << endl; // <0
  cout << compare(1.0, 2.0) << endl; // <0
  cout << compare(2, 1) << endl; // >0
  cout << compare(2.0, 1) << endl; // >0
  cout << compare(2.0, 1.0) << endl; // >0

  // optional C-string comparison
  char stra[] = "aaa";
  char strc[] = "ccc";
  cout << compare("aaa", "ccc") << endl; // <0
  cout << compare("ccc", stra) << endl; // >0
  cout << compare(stra, "ccc") << endl; // <0
  cout << compare(strc, stra) << endl; // >0
}