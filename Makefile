.phony: all clean


all: main


main: main.cpp
	g++ $^ -o main -O3
clean:
	rm -f main