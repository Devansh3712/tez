#include "tokenizer.hpp"

#ifndef SENTIMENT_HPP
#define SENTIMENT_HPP

/**
 * Sentiment analysis of input text.
 * 
 * Basic sentiment (positive, negative, neutral) analysis. It uses a pre-defined
 * sentiment lexicon for counting words based on sentiment and then returns a ratio
 * between the sentiment count and total count.
 */
class Sentiment {
private:
    std::vector<std::string> positive, negative, neutral;
    long double positiveCount, negativeCount, neutralCount, totalCount;
public:
    Sentiment(std::vector<std::string> words);
    long double positiveSentiment();
    long double negativeSentiment();
    long double neutralSentiment();
};

#endif
