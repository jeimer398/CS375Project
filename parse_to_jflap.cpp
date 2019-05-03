#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string addnode(int id){
	return string("\t<state id=\"") + to_string(id) + 
			"\" name=\"q" + to_string(id) + "\">\n" + 
				"\t\t<x>99.0</x>\n" + 
				"\t\t<y>55.0</y>\n" + 
			"\t</state>\n";
}

string addtrans(int from, int to){
	return string("\t<transition>\n") + 
			"\t\t<from>" + to_string(from) + "</from>\n" +
			"\t\t<to>" + to_string(to) + "</to>\n" +
			"\t\t<read> </read>\n" +
		"\t</transition>\n";
}

int main(int argc, char ** argv){
	if(argc != 3){
		cout << "To run, use ./main <input.txt> <output.txt>" << endl;
		return -1;
	}

	ifstream infile(argv[1]);
	ofstream outfile;
	outfile.open(argv[2]);

	int node_id, num_vals, i, temp_val;
	string outstr = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?><!--Created with JFLAP 6.4.--><structure>\n"
						"<type>fa</type>\n"
						"<automaton>\n"
						"<!--The list of states.-->\n";
	string trans = "<!--The list of transitions.-->\n";

	while(infile >> node_id >> num_vals){
		outstr += addnode(node_id);
		for(i = 0; i < num_vals; i++){
			infile >> temp_val;
			trans += addtrans(node_id, temp_val);
		}
	}
	outstr += trans + "</automaton>\n" + 
				"</structure>";
	outfile << outstr << endl;
	return 0;
}
