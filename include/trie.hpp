#include <string>
#include <vector>

#ifndef TRIE_HPP
#define TRIE_HPP

/**
 * Node of a trie.
 * 
 * Node is used for storing a character of a word, using it's index
 * with respect to 'a'.
 */
class TrieNode {
public:
    // Only lowercase alphabets are used in the words, thus 26 children.
    TrieNode *child[26];
    // True if node represents end of a word.
    bool isEndChar;
    TrieNode();
};

/**
 * Trie for storing distinct words of the input text.
 * 
 * Trie is used for retrieving words similar to input by a user. It recursively
 * suggests words similar to the input, and stores them in a vector of strings.
 */
class Trie {
private:
    TrieNode *root;
public:
    Trie();
    void insert(std::string word);
    bool isLastNode(TrieNode *node);
    void wordSuggestions(TrieNode *node, std::string prefix, std::vector<std::string> *words);
    std::vector<std::string> similarWords(std::string word);
};

#endif
