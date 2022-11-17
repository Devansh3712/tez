cmake_minimum_required(VERSION 3.25)
project(tez
        VERSION 1.0.0
        DESCRIPTION "Quantitative Text Analyzer")

add_executable(main main.cpp
                src/analyzer.cpp
                src/hashTable.cpp
                src/tokenizer.cpp
                src/trie.cpp)

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
