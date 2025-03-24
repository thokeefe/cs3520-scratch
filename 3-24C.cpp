/*
Write a program that prompts the user to input a year, and uses STL algorithms, a lambda, and the provided map to print 
the informal names of all the C++ standards that came out before that year.

Hint: use std::for_each.
*/

#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
  const map<int, string> standards = {
    { 1998, "C++98" },
    { 2003, "C++03" },
    { 2011, "C++11" },
    { 2014, "C++14" },
    { 2017, "C++17" },
    { 2020, "C++20" },
    { 2023, "C++23" },
  };

  // print prompt
  cout << "enter a year:" << endl;

  // get and check input
  int year = 0;
  if (!(cin >> year)) {
    return EXIT_SUCCESS;
  }

  // TODO
  for_each(standards.begin(), standards.end(), [year](const pair<int, string>& entry) {
    if (entry.first < year) {
        cout << entry.second << endl;
    }
  });
}