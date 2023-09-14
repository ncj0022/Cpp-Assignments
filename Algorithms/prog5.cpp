#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

//Utility function to find the smallest vertex
int minKey(int key[], bool mstSet[], int V)
{
	int min = INT_MAX, min_index;

	for(int v = 0; v < V; v++)
	{
		if(mstSet[v] == false && key[v] < min)
		{
			min = key[v];
			min_index = v;
		}
	}

	return min_index;
}

int main()
{
	int x;
	int start;
	int h = 0;
	int num = 0;

	string line;
	char *node;
	char cstr[256];

	//Input and output file declaration
	ifstream infile;
	ofstream outfile;

	//Open files
	infile.open("data5.txt");
	outfile.open("out5.txt");

	//Vector to hold lines from input file
	vector<string> hold;

	//Check if file exist and can be opened.
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

	//Construct 2d matrix to use as adjacency Matrix
	int graph[num][num];

	//Input info from data file into 2d Matrix
	//Forms the adjacency matrix to be used.
	for(int i = 0; i < num; i++)
	{
		string token = hold.at(i);
		strcpy(cstr, token.c_str());
		node = strtok(cstr, " ");
		for(int j = 0; j < num; j++)
		{
			while(node != NULL)
			{
				graph[i][j] = atoi(node);
				node = strtok(NULL, " ");
			}
		}
	}


	//Begin MST
	int parent[num];
	int key[num];

	bool mstSet[num];

	for(int i = 0; i < num; i++)
	{
		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	key[0]=0;
	parent[0] = -1;

	for(int count = 0; count < num - 1; count++)
	{
		int u = minKey(key, mstSet, num);

		mstSet[u] = true;

		for(int v = 0; v < num; v++)
		{
			if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}


	//Print MST to output
	int cost = 0;
	outfile << "Edge \tWeight\n";
	for(int i = 1; i < num; i++)
	{
		outfile<<parent[i]+1<<" - "<<i+1<<" \t"<<graph[i][parent[i]]<<endl;
		cost = cost + graph[i][parent[i]];
	}
	outfile<< "Total cost of graph is " << cost << endl;
	outfile.close();
	return 0;
}
