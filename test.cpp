#include "libraries.hpp"
#include "test.hpp"
#include "hash.hpp"
#include "sha1.hpp"
#include "md5.hpp"
#include "sha256.hpp"
#include "RNG.hpp"

void writeText() {
    string text;

    cout << "Now enter your text: " << endl;
    cin >> text;
    cout << "Your transformed text: ";
    cout << transformedText(text) << endl;
}

void sameLineLengthTest() {
    string textDifferent1 = "texts/text1000Different1.txt";
    string textDifferent2 = "texts/text1000Different2.txt";

    cout << "Different Text: " << fileToHashCode(textDifferent1) << endl;
    cout << "Different Text: " << fileToHashCode(textDifferent2) << endl;
}

void filesWithOneSymbol() {
    string texta = "texts/texta.txt";
    string textb = "texts/textb.txt";

    cout << "texta.txt: " << fileToHashCode(texta) << endl;
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

void hashingHash(string &text) {
    stringstream my_buffer = getText(text);
    stringstream stringBuffer(my_buffer.str());

    int fullTime;
    string line;
    int numOfLines = 0;
    int time = 0;

    while (!stringBuffer.eof()) {
        getline(stringBuffer, line);
        numOfLines++;

        auto start = std::chrono::high_resolution_clock::now();
        transformedText(line);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        time += elapsed.count();
    }
    cout << "Transformation for this hash took: " << time << " micro s\n";
}

void hashingLines(string &text) {
    int fullTime;
    int numOfLines = 0;
    int time[4] = {0, 0, 0, 0};
    int transformations = 7000;

    string line = getTextAsString(text);

    for (int i = 0; i < transformations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        transformedText(line);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        time[0] += elapsed.count();

        auto start1 = std::chrono::high_resolution_clock::now();
        md5(line);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto elapsed1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
        time[1] += elapsed1.count();

        auto start2 = std::chrono::high_resolution_clock::now();
        sha1(line);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
        time[2] += elapsed2.count();

        auto start3 = std::chrono::high_resolution_clock::now();
        sha256(line);
        auto end3 = std::chrono::high_resolution_clock::now();
        auto elapsed3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);
        time[3] += elapsed3.count();
        
        line.clear();
    }
    cout << "Transformation for this hash took: "<< time[0] << " micro s\n";
    cout << "Transformation for MD5 hash took: "<< time[1] << " micro s\n";
    cout << "Transformation for SHA-1 hash took: "<< time[2] << " micro s\n";
    cout << "Transformation for SHA-256 hash took: "<< time[3] << " micro s\n";
}

RandInt rnd{0, 53};
void collisionTest() {
    ofstream fileOut ("hashedPairs.txt");
    char symbols[] = "qwertyuiopasdfghjkklzxcvbnm,.1234567890+-_!@#$%^&***()";
    int numLines = 100000;
    int numberOfTypes = 4;
    int boxSize = numLines / numberOfTypes;
    int lineIndex = 0;
    int pairSizes[4] = {10, 100, 500, 1000};

    string file;

    for (int i = 0; i < boxSize; i++) {
        string firstPair;
        string secondPair;
        for (int j = 0; j < pairSizes[0]; j++) {
            firstPair += symbols[rnd()];
            secondPair += symbols[rnd()];
        }
        string string1 = transformedText(firstPair);
        string string2 = transformedText(secondPair);
        if (string1 == string2) {
            cout << "Collision was found in lines: " << firstPair << " and " << secondPair << endl;
            cout << "Hash code is: " << string1 << " and " << string2 << endl;
            lineIndex ++;
            break;
        }
        string1.clear();
        string2.clear();
    }

    for (int i = 0; i < boxSize; i++) {
        string firstPair;
        string secondPair;
        for (int j = 0; j < pairSizes[1]; j++) {
            firstPair += symbols[rnd()];
            secondPair += symbols[rnd()];
        }
        string string1 = transformedText(firstPair);
        string string2 = transformedText(secondPair);
        if (string1 == string2) {
            cout << "Collision was found in lines: " << firstPair << " and " << secondPair << endl;
            cout << "Hash code is: " << string1 << " and " << string2 << endl;
            lineIndex++;
            break;
        }
        fileOut << string1 << "  " << string2 << endl;
        string1.clear();
        string2.clear();
    }

    for (int i = 0; i < boxSize; i++) {
        string firstPair;
        string secondPair;
        for (int j = 0; j < pairSizes[2]; j++) {
            firstPair += symbols[rnd()];
            secondPair += symbols[rnd()];
        }
        string string1 = transformedText(firstPair);
        string string2 = transformedText(secondPair);
        if (string1 == string2) {
            cout << "Collision was found in lines: " << firstPair << " and " << secondPair << endl;
            cout << "Hash code is: " << string1 << " and " << string2 << endl;
            lineIndex++;
            break;
        }
        string1.clear();
        string2.clear();
    }

    for (int i = 0; i < boxSize; i++) {
        string firstPair;
        string secondPair;
        for (int j = 0; j < pairSizes[3]; j++) {
            firstPair += symbols[rnd()];
            secondPair += symbols[rnd()];
        }
        string string1 = transformedText(firstPair);
        string string2 = transformedText(secondPair);
        if (string1 == string2) {
            cout << "Collision was found in lines: " << firstPair << " and " << secondPair << endl;
            cout << "Hash code is: " << string1 << " and " << string2 << endl;
            lineIndex++;
            break;
        }
        string1.clear();
        string2.clear();
    }
    if (lineIndex == 0)
        cout << "No collisions were found" << endl;
}

void differenceTest() {
    char symbols[] = "qwertyuiopasdfghjkklzxcvbnm,.1234567890+-_!@#$%^&***()";

    int hashSize = 64;
    int numOfPairs = 100000;
    int numOfSymbols = 500-1;

    for (int i = 0; i < numOfPairs; i++) {
        string bitFirstPair;
        string bitSecongPair;
        string hexFirstPair;
        string hexSecondPair;

        for (int j = 0; j < numOfSymbols; j++) {
            bitFirstPair += symbols[rnd()];
        }

        bitSecongPair = 'b' + bitFirstPair;
        bitFirstPair = 'a' + bitFirstPair;

        hexFirstPair = transformedText(bitFirstPair);
        hexSecondPair = transformedText(bitSecongPair);

        
    }
}