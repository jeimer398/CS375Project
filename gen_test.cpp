#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

bool isin(vector<int> vect, int findme){
	for(auto iter = vect.begin(); iter < vect.end(); iter++){
		if(*iter == findme){
			return true;
		}
	}
	return false;
}

int main(int argc, char ** argv){
	string test1 = "tests/bintree.txt";
	string test2 = "tests/onecycle.txt";
	string test3 = "tests/manycycle.txt";
	string test4 = "tests/random.txt";

	int num_nodes = 100;
	int MAX_EDGES = 15;
	string outstr = "";

	srand(time(NULL));
	//int num = rand() % MAX + 1;

	//bintree
	ofstream outfile;
	outfile.open(test1);
	for(int i=0; i<num_nodes+1; i++){
		outstr += to_string(i) + " ";
		//if any edges
		if(i < num_nodes / 2 ){
			//add edges
			int num_edge = 2; // rand() % MAX + 1;
			outstr += to_string(num_edge) + " ";
			outstr += to_string(i*2+1) + " ";
			outstr += to_string(i*2+2);
		}else{
			outstr += "0";
		}
		outstr += "\n";
	}
	outfile << outstr << endl;
	outfile.close();

	//circle
	outstr = "";
	outfile.open(test2);
	for(int i=0; i<num_nodes; i++){
		outstr += to_string(i) + " ";
		outstr += to_string(1) + " ";
		outstr += to_string((i+1) % num_nodes) + " ";
		outstr += "\n";
	}
	outfile << outstr << endl;
	outfile.close();

	//random
	outstr = "";
	outfile.open(test4);
	for(int i=0; i<num_nodes; i++){
		outstr += to_string(i) + " ";
		//if any edges
		int num_edge = rand() % MAX_EDGES;
		outstr += to_string(num_edge) + " ";
		vector<int> vect; 
		for(int j=0; j<num_edge; j++){
			//add edges
			int rand_edge = rand() % num_nodes;
			while(isin(vect, rand_edge))
				rand_edge = rand() % num_nodes;
			vect.push_back(rand_edge);
			outstr += to_string(rand_edge) + " ";
		}
		outstr += "\n";
	}
	outfile << outstr << endl;
	outfile.close();

	return 0;
}
