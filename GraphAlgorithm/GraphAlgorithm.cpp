// GraphAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AdjacencyListGraph.h"

int main()
{
	Graph graph;
		
	int node1 = graph.AddNode("1");
	int node2 = graph.AddNode("2");
	int node3 = graph.AddNode("3");
	int node4 = graph.AddNode("4");
	int node5 = graph.AddNode("5");

	graph.AddEdge(node1, node2);
	graph.AddEdge(node2, node3);
	graph.AddEdge(node2, node5);
	graph.AddEdge(node3, node4);
	

	graph.DisplayGraph();

//	graph.BFS(node1);

	graph.DFS(node1);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
