#include "../include/Trie.h"
using namespace std;

// Constructor: initializes an empty TrieNode
TrieNode::TrieNode() {
    isEndOfWord = false;
}

// Constructor: initializes the root node of the Trie
Trie::Trie() {
    root = new TrieNode();
}

// Insert a word into the Trie and attach the full product line to the node where the word ends
void Trie::insert(const string& word, const string& fullLine) {
    TrieNode* node = root;
    for (char ch : word) {
        if (!node->children.count(ch)) {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->isEndOfWord = true;
    node->lines.insert(fullLine);  // Store the full product line at the end node
}

// Recursive depth-first search to collect all full lines under a Trie node
void Trie::dfs(TrieNode* node, vector<string>& results) {
    for (const string& line : node->lines) {
        results.push_back(line);  // Collect matching product line
    }
    for (auto& pair : node->children) {
        dfs(pair.second, results);  // Recurse through child nodes
    }
}

// Search the Trie for all lines that match a given prefix
vector<string> Trie::getMatchingLines(const string& prefix) {
    TrieNode* node = root;
    for (char ch : prefix) {
        if (!node->children.count(ch)) return {};  // Prefix not found
        node = node->children[ch];
    }
    vector<string> results;
    dfs(node, results);  // Gather all lines under this prefix node
    return results;
}