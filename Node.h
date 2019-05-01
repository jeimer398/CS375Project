#ifndef JJ
#define JJ
#include<iostream>
#include<vector>
#include<fstream>
#include<deque>

enum VISITED{
	black,
	white,
	gray
};

struct Node{
	std::vector<int> adj_lst;
	int id;
	enum VISITED color;
};

struct Graph{
	std::vector<Node> node_lst;
};

void BFS(struct Graph, int);
#endif
