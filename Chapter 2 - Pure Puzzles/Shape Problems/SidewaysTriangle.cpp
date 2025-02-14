#include <iostream>

using namespace std;

/*
Write a program that uses only two output statements,
cout << "#" and cout << "\n"
to produce a pattern of hash symbols shaped like
a sideways triangle.

Example Output:

#
##
###
####
###
##
#

*/

void sidewaysTriangle() {

    for (int row = 0; row < 8; row++) {

        for (int col = 0; col < 4 - abs(4 - row); col++) {

            cout << "#";
        }

        cout << "\n";
    }
}

int main() {

    sidewaysTriangle();

    return 0;
}