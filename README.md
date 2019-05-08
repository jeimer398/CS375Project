# CS375Project

Joshua Eimer and Joseph Osgood

## Input  
input files look like the following (tokens separated by single space):  
node_id number_of_neighbors neighbor_1 neighbor_2 ... neighbor_n

where node_id MUST range from 0, 1, 2, ... ,|V|-1  

see sample input files in "tests" folder  

## Generating Input  

The file "gen_test.cpp" generates test files formatted as described above. 
There are three kinds of graphs gen_tests creates: bintree, onecycle, and random. 
To generate these files, enter the desired num_nodes and MAX_EDGES, and the desired filenames (test1, test2, test3) (see declarations at the top of the main() function). 
Then type `make gen_test` to run the generator. 
(Note that this will take 30 minutes or more for num_nodes >= 10000)  

## Converting to JFlap  

The file "parse_to_jflap.cpp" generates jflap files from the files outputted by "gen_test.cpp". 
To use, type `make parse_to_jflap`, then `./parse_to_jflap <input_filename> <output_filename>`. 
Alterntively, type `make graph` after generating bintree, onecycle, and random for 100, 1000, 10000 and the output jflap files will automaticallybe generated and placed in the "jflap" folder.  

You can also simply type `make gen_test` and `make graph` will automatically run.  

Once you have generated jflap files (they will have extension ".txt"), you can open it with JFlap and then use View -> Apply A Specific Layout Algorithm -> Circle / Tree / GEM (for the Circle / Tree / Random graphs respectively) to generate nice-looking diagrams of graphs.

## Running Files  

To run, type `make exe` and then `./exe <input_filename> <output_filename>`. 
Alternatively, (assuming input files have already been generated), simply type `make run` and the outputs files will be generated and placed in the "outputs" folder. 

## Output 
The output is of the form: 
```
Beginning BFS
	Visiting id: i
	Visiting id: i
...
Ending BFS
	Duration is (x)ms  

Beginning DFS
	Visiting id: i
	Visiting id: i
...
Ending DFS
	Duration is (x)ms
```
Where each connected/reachable component begins and ends with "Beginning BFS/DFS" and "Ending BFS/DFS". 
And the node ids are listed in the order they were visited.
Here, the "Duration" (i.e. "Runtime") is listed in "ms", which here stands for "miscroseconds". 

## Run Time  
The Run Time of both BFS and DFS is O(|V|+|E|), since both algorithms iterate over each adjacent edge for each vertex, which amounts to iterating over each edge in the graph and each vertex in the graph.
