#include <cassert>
#include "../include/tokenizer.hpp"

int main() {
    Tokenizer t("./test/lorem.txt");
    std::vector<std::string> w, s, p;
    w = t.words();
    s = t.sentences();
    p = t.paragraphs();
    assert(w.size() == 404);
    assert(s.size() == 53);
    assert(p.size() == 5);
    return 0;
}
