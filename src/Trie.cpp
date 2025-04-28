#include "../include/Trie.h"
#include <algorithm> // for std::transform

// Helper function to convert strings to lowercase
std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

TrieNode::TrieNode() : isEndOfWord(false) {}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word) {
    std::string lowerWord = toLower(word);
    TrieNode* node = root;
    for (char ch : lowerWord) {
        if (!node->children.count(ch)) {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->isEndOfWord = true;
}

bool Trie::search(const std::string& word) {
    std::string lowerWord = toLower(word);
    TrieNode* node = root;
    for (char ch : lowerWord) {
        if (!node->children.count(ch)) return false;
        node = node->children[ch];
    }
    return node->isEndOfWord;
}

void Trie::dfs(TrieNode* node, std::string prefix, std::vector<std::string>& results) {
    if (node->isEndOfWord) results.push_back(prefix);
    for (auto& [ch, child] : node->children) {
        dfs(child, prefix + ch, results);
    }
}

std::vector<std::string> Trie::getSuggestions(const std::string& prefix) {
    std::string lowerPrefix = toLower(prefix);
    TrieNode* node = root;
    for (char ch : lowerPrefix) {
        if (!node->children.count(ch)) return {};
        node = node->children[ch];
    }
    std::vector<std::string> results;
    dfs(node, lowerPrefix, results);
    return results;
}