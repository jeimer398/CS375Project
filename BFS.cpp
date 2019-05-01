#include "Node.h"

using namespace std;

string BFS_helper(struct Graph g){
	string ret = "";
	for(Node n : g.node_lst){
		/* cout << n.id << "   " << n.color << endl; */
		if(n.color == white){
			ret += BFS(&g, n.id);
		}
	}
	return ret;
}

string BFS(struct Graph *g, int start_id){
	string ret = "";
	ret += "Beginning BFS\n";
	ret += "\tStarting with node: " + to_string(start_id) + "\n";
	Node temp;
	for(Node n : g->node_lst){
		if(n.id == start_id)
			continue;
		n.color = white;
	}
	g->node_lst[start_id].color = gray;
	deque<Node> q;
	q.push_back(g->node_lst[start_id]);

	while(!q.empty()){
		temp = q.front();
		q.pop_front();
		ret += "\t\tVisiting id: " + to_string(temp.id) + "\n"; 
		for(int idx : temp.adj_lst){
			if(g->node_lst[idx].color == white){
				g->node_lst[idx].color = gray;
				q.push_back(g->node_lst[idx]);
			}
		}
		temp.color = black;
		g->node_lst[temp.id] = temp;
	}	
	ret += "Ending BFS\n";
	return ret;
}
