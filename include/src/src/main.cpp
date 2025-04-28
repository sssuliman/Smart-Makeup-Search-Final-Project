#include <iostream>
#include <fstream>
#include "../include/Trie.h"

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

    std::cout << "Welcome to Smart Makeup Search!\n";

    std::string prefix;
    while (true) {
        std::cout << "\nEnter a product keyword (or 'exit'): ";
        std::getline(std::cin, prefix);
        if (prefix == "exit") break;

        std::vector<std::string> suggestions = trie.getSuggestions(prefix);
        if (suggestions.empty()) {
            std::cout << "No matches found.\n";
        } else {
            std::cout << "Suggestions:\n";
            for (const auto& word : suggestions) {
                std::cout << "- " << word << "\n";
            }
        }
    }

    return 0;
}
