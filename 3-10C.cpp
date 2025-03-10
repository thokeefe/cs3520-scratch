/*
Write a function named shiftforward that, given a pointer range of integers, creates an updated range with values in the same 
order, but without any toremove values.
It does this by shifting the non-toremove values forward in the range, and returns a pointer to the new end (one past the last 
value) of the range.
You can assume the pointer arguments are not null.
*/

#include <iostream>
#include <vector>
using namespace std;

int *shiftforward(int *begin, int *end, int toremove) {
 // TODO
    int *write_ptr = begin;
    for (int *read_ptr = begin; read_ptr < end; ++read_ptr) {
        if (*read_ptr != toremove) {
            *write_ptr = *read_ptr;
            ++write_ptr;
        }
    }
    return write_ptr;
}

void run(vector<int> vec, int toremove);

int main() {
  run({1, 0, 2, 0, 3, 0, 4}, 0); // `values: 1 2 3 4`
  run({8, 1, 8, 2, 8, 3, 8}, 8); // `values: 1 2 3`
  run({1, 2}, 5);                // `values: 1 2`
  run({1, 1, 1}, 1);             // `values: `
}

void run(vector<int> vec, int toremove) {
  int *begin = &(vec[0]);
  int *end = shiftforward(begin, begin + vec.size(), toremove);
  cout << "values:";
  for (; begin != end; ++begin) {
    cout << " " << *begin;
  }
  cout << endl;
}