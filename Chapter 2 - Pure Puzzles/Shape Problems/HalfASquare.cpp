#include <iostream>

using namespace std;

/*
Write a program that uses only two output statements,
cout << "#" and cout << "\n"
to produce a pattern of hash symbols shaped like half
of a perfect 5 x 5 square (or a right triangle).

Example Output:

#####
####
###
##
#

*/

void halfSquare() {

    for (int row = 0; row < 5; row++) {

        for (int col = 0; col < 5 - row; col++) {

            cout << "#";
        }

        cout << "\n";
    }
}

int main() {

    halfSquare();

    return 0;
}