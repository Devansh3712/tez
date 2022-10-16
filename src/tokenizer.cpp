#include <algorithm>
#include <fstream>
#include <sstream>
#include "tokenizer.hpp"

/**
 * Reads the content of the input file and stores in a string
 * variable.
 *
 * @param filePath Path of the file to be read.
 */
Tokenizer::Tokenizer(std::string filePath) {
    std::ifstream inFile;
    inFile.open(filePath);
    std::stringstream stream;
    stream << inFile.rdbuf();
    inFile.close();
    content = stream.str();
}

/**
 * Store all words of the file content in a vector of strings.
 * Words are delimited by whitespaces after converted to lowercase
 * and removing punctuations.
 *
 * @return Vector of words.
 */
std::vector<std::string> Tokenizer::words() {
    std::vector<std::string> result;
    std::string currentWord;
    for (long long int i = 0; i < content.size(); i++) {
        if (content[i] != ' ' && content[i] != '\n')
            currentWord += content[i];
        else {
            if (currentWord.size())
                result.push_back(currentWord);
            currentWord = "";
        }
    }
    if (currentWord.size())
        result.push_back(currentWord);
    for (long long int i = 0; i < result.size(); i++) {
        // Convert to lowercase.
        std::transform(result[i].begin(), result[i].end(), result[i].begin(), ::tolower);
        // Remove punctuations.
        auto iterator = std::remove_if(result[i].begin(), result[i].end(), ::ispunct);
        result[i].erase(iterator, result[i].end());
    }
    return result;
}

/**
 * Store all sentences of the file content in a vector of strings.
 * Sentences are delimited by periods (.), question marks (?) and
 * exclamation marks (?).
 *
 * @return Vector of sentences.
 */
std::vector<std::string> Tokenizer::sentences() {
    std::vector<std::string> result;
    std::string currentSentence;
    for (long long int i = 0; i < content.size(); i++) {
        if (content[i] != '.' && content[i] != '?' && content[i] != '!' && content[i] != '\n')
            currentSentence += content[i];
        else {
            if (currentSentence.size())
                result.push_back(currentSentence);
            currentSentence = "";
        }
    }
    if (currentSentence.size())
        result.push_back(currentSentence);
    return result;
}

/**
 * Store all paragraphs of the file content in a vector of strings.
 * Paragraphs are delimited by newline (\n).
 *
 * @return Vector of paragraphs.
 */
std::vector<std::string> Tokenizer::paragraphs() {
    std::vector<std::string> result;
    std::string currentParagraph;
    for (long long int i = 0; i < content.size(); i++) {
        if (content[i] != '\n')
            currentParagraph += content[i];
        else {
            if (currentParagraph.size())
                result.push_back(currentParagraph);
            currentParagraph = "";
        }
    }
    if (currentParagraph.size())
        result.push_back(currentParagraph);
    return result;
}
