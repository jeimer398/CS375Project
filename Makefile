CFLAGS = -g -Wall -Wextra -DDEBUG -pedantic -std=c++14

all: exe

exe: bfs.o dfs.o
	g++ $(CFLAGS) exe.cpp bfs.o dfs.o -o exe 

bfs.o: BFS.cpp Node.h
	g++ $(CFLAGS) -c BFS.cpp -o bfs.o

dfs.o: DFS.cpp Node.h
	g++ $(CFLAGS) -c DFS.cpp -o dfs.o

parse_to_jflap: parse_to_jflap.cpp
	g++ $(CFLAGS) parse_to_jflap.cpp -o parse_to_jflap

graph: parse_to_jflap
	./parse_to_jflap tests/test1.txt jflap/test1.txt

run: all
	./exe tests/test1.txt outfile1.txt
	cat outfile1.txt
	echo "==="
	./exe tests/test2.txt outfile2.txt
	cat outfile2.txt

gdb: all
	gdb ./exe

clean: 
	rm exe *.o *.txt parse_to_jflap
