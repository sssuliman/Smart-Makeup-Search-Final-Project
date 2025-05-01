#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "../include/Trie.h"

using namespace std;

// Converts a string to lowercase for consistent comparison
string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Removes punctuation from a word to avoid matching errors (e.g., "foundation:" → "foundation")
string cleanWord(string word) {
    word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
    return word;
}

// Loads the makeup dataset and inserts each word into the Trie
// Also stores the full line so we can retrieve it when a prefix matches
void loadData(const string& filename, Trie& trie, vector<string>& fullLines) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        fullLines.push_back(line);
        string lowered = toLower(line); // convert entire line to lowercase
        istringstream ss(lowered);
        string word;
        while (ss >> word) {
            word = cleanWord(word); // strip punctuation
            if (!word.empty()) {
                trie.insert(word, line); // insert word → attach full line
            }
        }
    }
    file.close();
}

// Prints the header instructions for the user
void printHeader() {
    cout << "=====================================\n";
    cout << "     SMART MAKEUP SEARCH TOOL        \n";
    cout << "=====================================\n";
    cout << "Search by:\n";
    cout << "  • prefix  → type one or more starting letters (e.g., 'foun oily')\n";
    cout << "Returns full product lines that contain words starting with each prefix.\n";
    cout << "Type 'exit' to quit.\n";
}

// Displays a list of full matching product lines
void printResults(const vector<string>& results) {
    if (results.empty()) {
        cout << "No matches found.\n";
    } else {
        cout << "\nResults:\n----------------------------\n";
        for (const auto& line : results) {
            cout << " - " << line << "\n";
        }
    }
    cout << "----------------------------\n";
}

int main() {
    Trie trie;
    vector<string> fullData;

    // Load all product lines and populate Trie with each word
    loadData("data/products_organized_full.txt", trie, fullData);
    printHeader();

    string input;
    while (true) {
        cout << "\nEnter prefix term(s): ";
        getline(cin, input);
        string term = toLower(input);
        if (term == "exit") break;

        // Break user input into individual prefix terms
        istringstream ss(term);
        vector<string> prefixes;
        string word;
        while (ss >> word) {
            prefixes.push_back(cleanWord(word));
        }

        // For each prefix, find all matching product lines
        unordered_map<string, int> lineCount;
        for (const string& prefix : prefixes) {
            vector<string> lines = trie.getMatchingLines(prefix);
            for (const string& line : lines) {
                lineCount[line]++; // count how many prefixes each line matched
            }
        }

        // Only include lines that matched all prefix terms
        vector<string> results;
        for (const auto& pair : lineCount) {
            if (pair.second == static_cast<int>(prefixes.size())) {
                results.push_back(pair.first);
            }
        }

        printResults(results);
    }

    cout << "\nThank you for using Smart Makeup Search!\n";
    return 0;
}