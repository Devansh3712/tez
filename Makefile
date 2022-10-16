test: test_tokenizer

run:
	g++ -o main main.cpp src/*.cpp
	./main

test_tokenizer:
	g++ -o tokenizer test/testTokenizer.cpp src/tokenizer.cpp
	./tokenizer

clean:
	rm *.exe
