//
//#include <iostream>
//#include <list>
//
//using namespace std;
//
//
//// This class represents a directed graph using adjacency list
//// representation
//class Graph
//{
//	int V; // number of vertices
//	list<int> *adj; // pointer to an array containing adjacency list
//
//public: 
//	Graph(int V);
//	
//	void addEdge(int v, int w);
//
//	void BFS(int s);
//};
//
//// Create new graph with V vertices
//Graph::Graph(int V)
//{
//	this->V = V;
//	adj = new list<int>[V];
//}
//
//// Add new edge to graph
//void Graph::addEdge(int v, int w)
//{
//	adj[v].push_back(w);
//}
//
//// Breath First Search
//void Graph::BFS(int s)
//{
//	// Save the vertices visited
//	bool *visited = new bool[V];
//	for (int i = 0; i < V; i++)
//		visited[i] = false;
//
//	// Queue to save the vertices not visited
//	list<int> queue;
//
//	// Assign status of vertex s to be visited
//	// and push this vetex into back of queue
//	visited[s] = true;
//	queue.push_back(s);
//
//	
//	// check if queue is empty
//	while (!queue.empty())
//	{
//		// Get the first element of queue
//
//		s = queue.front();
//		cout << s << " ";
//
//		// Remove the vertex from queue after traversed
//		queue.pop_front();
//
//		// Traverse all unvisited adjacent vertices of the vertex s
//		for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); i++)
//		{
//			// Push vertex into queue if it has not been visited before
//			if (!visited[*i])
//			{
//				visited[*i] = true;
//				queue.push_back(*i);
//			}
//		}
//	}
//}
//
//int main()
//{
//	Graph g(4);
//	g.addEdge(0, 1);
//	g.addEdge(0, 2);
//	g.addEdge(1, 2);
//	g.addEdge(2, 0);
//	g.addEdge(2, 3);
//	g.addEdge(3, 3);
//	
//	cout << "Following is Breath First Traversal "
//		<< "(starting from vertex 2) \n";
//	g.BFS(2);
//
//	getchar();
//	return 0;
//}


