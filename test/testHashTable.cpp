#include <cassert>
#include <map>
#include "../include/hashTable.hpp"
#include "../include/tokenizer.hpp"

int main() {
    Tokenizer t("./test/lorem.txt");
    HashTable h;
    std::map<std::string, long int> m;
    for (std::string word: t.words()) {
        h.insert(word);
        m[word]++;
    }
    for (HashTableNode *item: h.items()) {
        assert(item->getCount() == m[item->getKey()]);
    }
    return 0;
}
