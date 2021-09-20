#pragma once

#include "libraries.hpp"

stringstream getText(string &text);

string getTextAsString(string &text);

void saveText(stringstream buffer, string text);

string transformedText(string &input);

string fileToHashCode(string &text);