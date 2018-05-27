//
//#include <iostream>
//#include <list>
//#include <limits.h>
//using namespace std;
//
//class Graph
//{
//	int V; // NUmber of vertices
//	list<int> *adj; // Pointer to an array containing adjacency lists
//	bool isCyclicUtil(int v, bool visited[], bool *rs);
//
//public:
//	Graph(int V);
//	void addEdge(int v, int w);
//	bool isCyclic();// Return true if there is a cycle in this graph
//};
//
//Graph::Graph(int V)
//{
//	this->V = V;
//	adj = new list<int>[V];
//}
//
//void Graph::addEdge(int v, int w)
//{
//	adj[v].push_back(w);
//}
//
//
//bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
//{
//	if (visited[v] == false)
//	{
//		visited[v] = true;
//		recStack[v] = true;
//
//		list<int>::iterator i;
//		for (i = adj[v].begin(); i != adj[v].end(); i++)
//		{
//			// if vertex is not visited ==> call isCyclic (DFS)
//			if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
//				return true;
//			// vertex has been visited but not traversed
//			else if (recStack[*i]) 
//				return true;
//			
//		}
//	}
//	recStack[v] = false;
//	
//	return false;
//}
//
//bool Graph::isCyclic()
//{
//	// Marks vertices visited (được thăm)
//	bool *visited = new bool[V];
//
//	// Marks vertices traversed (được duyệt = được thăm + thăm hết các đỉnh kề)
//	bool *recStack = new bool[V];
//
//	// Initialize values
//	for (int i = 0; i < V; i++)
//	{
//		visited[i] = false;
//		recStack[i] = false;
//	}
//
//	// Since graph can have few connected components so we should call DFS for each vertex
//	for (int i = 0; i < V; i++)
//		if (isCyclicUtil(i, visited, recStack))
//			return true;
//
//	return false;
//}
//
//int main()
//{
//	// Create a graph given in the above diagram
//	Graph g(4);
//	g.addEdge(0, 1);
//	g.addEdge(0, 2);
//	g.addEdge(1, 2);
//	g.addEdge(2, 0);
//	g.addEdge(2, 3);
//	g.addEdge(3, 3);
//
//	if (g.isCyclic())
//		cout << "Graph contains cycle";
//	else
//		cout << "Graph doesn't contain cycle";
//
//	getchar();
//	return 0;
//}