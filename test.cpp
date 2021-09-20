#include "libraries.hpp"
#include "test.hpp"
#include "hash.hpp"
void sameLineLengthTest() {
    string textDifferent1 = "texts/text1000Different1.txt";
    string textDifferent2 = "texts/text1000Different2.txt";

    cout << "1. Different Text: " << fileToHashCode(textDifferent1) << endl;
    cout << "2. Different Text: " << fileToHashCode(textDifferent2) << endl;
}

void filesWithOneSymbol() {
    string texta = "texts/texta.txt";
    string textb = "texts/textb.txt";

    cout << "texta:.txt " << fileToHashCode(texta) << endl;
    cout << "textb.txt: " << fileToHashCode(textb) << endl;
}

void filesWithSimilarSymbols() {
    string textSame1 = "texts/text1000Same1.txt";
    string textSame2 = "texts/text1000Same2.txt";

    cout << "text1000Same1.txt: " << fileToHashCode(textSame1) << endl;
    cout << "text1000Same2.txt: " << fileToHashCode(textSame2) << endl;
}

void fileWithNoSymbols() {
    string textEmpty = "texts/textEmpty.txt";

    cout << "textEmpty.txt: " << fileToHashCode(textEmpty) << endl;
}

void hashingLines(string &text) {
    stringstream my_buffer = getText(text);
    stringstream stringBuffer(my_buffer.str());

    string line;
    int numOfLines = 0;
    while (!stringBuffer.eof()) {
        getline(stringBuffer, line);
        numOfLines++;
        cout << transformedText(line) << endl;
    }
    
}
