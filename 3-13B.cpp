/*
Write a program that prompts the user for a string length.  Then the program dynamically allocates a char buffer just big 
enough to hold a C-string of the given length (including space for the null character). It then prompts the user for a string, 
reads it into the buffer, converts it to uppercase, and displays the uppercase C-string. Then the buffer is deallocated.

Hint: You can use cin.getline(buffer, bufferlength) to read up to bufferlength chars (including the null char) into buffer.
*/

#include <iostream>
#include <limits>
using namespace std;

int main() {
  cout << "Enter a string length:" << endl;
  int len;
  if (!(cin >> len) || len <= 0) {
    cout << "Input error." << endl;
    return -1;
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Enter a string to uppercase:" << endl;

  // TODO
  char* str = new char[len + 1];
  cin.getline(str, len + 1);

  for (int i = 0; str[i] != '\0'; ++i) {
    str[i] = toupper(str[i]);
  }

  cout << str << endl;

  delete[] str;

  return 0;
}