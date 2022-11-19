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
    for (std::string word: words)
        dict.insert(word);
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

std::pair<std::vector<std::string>, long int> Analyzer::mostCommonWords() {
    std::vector<std::string> result;
    long int maxCount = 1;
    for (HashTableNode *node: dict.items())
        if (node->getCount() > maxCount)
            maxCount = node->getCount();
    for (HashTableNode *node: dict.items())
        if (node->getCount() == maxCount)
            result.push_back(node->getKey());
    return std::make_pair(result, maxCount);
}

std::pair<std::vector<std::string>, long int> Analyzer::leastCommonWords() {
    std::vector<std::string> result;
    long int minCount = 1;
    for (HashTableNode *node: dict.items())
        if (node->getCount() < minCount)
            minCount = node->getCount();
    for (HashTableNode *node: dict.items())
        if (node->getCount() == minCount)
            result.push_back(node->getKey());
    return std::make_pair(result, minCount);
}

/**
 * Implementation of levenshtein distance, which is the minimum number of edits needed to
 * transform one string into the other.
 * 
 * @param originalWord Word to compare to.
 * @param suggestedWord Word to be compared.
 * @return Levenshtein distance between the input words.
 */
int edit_distance(std::string originalWord, std::string suggestedWord) {
    int n = originalWord.size(), m = suggestedWord.size();
    std::vector<std::vector<int>> distance(n + 1, std::vector<int>(m + 1));
    distance[0][0] = 0;
    for(int i = 1; i <= n; ++i)
        distance[i][0] = i;
    for(int i = 1; i <= m; ++i)
        distance[0][i] = i;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            distance[i][j] = std::min(std::min(distance[i - 1][j] + 1, distance[i][j - 1] + 1),
                                        distance[i - 1][j - 1] + (originalWord[i - 1] == suggestedWord[j - 1] ? 0 : 1));
    return distance[n][m];
}

/**
 * Find similarity between 2 words. Output is between 0 to 1, where 0 means no similarity
 * and 1 means the words are same.
 * 
 * @param originalWord Word to compare to.
 * @param suggestedWord Word to be compared.
 * @return Similarity ratio.
 */
float similarity(std::string originalWord, std::string suggestedWord) {
    return 1 - 1.0 * edit_distance(originalWord, suggestedWord) / std::max(originalWord.size(), suggestedWord.size());
}
