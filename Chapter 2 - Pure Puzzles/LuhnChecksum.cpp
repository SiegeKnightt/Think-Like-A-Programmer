#include <iostream>

using namespace std;

/*
The Luhn formula is a widely used system for validating identification numbers.
Using the original number, double the value of every other digit. Then add the 
values of the individual digits together (if a doubled value now has two digits,
add the digits individually). The identification number is valid if the sum is 
divisible by 10.

Write a program that takes an identification number of arbitrary length and
determines whether the number is valid under the Luhn formula. The program must
process each character before reading the next one.

*Example on page 32*
*/

int doubleNum(int num) {

    int doubled = num * 2;
    int sum;

    if (doubled >= 10) {

        // Number must always be between 10 and 18
        // So we add 1 plus the remainder
        sum = 1 + (doubled % 10);
    }
    else {

        sum = doubled;
    }

    return sum;
}

bool checksumLuhn() {

    char number;
    int sumEven = 0;
    int sumOdd = 0;
    int sum = 0;
    int position = 1;

    cout << "Enter a number: " << endl;

    number = cin.get();

    // '\n' is the character after all other digits are processed
    while (number != '\n') {

        if (position % 2 == 0) { 
            
            // Subtract '0' to get integer value instead of character value
            sumOdd += doubleNum(number - '0');
            sumEven += number - '0';
        }
        else {
            
            sumOdd += number - '0';
            sumEven += doubleNum(number - '0');
        }

        cout << "Digit: " << number << endl;
        cout << "SumEven: " << sumEven << endl;
        cout << "SumOdd: " << sumOdd << endl;
        number = cin.get();

        position++;
    }

    cout << "Position: " << position << endl;

    // Two running sums account due to 
    // not knowing the length in the beginning
    if ((position - 1) % 2 == 0) {

        sum = sumEven;
    }
    else {

        sum = sumOdd;
    }

    cout << endl << "Checksum is: " << sum << endl;

    // Determine whether or not the checksum is valid
    return sum % 10 == 0 ? true : false;
}

int main() {

    if (checksumLuhn()) {

        cout << "Checksum is divisible by 10. VALID!" << endl;
    }
    else {

        cout << "Checksum is not divisible by 10. INVALID!" << endl;
    }

    return 0;
}