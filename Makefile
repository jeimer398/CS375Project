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
	./parse_to_jflap tests/bintree.txt jflap/bintree.txt
	./parse_to_jflap tests/onecycle.txt jflap/onecycle.txt
	./parse_to_jflap tests/random.txt jflap/random.txt

run: all
	./exe tests/test1.txt outfile1.txt
	cat outfile1.txt
	echo "==="
	./exe tests/test2.txt outfile2.txt
	cat outfile2.txt
	./exe tests/test3.txt outfile3.txt
	cat outfile3.txt
	echo "==="
	./exe tests/test4.txt outfile4.txt
	cat outfile4.txt
	echo "==="
	./exe tests/bintree.txt bintree.txt
	cat bintree.txt
	echo "==="
	./exe tests/onecycle.txt onecycle.txt
	cat onecycle.txt
	echo "==="
	./exe tests/random.txt random.txt
	cat random.txt

gdb: all
	gdb ./exe

clean: 
	rm exe *.o *.txt parse_to_jflap gen_test
