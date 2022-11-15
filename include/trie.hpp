#include <string>
#include <vector>

#ifndef TRIE_HPP
#define TRIE_HPP

class TrieNode {
public:
    // Only lowercase alphabets are used in the words, thus 26 children.
    TrieNode *child[26];
    // True if node represents end of a word.
    bool isEndChar;
    TrieNode();
};

class Trie {
public:
    TrieNode *root;
    Trie();
    void insert(std::string word);
    bool isLastNode(TrieNode *node);
    void wordSuggestions(TrieNode *root, std::string prefix, std::vector<std::string> *words);
    std::vector<std::string> similarWords(std::string word);
};

#endif
