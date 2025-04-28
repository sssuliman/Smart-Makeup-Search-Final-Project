#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <vector>
#include <string>

class TrieNode {
public:
    bool isEndOfWord;
    std::unordered_map<char, TrieNode*> children;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;
    void dfs(TrieNode* node, std::string prefix, std::vector<std::string>& results);

public:
    Trie();
    void insert(const std::string& word);
    bool search(const std::string& word);
    std::vector<std::string> getSuggestions(const std::string& prefix);
};

#endif
