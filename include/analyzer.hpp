#include <utility>

#include "hashTable.hpp"
#include "tokenizer.hpp"

#ifndef ANALYZER_HPP
#define ANALYZER_HPP

/**
 * Quantitative analysis of input text.
 * 
 * Statistical analysis of the text such as count, most common and least
 * common words etc.
 */
class Analyzer {
private:
    std::vector<std::string> words, sentences, paragraphs;
    HashTable dict;
public:
    Analyzer(Tokenizer t);
    long long int characterCount();
    long long int wordCount();
    long long int sentenceCount();
    long long int paragraphCount();
    std::pair<std::vector<std::string>, long int> mostCommonWords();
    std::pair<std::vector<std::string>, long int> leastCommonWords();
};

// Similarity between 2 words using levenshtein distance.
float similarity(std::string originalWord, std::string suggestedWord);

#endif
