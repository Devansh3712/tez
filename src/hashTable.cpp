#include "../include/hashTable.hpp"

/**
 * Create a node for the hash table with the word and
 * it's frequency.
 * 
 * @param _word Word to be stored.
 * @param _frequency Initial frequency of the word.
 */
HashTableNode::HashTableNode(std::string _word, int _value) {
    word = _word;
    count = _value;
    next = nullptr;
}

std::string HashTableNode::getKey() {
    return word;
}

long int HashTableNode::getCount() {
    return count;
}

HashTableNode* HashTableNode::getNext() {
    return next;
}

void HashTableNode::setNext(HashTableNode *node) {
    next = node;
}

void HashTableNode::incrementCount() {
    count++;
}

HashTable::HashTable() {
    threshold = 0.75f;
    tableSize = DEFAULT_SIZE;
    maxSize = (long int)(threshold * tableSize);
    size = 0;
    table = new HashTableNode*[tableSize];
    for (long int i = 0; i < tableSize; i++)
        table[i] = nullptr;
}

HashTable::~HashTable() {
    for (long int i = 0; i < tableSize; i++)
        if (table[i] != nullptr) {
            HashTableNode *prev, *curr = table[i];
            while (curr != nullptr) {
                prev = curr;
                curr = curr->getNext();
                delete curr;
            }
        }
    delete[] table;
}

/**
 * Dynamically resize the hash table. The table size is increased by 2x once
 * it passes the maximum size derived using a threshold frequency.
 */
void HashTable::resize() {
    long int oldSize = tableSize;
    tableSize *= 2;
    maxSize = (long int)(tableSize * threshold);
    HashTableNode **oldTable = table;
    table = new HashTableNode*[tableSize];
    for (long int i = 0; i < tableSize; i++)
        table[i] = nullptr;
    size = 0;
    for (long int i = 0; i < oldSize; i++)
        if (oldTable[i] != nullptr) {
            HashTableNode *oldItem, *item = oldTable[i];
            while (item != nullptr) {
                insert(item->getKey(), item->getCount());
                oldItem = item;
                item = item->getNext();
                delete oldItem;
            }
        }
    delete[] oldTable;
}

/**
 * Get an index for storing the node in the hash table by hashing
 * the key of the node.
 * 
 * @return Index at which node has to be stored.
 */
long int HashTable::hash(std::string key) {
    long int res = 0;
    for (int i = 0; i < key.length(); i++) {
        res += (key[i] << 4) + key[i];
    }
    return res % tableSize;
}

/**
 * Insert a node in the hash table. The hash table does collision resolution
 * by chaining (closed addressing), thus each item in the table contains a link
 * to a singly linked list containing items with the same hash value.
 * 
 * Items with same hash are added to the end of the linked list.
 */
void HashTable::insert(std::string key, int value) {
    long int index = hash(key);
    if (table[index] == nullptr) {
        table[index] = new HashTableNode(key, value);
        size++;
    } else {
        HashTableNode *item = table[index];
        while (item->getNext() != nullptr) {
            if (item->getKey() == key) {
                item->incrementCount();
                return;
            }
            item = item->getNext();
        }
        if (item->getKey() == key)
            item->incrementCount();
        else
            item->setNext(new HashTableNode(key, value));
            size++;
    }
    if (size >= maxSize)
        resize();
}

/**
 * Retrieve a key-value pair from the hash table if it exists.
 * 
 * @return HashTableNode if key exists else nullptr.
 */
HashTableNode *HashTable::search(std::string key) {
    long int index = hash(key);
    if (table[index] == nullptr)
        return nullptr;
    HashTableNode *item = table[index];
    while (item != nullptr && item->getKey() != key)
        item = item->getNext();
    if (item == nullptr)
        return nullptr;
    return item;
}

/**
 * Get all items of the hash table.
 * 
 * @return Vector of all nodes of hash table.
 */
std::vector<HashTableNode*> HashTable::items() {
    std::vector<HashTableNode*> result;
    for (long int i = 0; i < tableSize; i++)
        if (table[i] != nullptr) {
            HashTableNode *temp = table[i];
            while (temp != nullptr) {
                result.push_back(temp);
                temp = temp->getNext();
            }
        }
    return result;
}
