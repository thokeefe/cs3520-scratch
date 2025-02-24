/*
Fill in the function copy_subarray.  It takes a source array and its size, and copies that array onto a destination array, 
starting at the given offset.
You can assume there is enough room in the destination array.

Optional: update the function to take the size of the destination array, and throw an exception if there isn't enough room.
*/

#include <iostream>
using namespace std;

void copy_subarray(int * dest, size_t dest_offset, const int * src, size_t src_size) {
  // TODO
}

int main() {
  const size_t size1 = 6;
  int arr1[size1] = { 1, 2, 3, 4, 5, 6 };

  const size_t size2 = 3;
  int arr2[size2] = { 7, 8, 9 };

  copy_subarray(arr1, 1, arr2, size2);
  for (int e: arr1) {
    cout << e << " ";
  }
  cout << endl; // `1 7 8 9 5 6 `
}