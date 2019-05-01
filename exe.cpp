#include"Node.h"

using namespace std;

int main(int argc, char ** argv){
	if(argc != 3){
		cout << "To run, use ./main <input.txt> <output.txt>" << endl;
		return -1;
	}

	ifstream infile(argv[1]);
	ofstream outfile;
	outfile.open(argv[2]);

	struct Graph graph;
	int node_id, num_vals, i, temp_val;

	while(infile >> node_id >> num_vals){
		struct Node node;
		node.id = node_id;
		for(i = 0; i < num_vals; i++){
			infile >> temp_val;
			node.adj_lst.push_back(temp_val);
		}
		node.color = white;
		graph.node_lst.push_back(node);
	}

	for(Node n : graph.node_lst){
		cout << n.id << endl;
		for(int i : n.adj_lst){
			cout << "\t" << i << endl;
		}
	}

	return 0;
}
