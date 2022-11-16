#include "../include/trie.hpp"

/**
 * Get index of character with respect to lowercase 'a'.
 * 
 * @param alphabet Character whose index is required.
 */
int charIndex(char alphabet) {
    return (int)alphabet - (int)'a';
}

TrieNode::TrieNode() {
    isEndChar = false;
    for (int i = 0; i < 26; i++)
        child[i] = nullptr;
}

Trie::Trie() {
    root = new TrieNode();
}

/**
 * Insert a word into the trie if its not present. If the word is a
 * prefix of a node, it just marks the leaf node.
 */
void Trie::insert(std::string word) {
    TrieNode *temp = root;
    for (int i = 0; i < word.length(); i++) {
        int index = charIndex(word[i]);
        if(!temp->child[index])
            temp->child[index] = new TrieNode();
        temp = temp->child[index];
    }
    temp->isEndChar = true;
}

/**
 * Check whether a node is a leaf node in the trie.
 * 
 * @return True if all children are NULL else false.
 */
bool Trie::isLastNode(TrieNode *node) {
    for (int i = 0; i < 26; i++)
        if (node->child[i])
            return false;
    return true;
}

/**
 * Recursive function to store suggested words in a vector of strings for
 * a given node. The vector is passed by reference.
 */
void Trie::wordSuggestions(TrieNode *node, std::string prefix, std::vector<std::string> *words) {
    if (node->isEndChar)
        words->push_back(prefix);
    for (int i = 0; i < 26; i++)
        if (node->child[i]) {
            char newPrefix = 'a' + i;
            wordSuggestions(node->child[i], prefix + newPrefix, words);
        }
}

std::vector<std::string> Trie::similarWords(std::string word) {
    std::vector<std::string> words;
    TrieNode *temp = root;
    for (char c: word) {
        int index = charIndex(c);
        if (!temp->child[index])
            return words;
        temp = temp->child[index];
    }
    if (isLastNode(temp)) {
        words.push_back(word);
        return words;
    }
    wordSuggestions(temp, word, &words);
    return words;
}
