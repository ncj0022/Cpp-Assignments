//Name: Nicholas Jones
//Date: March 03, 2020
//Course: CSCE 3110
//Description: Performs a Breadth First Search on a given Adjacency List.

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Graph
{
    int v; //number of verticies
    list<int> *adj; //pointer to adjacency list

    public:
        Graph(int v); //constructor
        void addEdge(int v, int x); //add edges between nodes
        void Bfs(int s); //perform breadth first seach
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int x)
{
    adj[v].push_back(x);
}

void Graph::Bfs(int s)
{
    ofstream outfile;
    outfile.open("out2.txt");
    // Mark all the vertices as not visited
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
    {
	visited[i] = false;
    }

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

}

int main()
{
    int n_lines = 0; //number of n_lines
    string n;
    string line;

    vector<int> node; //vector containing nodes
    vector<string> token; //vector to contain delimited string tokens

    //Opening input and output files
    ifstream myfile;
    ofstream outfile;

    myfile.open("data2.txt");
    outfile.open("out2.txt");

    if(myfile.is_open())
    {
        while(getline(myfile, line))
        {
            n_lines++;
            node.push_back(n_lines); //add node to vector
	    token.push_back(line);
        }

    }

    Graph g(n_lines);

    char cstr[256];
    char *vertex;
    int start;
    int first = 1;
    for(int i = 0; i < n_lines-1; i++)
    {
	string s = token.at(i);
	strcpy(cstr, s.c_str());
	vertex = strtok(cstr, " ");
	start = atoi(vertex);
	while(vertex != 0) //Begin adding edges between nodes
	{
		int x = atoi(vertex);
		vertex = strtok(NULL, " ");
		g.addEdge(first, x);
		cout << first << " - " << x << endl;
	}
	first++;
    }

    cout << endl;
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.Bfs(2);

	outfile << "Connected" << endl;
    return 0;

}

