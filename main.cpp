#include "libraries.hpp"
#include "hash.hpp"
#include "test.hpp"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // cout << "0 - Enter text" << endl;
        // string input = "texts/konstitucija.txt";
        // int selection;
        // cin >> selection;

        // if (selection == 1) {
        //     //sameLineLengthTest();
        // }
    }
    string input = "texts/konstitucija.txt";
        int selection;
        cin >> selection;

        if (selection == 1) {
            //hashingLines(input);
            //sameLineLengthTest();
            fileGenerator();
        }
}