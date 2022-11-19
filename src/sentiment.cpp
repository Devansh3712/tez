#include "../include/sentiment.hpp"

/**
 * Store the count of positive, negative and neutral words from the input
 * text. If total word count is zero, throw an error.
 */
Sentiment::Sentiment(std::vector<std::string> words) {
    Tokenizer _positive("./res/positive.txt");
    Tokenizer _negative("./res/negative.txt");
    Tokenizer _neutral("./res/neutral.txt");
    positive = _positive.words();
    negative = _negative.words();
    neutral = _neutral.words();
    positiveCount = negativeCount = neutralCount = totalCount = 0;
    for (std::string word: words) {
        if (std::find(positive.begin(), positive.end(), word) != positive.end()) {
            positiveCount++;
            totalCount++;
        }
        if (std::find(negative.begin(), negative.end(), word) != negative.end()) {
            negativeCount++;
            totalCount++;
        }
        if (std::find(neutral.begin(), neutral.end(), word) != neutral.end()) {
            neutralCount++;
            totalCount++;
        }
    }
    if (totalCount == 0)
        throw -1;
}

long double Sentiment::positiveSentiment() {
    return (positiveCount / totalCount) * 100;
}

long double Sentiment::negativeSentiment() {
    return (negativeCount / totalCount) * 100;
}

long double Sentiment::neutralSentiment() {
    return (neutralCount / totalCount) * 100;
}
