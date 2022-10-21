#include <string>
#ifndef NODE_HPP
#define NODE_HPP

/**
 * Node for chaining in hash table.
 * 
 * Nodes are created for the linked list used in chaining for resolving
 * hash collisions.
 */
class Node {
private:
    std::string word;
    long long int count;
    Node *next;
public:
    Node(std::string word, int value);
    std::string getKey();
    long long int getCount();
    Node* getNext();
    void incrementCount();
};

#endif