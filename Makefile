test: test_tokenizer test_analyzer

run:
	g++ -o main main.cpp src/*.cpp
	./main

test_tokenizer:
	g++ -o tokenizer test/testTokenizer.cpp src/tokenizer.cpp
	./tokenizer

test_analyzer:
	g++ -o analyzer test/testAnalyzer.cpp src/*.cpp
	./analyzer
