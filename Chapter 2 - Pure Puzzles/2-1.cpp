#include <iostream>

using namespace std;

/*
Write a program that uses only three output statements,
cout << "#", cout << " ", and cout << "\n"
to produce a pattern of hash symbols shaped 
as shown below.

Example Output:

########
 ######
  ####
   ##

*/

void triangle() {

    for (int row = 0; row < 4; row++) {

        for (int col = 0; col < 4 - abs(4 - row); col++) {

            cout << " ";
        }

        for (int col = 0; col < 8 - row * 2; col++) {

            cout << "#";
        }

        cout << "\n";
    }
}

int main() {

    triangle();

    return 0;
}