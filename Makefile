test: test_tokenizer test_analyzer test_trie

run:
	g++ -o main main.cpp src/*.cpp
	./main

test_tokenizer:
	g++ -o tokenizer test/testTokenizer.cpp src/*.cpp
	./tokenizer

test_analyzer:
	g++ -o analyzer test/testAnalyzer.cpp src/*.cpp
	./analyzer

test_trie:
	g++ -o trie test/testTrie.cpp src/*.cpp
	./trie
