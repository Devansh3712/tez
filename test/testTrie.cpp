#include <cassert>
#include "../include/trie.hpp"

int main() {
    Trie t;
    t.insert("hello");
    t.insert("dog");
    t.insert("cat");
    t.insert("hell");
    t.insert("help");
    t.insert("world");
    t.insert("heart");
    std::vector<std::string> similarWords = t.similarWords("he");
    std::string words[] = {"heart", "hell", "hello", "help"};
    for (int i = 0; i < similarWords.size(); i++)
        assert(similarWords[i] == words[i]);
    return 0;
}
