CFLAGS = -g -Wall -Wextra -DDEBUG -pedantic -std=c++14

all: exe

exe: bfs.o dfs.o
	g++ $(CFLAGS) exe.cpp bfs.o dfs.o -o exe 

bfs.o: BFS.cpp Node.h
	g++ $(CFLAGS) -c BFS.cpp -o bfs.o

dfs.o: DFS.cpp Node.h
	g++ $(CFLAGS) -c DFS.cpp -o dfs.o

gen_test: gen_test.cpp
	g++ $(CFLAGS) gen_test.cpp -o gen_test
	./gen_test
	make graph

parse_to_jflap: parse_to_jflap.cpp
	g++ $(CFLAGS) parse_to_jflap.cpp -o parse_to_jflap

graph: parse_to_jflap
	./parse_to_jflap tests/bintree100.txt jflap/bintree100.txt
	./parse_to_jflap tests/onecycle100.txt jflap/onecycle100.txt
	./parse_to_jflap tests/random100.txt jflap/random100.txt
	./parse_to_jflap tests/bintree1000.txt jflap/bintree1000.txt
	./parse_to_jflap tests/onecycle1000.txt jflap/onecycle1000.txt
	./parse_to_jflap tests/random1000.txt jflap/random1000.txt
	./parse_to_jflap tests/bintree10000.txt jflap/bintree10000.txt
	./parse_to_jflap tests/onecycle10000.txt jflap/onecycle10000.txt
	./parse_to_jflap tests/random10000.txt jflap/random10000.txt

run: all
	mkdir outputs/
	./exe tests/test1.txt outfile1.txt
	./exe tests/test2.txt outfile2.txt
	./exe tests/test3.txt outfile3.txt
	./exe tests/test4.txt outfile4.txt
	./exe tests/bintree100.txt bintree100.txt
	./exe tests/onecycle100.txt onecycle100.txt
	./exe tests/random100.txt random100.txt
	./exe tests/bintree1000.txt bintree1000.txt
	./exe tests/onecycle1000.txt onecycle1000.txt
	./exe tests/random1000.txt random1000.txt
	./exe tests/bintree10000.txt bintree10000.txt
	./exe tests/onecycle10000.txt onecycle10000.txt
	./exe tests/random10000.txt random10000.txt
	./exe tests/random10000-5000.txt random10000-5000.txt
	./exe tests/random10000-8000.txt random10000-8000.txt
	mv *.txt outputs/

gdb: all
	gdb ./exe

clean: 
	rm -r exe *.o outputs/ parse_to_jflap gen_test
