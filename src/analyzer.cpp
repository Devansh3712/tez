#include "../include/analyzer.hpp"

/**
 * Stores the words, sentences and paragraphs from the tokenizer
 * object.
 * 
 * @param t Tokenizer object of input text.
 */
Analyzer::Analyzer(Tokenizer t) {
    words = t.words();
    sentences = t.sentences();
    paragraphs = t.paragraphs();
}

/**
 * Returns the total count of characters in the text.
 * 
 * @return Total character count.
 */
long long int Analyzer::characterCount() {
    long long int count = 0;
    for (long long int i = 0; i < paragraphs.size(); i++) {
        count += paragraphs[i].size();
    }
    return count;
}

/**
 * Returns the total count of words in the text.
 * 
 * @return Total word count.
 */
long long int Analyzer::wordCount() {
    return words.size();
}

/**
 * Returns the total count of sentences in the text.
 * 
 * @return Total sentence count.
 */
long long int Analyzer::sentenceCount() {
    return sentences.size();
}

/**
 * Returns the total count of paragraphs in the text.
 * 
 * @return Total paragraph count.
 */
long long int Analyzer::paragraphCount() {
    return paragraphs.size();
}
