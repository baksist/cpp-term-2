CC ?= g++

OBJECTS = $(patsubst src/%.cpp, build/%.o, $(wildcard src/*.cpp))

all: build/main

run: clean build/main
	build/main

build:
	mkdir -p build

clean:
	rm -rf build

build/main: $(OBJECTS)
	$(CC) -g -lstdc++ -l cryptopp -o $@ $^

build/%.o: src/%.cpp | build
	$(CC) -Og -c -Isrc/include -std=c++14 -o $@ $<
