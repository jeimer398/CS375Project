#ifndef JJ
#define JJ
#include<iostream>
#include<vector>

enum VISITED{
	black,
	white,
	gray
};

struct Node{
	int id;
	enum VISITED color;
};

struct Graph{
	std::vector<std::vector<Node>> adj_lst;
};

#endif
