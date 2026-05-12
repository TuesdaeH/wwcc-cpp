#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    cout << "TEXT ANALYZER" << endl;
    cout << "-------------" << endl;
    cout << "Enter a sentence or paragraph:" << endl;

    string text;
    getline(cin, text);

    // Character count
    int charCount = text.length();

    // Sentence count
    int sentenceCount = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentenceCount++;
        }
    }

    // Word count, longest word, average word length
    stringstream ss(text);
    string word;
    int wordCount = 0;
    string longestWord = "";
    double totalWordLength = 0;

    while (ss >> word) {
        wordCount++;

        // Strip punctuation for comparison
        string cleanWord = word;
        cleanWord.erase(remove_if(cleanWord.begin(), cleanWord.end(), ::ispunct), cleanWord.end());

        totalWordLength += cleanWord.length();

        if (cleanWord.length() > longestWord.length()) {
            longestWord = cleanWord;
        }
    }

    double avgWordLength = (wordCount > 0) ? totalWordLength / wordCount : 0;

    // Uppercase and lowercase
    string upper = text;
    string lower = text;
    for (int i = 0; i < text.length(); i++) {
        upper[i] = toupper(text[i]);
        lower[i] = tolower(text[i]);
    }

    // Display results
    cout << "\nAnalysis:" << endl;
    cout << "  Characters (with spaces): " << charCount << endl;
    cout << "  Word count:               " << wordCount << endl;
    cout << "  Sentence count:           " << sentenceCount << endl;
    cout << "  Longest word:             " << longestWord << endl;
    cout << "  Average word length:      " << avgWordLength << " characters" << endl;

    cout << "\nUppercase:" << endl;
    cout << "  " << upper << endl;

    cout << "\nLowercase:" << endl;
    cout << "  " << lower << endl;

    return 0;
}