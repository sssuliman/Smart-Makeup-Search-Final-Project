#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Node for each character in the Trie
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;  // Links to next letters
    std::unordered_set<std::string> lines;         // Set of full product lines ending here
    bool isEndOfWord;                              // True if this is the end of a word

    TrieNode(); // Constructor
};

// Trie class for inserting and searching prefix terms
class Trie {
private:
    TrieNode* root;

    // Helper for recursively finding all full lines under a given node
    void dfs(TrieNode* node, std::vector<std::string>& results);

public:
    Trie();  // Constructor

    // Insert a word into the Trie and associate it with a full line
    void insert(const std::string& word, const std::string& fullLine);

    // Get all full product lines that match a given prefix
    std::vector<std::string> getMatchingLines(const std::string& prefix);
};

#endif