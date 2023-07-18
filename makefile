all: compile run

compile:
	g++ -I ./include/ -o ./lib/ArrayList.o -c ./src/ArrayList.cpp
	g++ -I ./include/ -o ./lib/Factorial.o -c ./src/Factorial.cpp
	g++ -I ./include/ -o ./bin/main ./lib/ArrayList.o ./lib/Factorial.o ./src/main.cpp

run:
	./bin/main