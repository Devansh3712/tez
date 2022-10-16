build:
	g++ -o main main.cpp src/*.cpp

test_tokenizer:
	g++ -o tokenizer test/testTokenizer.cpp src/tokenizer.cpp
