#include <string>
#include <vector>

#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

const int DEFAULT_SIZE = 1024;

/**
 * Node for chaining in hash table.
 * 
 * Nodes are created for the linked list used in chaining for resolving
 * hash collisions.
 */
class HashTableNode {
private:
    std::string word;
    long int count;
    HashTableNode *next;
public:
    HashTableNode(std::string word, int value);
    std::string getKey();
    long int getCount();
    HashTableNode* getNext();
    void setNext(HashTableNode *node);
    void incrementCount();
};

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
    // Current maximum size of the table.
    long int maxSize;
    // Current size of the table.
    long int tableSize;
    // Current number of elements in the table.
    long int size;
    HashTableNode **table;
    void resize();
    long int hash(std::string key);
public:
    HashTable();
    ~HashTable();
    void insert(std::string key, int value = 1);
    HashTableNode *search(std::string key);
    std::vector<HashTableNode*> items();
};

#endif
