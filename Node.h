#ifndef JJ
#define JJ
#include<iostream>
#include<vector>
#include<fstream>
#include<deque>
#include<string>
#include<chrono>

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

std::string BFS(struct Graph *, int);
std::string BFS_helper(struct Graph);
#endif
