/*
Write a program that reads integers from stdin until an error.  It then prints the integers entered (including duplicates) 
in increasing order. Use a vector and algorithm(s).
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> numbers;

  // TODO
  int num;
  while(cin >> num) {
    numbers.push_back(num);
  }
  
    bool swapped;
    for (size_t i = 0; i < numbers.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < numbers.size() - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    for(int i : numbers) {
        cout << i << " ";
    }
    cout << endl;
}