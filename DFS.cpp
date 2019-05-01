#include "Node.h"

using namespace std;

string DFS_helper(struct Graph g){
	for(Node n : g.node_lst) n.color = white;
	string ret = "";
	ret += "\nBeginning DFS\n";
	for(Node n : g.node_lst){
		if(n.color == white){
			ret += DFS(&g, n.id);
		}
	}
	ret += "Ending DFS\n";
	return ret;
}

string DFS(struct Graph *g, int start_id){
	string ret = "";
	Node temp;
	temp = g->node_lst[start_id];
	ret += "\tVisiting id: " + to_string(temp.id) + "\n"; 
	g->node_lst[start_id].color = gray;
	for(int idx : temp.adj_lst){
		if(g->node_lst[idx].color == white){
			ret += DFS(g, idx);
		}
	}
	temp.color = black;
	g->node_lst[temp.id] = temp;
	return ret;
}
