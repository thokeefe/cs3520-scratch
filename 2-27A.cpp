/*
Write a function countChars that takes a C-string and a character as arguments and returns the number of occurrences of the 
character in the C-string. Don’t use any functions from <cstring>.
*/

#include <iostream>
using namespace std;

int countChars(const char str[], char ch) {
  // TODO
  int count = 0;
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == ch) {
        count++;
    }
    i++;
  }
  return count;
}

int main() {
  cout << countChars("12341321", '1') << endl; // 3
  cout << countChars("12341321", '2') << endl; // 2
  cout << countChars("12341321", '4') << endl; // 1
}