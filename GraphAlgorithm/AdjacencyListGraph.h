
///////////////////////////////////////////////////////////////////////////////////////////////////
// DFS: Topological Sort, Cyclic?, Strongly ConnectedComponent.
///////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

struct GraphNode
{
	string data;

	std::unordered_map<GraphNode*, int> edges;

	GraphNode(string mData)
	{
		data = mData;
	}

public:

	void AddEdge(GraphNode* neiborghNode, int weight = 0)
	{
		std::unordered_map<GraphNode*, int>::const_iterator got = edges.find(neiborghNode);

		if (got != edges.end())
		{
			std::cout << "already contains edge" << endl;
			return;
		}

		edges.insert(std::pair<GraphNode*, int>(neiborghNode, weight));
	}
};



class Graph
{
protected:
	std::vector<GraphNode*> graphData;

public:
	Graph()
	{

	}

	~Graph()
	{

	}


	void DFS(int s)
	{
		std::cout << "DFS: ";

		int size = graphData.size();

		if (s > size - 1)
		{
			std::cout << "illegal node!" << std::endl;
			return;
		}


		// we will create an array with visited nodes
		bool* visited = new bool[size];

		// intialize with all visited nodes been unvisited.
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}

		// create an stack for DFS
		std::stack<int> dfsStack;

		// push the current source node
		dfsStack.push(s);


		while (!dfsStack.empty())
		{
			s = dfsStack.top();
			dfsStack.pop();

			if (!visited[s])
			{
				cout << s << ",";
				visited[s] = true;
			}

			// get our current node
			GraphNode* graphNode = graphData[s];

			for (std::pair<GraphNode*, int> element : graphNode->edges)
			{
				int nodeID = GetID(element.first);

				if (!visited[nodeID])
					dfsStack.push(nodeID);
			}


		}


		std::cout << std::endl;
	}



	// s stands for nodeID
	// which means prints out all the nodeID's in 
	void BFS(int s)
	{
		std::cout << "BFS: ";

		int size = graphData.size();

		if (s > size - 1)
		{
			std::cout << "illegal node!" << std::endl;
			return;
		}


		// we will create an array with visted nodes.
		bool *visited = new bool[size];

		// intialize with all visited nodes been unvisited.
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}

		// create a queue for BFS
		std::queue<int> bfsQueue;

		visited[s] = true;
		bfsQueue.push(s);
		
		// 'i' will be used to get all adjacent 
		// vertices of a vertex 
		list<int>::iterator i;


		while (!bfsQueue.empty())
		{
			s = bfsQueue.front();
			cout << s << ",";
			bfsQueue.pop();

			GraphNode* graphNode = graphData[s];

			for (std::pair<GraphNode*, int> element : graphNode->edges)
			{
				int nodeIndex = GetID(element.first);
				
				if (!visited[nodeIndex])
				{
					visited[nodeIndex] = true;
					bfsQueue.push(nodeIndex);
				}

			}

		}
	
		std::cout << std::endl;
	}


	int AddNode(string Data)
	{
		int currentIndex = graphData.size();

		//std::cout << "ADDING: " << currentIndex << endl;

		graphData.push_back(new GraphNode(Data));

		return currentIndex;
	}

	void AddEdge(int nodeID, int neighborID, int weight = 0)
	{
		if (graphData[nodeID] == nullptr)
		{
			std::cout << "invalid insertion" << endl;
			return;
		}

		if (graphData[neighborID] == nullptr)
		{
			std::cout << "invalid insertion" << endl;
			return;
		}


		graphData[nodeID]->AddEdge(graphData[neighborID], weight);

	}

	int GetID(GraphNode* node)
	{
		std::vector<GraphNode*>::iterator itr = std::find(graphData.begin(), graphData.end(), node);

		if (itr != graphData.cend())
		{
			return std::distance(graphData.begin(), itr);
		}

	}

	void DisplayGraph()
	{
		for (int i = 0; i < graphData.size(); i++)
		{
			std::cout << "node id: " << i <<" Edges: ";
			for(std::pair<GraphNode*, int> element : graphData[i]->edges)
			{
				std::cout << GetID(element.first) << "(" << element.second << "), ";

			}

			std::cout << endl;
		}
	}
};
