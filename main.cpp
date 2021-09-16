#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

stringstream getText(string &text) {
    std::ifstream file;
    file.open(text);

    if(!file) {
        throw std::runtime_error("File could not be opened");
    }

    stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer;
}

string getTextAsString(string &text) {
    stringstream buffer = getText(text);
    string content = buffer.str();
    return content;
}

void saveText(stringstream buffer, string text) {
    std::ofstream file;
    file.open(text);

    if(!file) {
        throw std::runtime_error("File could not be opened");
    }

    file << buffer.str();
    file.close();
}

// string file(string &file) {
//     string content = getTextAsString(file);
// }

int main()
{
    string text = "test.txt";
    cout << getTextAsString(text);
}   