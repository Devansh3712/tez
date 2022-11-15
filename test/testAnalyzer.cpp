#include <cassert>
#include "../include/analyzer.hpp"

int main() {
    Tokenizer t("./test/lorem.txt");
    Analyzer a(t);
    assert(a.wordCount() == 404);
    assert(a.sentenceCount() == 53);
    assert(a.paragraphCount() == 5);
    return 0;
}
