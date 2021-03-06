//#include <iostream>
//#include <list>
//using namespace std;
//
//class Graph
//{
//	int V; // Number of vertices
//	list<int> *adj; // Adjacency List
//
//	void DFSUtil(int v, bool visited[]);
//
//public:
//	// Constructor
//	Graph(int V);
//
//	// Function to add an edge to graph
//	void addEdge(int v, int w);
//
//	// DFS traversal of the vertices reachable from v
//	void DFS(int v);
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
//// DFS traversal of the vertices reachable from v
//void Graph::DFS(int v)
//{
//	bool *visited = new bool[V];
//	for (int i = 0; i < V; i++)
//		visited[i] = false;
//
//	DFSUtil(v, visited);
//}
//
//
//void Graph::DFSUtil(int v, bool visited[])
//{
//	visited[v] = true;
//	cout << v << " ";
//
//	list<int>::iterator i;
//	for (i = adj[v].begin(); i != adj[v].end(); i++)
//	{
//		if (!visited[*i])
//			DFSUtil(*i, visited);
//	}
//	
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
//	cout << "Following is Depth First Traversal"
//		<< " (starting from vertex 2 \n";
//	g.DFS(2);
//
//	getchar();
//	return 0;
//}