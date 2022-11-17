#include <iostream>

std::string ASCII_ART = R"(       __          )" "\n"
R"(      / /____  ____)" "\n"
R"(     / __/ _ \/_  /)" "\n"
R"(    / /_/  __/ / /_)" "\n"
R"(    \__/\___/ /___/)" "\n";

int main() {
    std::cout << "\033[1;36m" << ASCII_ART << "\033[0m" << std::endl;
    std::cout << "\033[1;35mQuantitative Text Analyzer\033[0m\n" << std::endl;
    return 0;
}
