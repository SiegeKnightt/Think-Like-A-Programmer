#include <iostream>

using namespace std;

/*
A message has been encoded as a text stream that is to be read 
character by character. The stream contains a series of comma-
delimited integers, each a positive number capable of being
represent by a C++ int. However, the character represented by
a particular integer depends on the current decoding mode. There
are three modes: uppercase, lowercase, and punctuation.

1. Uppercase
In uppercase mode, each integer represents an upercase letter. The
integer % 27 indicates the letter of the alphabet (where 1 = A and
so on). So an input value of 143 in uppercase mode would yield the
letter H because 143 % 27 is 8 and H is the eighth letter in the 
alphabet.

2. Lowercase
The lowercase mode works the same but with lowercase letters; the
remainder of dividing the integer by 27 represents the lowercase
letter (1 = a and so on). So an input value of 65 in lowercase mode
would yield the letter b because 56 % 27 is 2 and b is the second
letter in the alphabet.

3. Punctuation
In punctuation mode, the integer is instead considered % 9, with
the interpretatiion being in Table 2-3 on page 42. So 19 would 
yield an exlamation point because 19 % 9 = 1.abort

At the beginning of each message, the decoding mode is uppercase
letters. Each time the modulo operation (by 27 or 9, depending
on the mode) results in 0, the decoding mode switches. If the current
mode is uppercase, the mode switches to lowercase letters. If the mode
is lowercase, the mode switches to punctuation, and if it is punctuation,
it switches back to uppercase.
*/
 
int main() {

    char input;
    char letter;
    int number;
    int letterNum;
    int mode = 1;

    cout << "Enter a text stream of comma-delimited integers: " << endl;

    do {

        input = cin.get();

        number = input - '0';

        input = cin.get();

        while (input != '\n' && input != ',') {
            
            number = number * 10 + (input - '0');
            input = cin.get();
        }

        //cout << "Number is: " << number << endl;

        // Uppercase
        if (mode == 1) {

            letterNum = number % 27;
            //cout << "Decoded number: " << letterNum << endl;

            letter = letterNum + 'A' - 1;

            if (letterNum == 0) {

                mode = 2;
            }
        }
        // Lowercase
        else if (mode == 2) {

            letterNum = number % 27;

           //cout << "Decoded number: " << letterNum << endl;

            letter = letterNum + 'a' - 1;

            if (letterNum == 0) {

                mode = 3;
            }
        }
        // Punctuation
        else if (mode == 3) {

            letterNum = number % 9;

            //cout << "Decoded number: " << letterNum << endl;

            if (letterNum == 1) {

                letter = '!';
            }
            else if (letterNum == 2) {

                letter = '?';
            }
            else if (letterNum == 3) {

                letter = ',';
            }
            else if (letterNum == 4) {

                letter = '.';
            }
            else if (letterNum == 5) {

                letter = ' ';
            }
            else if (letterNum == 6) {

                letter = ';';
            }
            else if (letterNum == 7) {

                letter = '"';
            }
            else if (letterNum == 8) {

                letter = '\'';
            }
            
            if (letterNum == 0) {

                mode = 1;
            }
        }

        if (letterNum != 0) {

            cout << letter;
        }

    } while (input != '\n');

    return 0;
}