#include "libraries.hpp"
#include "hash.hpp"
#include "test.hpp"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << "0. Write text" << endl;
        cout << "1. Transform 2 files with different symbols" << endl;
        cout << "2. Transform 2 files with only one symbol " << endl;
        cout << "3. Transform 2 same files, where only one symbol is different" << endl;
        cout << "4. Transform file with no symbols (empty file)" << endl;
        cout << "5. Benchmark the speed by transforming lines of konstitucija.txt" << endl;
        cout << "6. Benchmark the speed of this hash function compared to SHA-256, MD5, SHA-1" << endl;
        cout << "7. Ascertain that there are no collisions between 2 pairs of string" << endl;
        cout << "8. Find the difference in bits and hex levels" << endl;

        string input = "texts/konstitucija.txt";
        int selection;
        cin >> selection;
        cout << endl;

        switch (selection) {
        case 0:
            writeText();
            break;
        case 1:
            sameLineLengthTest();
            break;
        case 2:
            filesWithOneSymbol();
            break;
        case 3:
            filesWithSimilarSymbols();
            break;
        case 4:
            fileWithNoSymbols();
            break;
        case 5:
            hashingHash(input);
            break;
        case 6:
            hashingLines(input);
            break;
        case 7:
            collisionTest();
            break;
        case 8:
            cout << "still not ready" << endl;
            break;        
        default:
            cout << "Incorrect selection" << endl;
            exit(1);
        }
    }
    else if (argc == 2) {
        cout << "Hashing string: " << transformedText(argv[1]) << endl;
    }
    else 
        cout << "Too many arguments in command line" << endl;
    return 0;
}