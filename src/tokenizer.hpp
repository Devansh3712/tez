#include <string>
#include <vector>

#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

/**
 * Tokenizing user file input.
 *
 * The input file is read and tokenized into words, sentences and paragraphs.
 * Used for creating the hash table of the words and statistical analysis
 * of the text.
 */
class Tokenizer {
private:
    std::string content;
public:
    Tokenizer(std::string filePath);
    std::vector<std::string> words();
    std::vector<std::string> sentences();
    std::vector<std::string> paragraphs();
};

#endif
