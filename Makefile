CFLAGS = -g -Wall -Wextra -DDEBUG -pedantic -std=c++14

all: main

main: bfs.o dfs.o
	g++ $(CFLAGS) main.cpp bfs.o dfs.o -o main

bfs.o: BFS.cpp Node.h
	g++ $(cflags) -c BFS.cpp -o bfs.o

dfs.o: DFS.cpp Node.h
	g++ $(cflags) -c DFS.cpp -o dfs.o

clean: 
	rm main *.o
