/*
Complete the implementation of allocate_array to allocate an int array of the given size using a unique_ptr and sort_array 
to sort a unique_ptr array of ints.
sort_array should take responsibility for array passed in, and pass responsibility back out.
Hint: use std::make_unique and std::sort.
*/

#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int[]> allocate_array(size_t sz) {
  /* TODO */
  return make_unique<int[]>(sz);

}

/* TODO */ unique_ptr<int[]> sort_array(/* TODO */ unique_ptr<int[]> arr, size_t sz) {
  /* TODO */
  sort(arr.get(), arr.get() + sz);
  return arr;
}

int main() {
  cout << "Enter an array size:" << endl;
  size_t arr_sz;
  if (!(cin >> arr_sz)) {
    return EXIT_FAILURE;
  }

  auto arr = allocate_array(arr_sz);
  for (size_t ii = 0; ii < arr_sz; ++ii) {
    cout << "Enter a number:" << endl;
    if (!(cin >> arr.get()[ii])) {
      return EXIT_FAILURE;
    }
  }

  arr = sort_array(std::move(arr), arr_sz);

  cout << "Sorted:";
  for (size_t ii = 0; ii < arr_sz; ++ii) {
    cout << " " << arr.get()[ii];
  }
  cout << endl;
}