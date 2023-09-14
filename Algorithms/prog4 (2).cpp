//Name: Nicholas Jones
//Date: November 18, 2019
//Class: CSCE 3110-Data Structures and Algorithms
//Description: Perform Topological Sort using information provided in a file.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <list>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

//Global vector to sort final output
vector<int> reverse;

//Graph Class
class Graph
{
	int v; //number of verticies

	list<int> *adj; //List of adjacent nodes

	void topoUtil(int v, bool visited[], stack<int> &stack); //stack to keep track of visited nodes
public:
	Graph(int v);

	void addEdge(int v, int w); //Add directional edge between two nodes

	void topoSort();
};

//Graph Constructor
Graph::Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::topoUtil(int v, bool visited[], stack<int> &stack)
{
	visited[v] = true;

	list<int>::iterator i;

	for(i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if(!visited[*i])
		{
			topoUtil(*i, visited, stack);
		}
	}

	stack.push(v);
}

//Perform Topological Sort
void Graph::topoSort()
{
	stack<int> stack;

	bool *visited = new bool[v];

	for(int i = 0; i < v; i++)
	{
		visited[i] = false;
	}

	for(int i = 0; i < v; i++)
	{
		if(visited[i] == false)
		{
			topoUtil(i, visited, stack);
		}
	}

	//Puts  verticies in stack in reverse vector to be called later
	//because verticies are added on stack in reverse order.
	while(stack.empty() == false)
	{
		reverse.push_back(stack.top());
		stack.pop();
	}
}


int main()
{
	int x;
	int start;  //Vertex arrows are coming off of
	int num;

	string line;
	char *vertex;
	char cstr[256];

	//Input and output file declaration
	ifstream infile;
	ofstream outfile;

	//Open files
	infile.open("data4.txt");
	outfile.open("out4.txt");


	vector<string> hold;
	vector<int> edges; //Vector to keep track of edges from input file

	//Retrieve information from input file and store in vector
	if(infile.is_open())
	{
		while(getline(infile, line))
		{
			hold.push_back(line);
			num++;
		}
		infile.close();
	}
	else
	{
		cout << "Unable to open file." << endl;
	}

	Graph g(num); //Graph Class Declaration

	//Loop to add edges between each vertex after delimiting
	//information stored in hold vector
	for(int i = 0; i < num-1; i++)
	{
		string token = hold.at(i);
		strcpy(cstr, token.c_str());
		vertex = strtok(cstr, " ");
		start = atoi(vertex);
		while(vertex!=0) //Begin adding edges between nodes
		{
			x = atoi(vertex);
			vertex = strtok(NULL, " ");
			g.addEdge(start, x);
		}
	}


	g.topoSort(); //Perform Topological sort

	for(int i = num-1; i >= 0; i--)
	{
		outfile << reverse.at(i) << " ";
	}
	cout << endl;
	cout << "Topological Sort Complete" << endl;

	outfile.close();
	return 0;
}
