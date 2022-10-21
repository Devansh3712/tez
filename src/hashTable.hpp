#include "node.hpp"
#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

const int DEFAULT_SIZE = 128;

/**
 * Hash table for storing word count of the input text.
 * 
 * Resizable hash table for storing the occurences of words in the text file
 * input by the user after tokenizing it. The keys are string and the values
 * are integer.
 */
class HashTable {
private:
    float threshold;
    long int maxSize;
    long int tableSize;
    long int size;
    Node **table;
    void resize();
public:
    HashTable();
    ~HashTable();
    void insert(std::string key, int value);
    void remove(std::string key);
    long long int search(std::string key);
};

#endif