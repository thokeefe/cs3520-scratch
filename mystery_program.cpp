
/*
Use callgrind to determine whether the program spends more instructions (inclusive) in mystery1 or mystery2.  Include relevant callgrind output in your answer.

You can paste the code into scratch.cpp from the demo to run in VS Code.
*/

/* ANSWER:
*/

#include <iostream>
using namespace std;

void mystery1() {
    int x = 0;
    int y = 0;
    for (int ii = 0; ii < 1000000; ++ ii) {
        x = ((x + 1) * 7) % 97;
        for (int jj = 0; jj < x; ++ jj) {
            y = ((y + 1) * 5) % 97;
        }
    }
    cout << x << " " << y << endl;
}

void mystery2() {
    int x = 0;
    int y = 0;
    for (int ii = 0; ii < 100000; ++ ii) {
        x = ((x + 1) * 7) % 5011;
        for (int jj = 0; jj < x; ++ jj) {
            y = ((y + 1) * 5) % 97;
        }
    }
    cout << x << " " << y << endl;
}

int main() {
    mystery1();
    mystery2();
}
