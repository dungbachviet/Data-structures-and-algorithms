//
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//using namespace std;
//
//// A structure to represent an edge in graph
//struct Edge
//{
//	int src, dest;
//};
//
//// A structure to represent a graph
//struct Graph
//{
//	int V, E;
//	struct Edge* edge;
//};
//
//
//// Creates a graph with V vertices and E edges
//struct Graph* createGraph(int V, int  E)
//{
//	struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
//	graph->V = V;
//	graph->E = E;
//	graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
//
//	return graph;
//}
//
//// A utility function to find the subset of an element i
//int find(int parent[], int i)
//{
//	if (parent[i] == -1)
//		return i;
//	return find(parent, parent[i]);
//}
//
//// A utility function to do union of two subsets
//void Union(int parent[], int x, int y)
//{
//	// Get set of x
//	int xset = find(parent, x);
//
//	// Get set of y
//	int yset = find(parent, y);
//
//	// Set up an union
//	parent[xset] = yset;
//}
//
//int isCycle(struct Graph* graph)
//{
//	int *parent = (int*)malloc(graph->V * sizeof(int));
//	memset(parent, -1, sizeof(int) * graph->V);
//
//	for (int i = 0; i < graph->E; i++)
//	{
//		int x = find(parent, graph->edge[i].src);
//		int y = find(parent, graph->edge[i].dest);
//
//		// if 2 vertex belong to the same subset, creates circle
//		if (x == y)
//			return 1;
//		// Set the union of them since x, y lie on same edge
//		Union(parent, x, y);
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int V = 5, E = 5;
//	struct Graph* graph = createGraph(V, E);
//
//	// add edge 0-1
//	graph->edge[0].src = 0;
//	graph->edge[0].dest = 1;
//
//	// add edge 0-2
//	graph->edge[1].src = 0;
//	graph->edge[1].dest = 2;
//
//	// add edge 3-2
//	graph->edge[2].src = 3;
//	graph->edge[2].dest = 2;
//
//	// add edge 2-4
//	graph->edge[3].src = 2;
//	graph->edge[3].dest = 4;
//
//	// add edge 3-4
//	graph->edge[4].src = 3;
//	graph->edge[4].dest = 4;
//
//	if (isCycle(graph))
//		printf("graph contains cycle");
//	else
//		printf("graph doesn't contain cycle");
//
//	getchar();
//	return 0;
//}
