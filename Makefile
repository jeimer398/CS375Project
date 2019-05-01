CFLAGS = -g -Wall -Wextra -DDEBUG -pedantic -std=c++14

all: exe

exe: bfs.o dfs.o
	g++ $(CFLAGS) exe.cpp bfs.o dfs.o -o exe 

bfs.o: BFS.cpp Node.h
	g++ $(cflags) -c BFS.cpp -o bfs.o

dfs.o: DFS.cpp Node.h
	g++ $(cflags) -c DFS.cpp -o dfs.o

run: all
	./exe tests/test1.txt outfile1.txt
	echo "==="
	./exe tests/test2.txt outfile2.txt

clean: 
	rm exe *.o *.txt
