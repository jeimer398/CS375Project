#include "Node.h"

using namespace std;

void breakhere(){
	int i = 0;
	i++;
}

void BFS_helper(struct Graph g){
	for(Node n : g.node_lst){
		cout << n.id << "   " << n.color << endl;
		if(n.color == white){
			BFS(&g, n.id);
		}
	}
}

void BFS(struct Graph *g, int start_id){
	breakhere();
	cout << "In BFS" << endl;
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
		cout << temp.id << endl;
		for(int idx : temp.adj_lst){
			if(g->node_lst[idx].color == white){
				g->node_lst[idx].color = gray;
				q.push_back(g->node_lst[idx]);
			}
		}
		temp.color = black;
		g->node_lst[temp.id] = temp;
	}	
	cout << "Done with BFS" << endl;
}
