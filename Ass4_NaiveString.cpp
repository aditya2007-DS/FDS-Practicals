// Assignment 4 Naive String Matching Algorithm
#include <iostream>
#include <string>

using namespace std;

void naiveStringSearch(string text, string pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    bool matchFound = false;

    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;

        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == patternLength) {
            cout << "Pattern found at index: " << i << endl;
            matchFound = true;
        }
    }

    if (!matchFound) {
        cout << "Pattern not found in the given text." << endl;
    }
}

int main() {
    string text = "AABAACAADAABAABAA";
    string pattern = "AABA";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "------------------------" << endl;

    naiveStringSearch(text, pattern);

    return 0;
}

/*
Output:
Text: AABAACAADAABAABAA
Pattern: AABA
------------------------
Pattern found at index: 0
Pattern found at index: 9
Pattern found at index: 12
*/
