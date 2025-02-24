/*
Write a function array_equal that takes two built-in int arrays and their sizes as arguments (so 4 arguments total), and 
returns true if the contents of the arrays are equal, false otherwise. The contents are equal if the arrays are the same size 
and have the same elements in the same order.
*/

#include <iostream>
using namespace std;

bool array_equal(const int arr1[], int size1, const int arr2[], int size2 /* TODO */) {
  // TODO
  if (size1 != size2) {
    return false;
  }
  for (int i = 0; i < size1; i++) {
    if (arr1[i] != arr2[i]) {
        return false;
    }
  }
  return true;
}

int main() {
  const size_t sizea = 5;
  const int arra[sizea] = { 1, 2, 3, 4, 5 };

  const size_t sizeb = 5;
  const int arrb[sizeb] = { 1, 2, 3, 4, 5 };

  const size_t sizec = 5;
  const int arrc[sizec] = { 2, 3, 4, 5, 6 };

  const size_t sized = 4;
  const int arrd[sized] = { 1, 2, 3, 4 };

  cout << array_equal(arra, sizea, arrb, sizeb) << endl; // 1
  cout << array_equal(arra, sizea, arrc, sizec) << endl; // 0
  cout << array_equal(arra, sizea, arrd, sized) << endl; // 0
}