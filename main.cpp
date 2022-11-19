#include <filesystem>
#include <iostream>
#include "include/analyzer.hpp"
#include "include/sentiment.hpp"
#include "include/tabulate.hpp"
#include "include/trie.hpp"
using namespace tabulate;

std::string ASCII_ART = R"(       __          )" "\n"
R"(      / /____  ____)" "\n"
R"(     / __/ _ \/_  /)" "\n"
R"(    / /_/  __/ / /_)" "\n"
R"(    \__/\___/ /___/)" "\n";

int main() {
    std::cout << "\033[1;36m" << ASCII_ART << "\033[0m" << std::endl;
    std::cout << "\033[1;35mQuantitative Text Analyzer\033[0m\n" << std::endl;
    Table menu;
    menu.add_row({"OPTION", "COMMAND"});
    menu.add_row({"1", "Statistical Analysis"});
    menu.add_row({"2", "Sentiment Analysis"});
    menu.add_row({"3", "Similar Words"});
    menu.add_row({"4", "Exit"});
    menu[0].format()
        .font_color(Color::yellow)
        .font_align(FontAlign::center);
    for (int i = 1; i <= 4; i++)
        menu[i][0].format()
            .font_align(FontAlign::center);
    std::cout << menu << std::endl;
    while (true) {
        int option;
        std::cout << std::endl << "tez> Enter option: ";
        std::cin >> option;
        switch (option) {
            case 1: {
                std::string filePath;
                std::cout << "tez> Enter path of text file: ";
                std::cin >> filePath;
                if (!std::filesystem::exists(filePath)) {
                    std::cout << "\033[31m[-] File does not exist.\033[0m" << std::endl;
                    break;
                }
                Tokenizer t(filePath);
                Analyzer a(t);
                Table analysis;
                std::string character, word, sentence, paragraph, mostCommonWords = "", leastCommonWords = "";
                std::pair<std::vector<std::string>, long int> mostCommonWordList, leastCommonWordList;
                character = std::to_string(a.characterCount());
                word = std::to_string(a.wordCount());
                sentence = std::to_string(a.sentenceCount());
                paragraph = std::to_string(a.paragraphCount());
                mostCommonWordList = a.mostCommonWords();
                leastCommonWordList = a.leastCommonWords();
                for (long int i = 0; i < mostCommonWordList.first.size(); i++) {
                    mostCommonWords += mostCommonWordList.first[i];
                    if (i != mostCommonWordList.first.size() - 1)
                        mostCommonWords += ", ";
                }
                for (long int i = 0; i < leastCommonWordList.first.size(); i++) {
                    leastCommonWords += leastCommonWordList.first[i];
                    if (i != leastCommonWordList.first.size() - 1)
                        leastCommonWords += ", ";
                }
                analysis.add_row({"PARAMETER", "RESULT"});
                analysis.add_row({"Character Count", character});
                analysis.add_row({"Word Count", word});
                analysis.add_row({"Sentence Count", sentence});
                analysis.add_row({"Paragraph Count", paragraph});
                analysis[0].format()
                    .font_color(Color::yellow)
                    .font_align(FontAlign::center);
                std::cout << analysis << std::endl;
                std::cout << "\n\033[33mMost Common Word(s): \033[0m" << mostCommonWords
                        << " [" << mostCommonWordList.second << "]" << std::endl;
                std::cout << "\033[33mLeast Common Word(s): \033[0m" << leastCommonWords
                        << " [" << leastCommonWordList.second << "]" << std::endl;
                break;
            }
            case 2: {
                std::string filePath;
                std::cout << "tez> Enter path of text file: ";
                std::cin >> filePath;
                if (!std::filesystem::exists(filePath)) {
                    std::cout << "\033[31m[-] File does not exist.\033[0m" << std::endl;
                    break;
                }
                Tokenizer t(filePath);
                HashTable h;
                for (std::string word: t.words())
                    h.insert(word);
                std::vector<std::string> words;
                for (HashTableNode* item: h.items())
                    words.push_back(item->getKey());
                try {
                    Sentiment s(words);
                    Table analysis;
                    std::string positive, negative, neutral;
                    positive = std::to_string(s.positiveSentiment());
                    negative = std::to_string(s.negativeSentiment());
                    neutral = std::to_string(s.neutralSentiment());
                    analysis.add_row({"PARAMETER", "RESULT"});
                    analysis.add_row({"Positive Sentiment", positive});
                    analysis.add_row({"Negative Sentiment", negative});
                    analysis.add_row({"Neutral Sentiment", neutral});
                    analysis[0].format()
                        .font_color(Color::yellow)
                        .font_align(FontAlign::center);
                    analysis[1][0].format()
                        .font_color(Color::green);
                    analysis[2][0].format()
                        .font_color(Color::red);
                    analysis[3][0].format()
                        .font_color(Color::blue);
                    std::cout << analysis << std::endl;
                } catch(...) {
                    std::cout << "\033[31m[-] Not enough keywords for sentiment analysis.\033[0m" << std::endl;
                }
                break;
            }
            case 3: {
                std::string filePath, inputWord;
                std::cout << "tez> Enter path of text file: ";
                std::cin >> filePath;
                if (!std::filesystem::exists(filePath)) {
                    std::cout << "\033[31m[-] File does not exist.\033[0m" << std::endl;
                    break;
                }
                std::cout << "tez> Enter word: ";
                std::cin >> inputWord;
                Tokenizer t(filePath);
                Trie _t;
                for (std::string word: t.words())
                    _t.insert(word);
                Table similarWords;
                similarWords.add_row({"WORD", "SIMILARITY"});
                for (std::string word: _t.similarWords(inputWord)) {
                    float similarityPercentage = similarity(inputWord, word) * 100;
                    similarWords.add_row({word, std::to_string(similarityPercentage)});
                }
                similarWords[0].format()
                        .font_color(Color::yellow)
                        .font_align(FontAlign::center);
                std::cout << similarWords << std::endl;
                break;
            }
            case 4:
                std::cout << "\033[32m[+] Terminating program.\033[0m" << std::endl;
                exit(0);
            default:
                std::cout << "\033[31m[-] Choose a correct option from the menu\033[0m" << std::endl;
                break;
        }
    }
    return 0;
}
