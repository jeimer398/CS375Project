#include"Node.h"

using namespace std;
using namespace std::chrono;

struct Graph graph;

int main(int argc, char ** argv){
	if(argc != 3){
		cout << "To run, use ./main <input.txt> <output.txt>" << endl;
		return -1;
	}

	ifstream infile(argv[1]);
	ofstream outfile;
	outfile.open(argv[2]);

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

	/* for(Node n : graph.node_lst){ */
	/* 	cout << n.id << endl; */
	/* 	for(int i : n.adj_lst){ */
	/* 		cout << "\t" << i << endl; */
	/* 	} */
	/* } */

	/* BFS */
	string bfsret = ""; 

	auto start = steady_clock::now();

	bfsret = BFS_helper(graph);
	
	auto stop = steady_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	outfile << bfsret << "\tDuration is " << duration.count() << ("ms") << endl;

	/* DFS */
	string dfsret = ""; 

	start = steady_clock::now();

	dfsret = DFS_helper(graph);
	
	stop = steady_clock::now();
	duration = duration_cast<microseconds>(stop - start);

	outfile << dfsret << "\tDuration is " << duration.count() << ("ms") << endl;

	return 0;
}
