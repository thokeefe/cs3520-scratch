/*
Write a function mean_average that takes a vector of doubles as an argument, and returns the mean average of the numbers in the 
vector. If the vector is empty, the function throws an invalid_argument exception.

Update the function read_and_average_numbers to handle an invalid_argument exception from mean_average and print an error 
message.
*/

#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>
using namespace std;

double mean_average(const vector<double> & v) {
  // TODO
  if (v.size() < 1) {
    throw invalid_argument("Empty vector");
  }
  double sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  return sum / v.size();
}

void read_and_average_numbers() {
  vector<double> v;
  double x;
  while (cin >> x) {
    v.push_back(x);
  }
  // TODO
  try {
    cout << mean_average(v) << endl;
  } catch (const invalid_argument & e) {
    cout << "Error: " << e.what() << endl;
  }
  // TODO
}

int main() {
  read_and_average_numbers();
}