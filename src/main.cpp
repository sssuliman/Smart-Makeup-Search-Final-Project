#include <iostream>
#include <fstream>
#include "../include/Trie.h"

void printHeader() {
    std::cout << "=====================================\n";
    std::cout << "     SMART MAKEUP SEARCH TOOL        \n";
    std::cout << "=====================================\n";
    std::cout << "Type a keyword to search makeup.\n";
    std::cout << "Type 'exit' to quit the program.\n\n";
}

void printSuggestions(const std::vector<std::string>& suggestions) {
    if (suggestions.empty()) {
        std::cout << "No matches found.\n";
    } else {
        std::cout << "\nSuggestions:\n";
        std::cout << "----------------------------\n";
        for (const auto& word : suggestions) {
            std::cout << " - " << word << "\n";
        }
    }
    std::cout << "----------------------------\n";
}

void loadProducts(const std::string& filename, Trie& trie) {
    std::ifstream file(filename);
    std::string product;
    while (getline(file, product)) {
        trie.insert(product);
    }
    file.close();
}

int main() {
    Trie trie;
    loadProducts("data/products.txt", trie);

    printHeader();

    std::string prefix;
    while (true) {
        std::cout << "\nSearch keyword: ";
        std::getline(std::cin, prefix);

        if (prefix == "exit") {
            std::cout << "\nGoodbye! Thank you for using the Smart Makeup Search Tool.\n";
            break;
        }

        std::vector<std::string> suggestions = trie.getSuggestions(prefix);
        printSuggestions(suggestions);
    }

    return 0;
}
