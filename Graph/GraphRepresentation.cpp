//
//#include <stdio.h>
//#include <stdlib.h>
//
//// A structure to represent an adjacency list node
//struct AdjListNode
//{
//	int data;
//	AdjListNode *next;
//};
//
//// A structure to reprensent an adjacency list
//struct AdjList
//{
//	AdjListNode *head;
//};
//
//// A structure to represent a graph
//// A graph is an array of adjacency lists
//// Number of vertices : V (= size of array)
//struct Graph
//{
//	int V;
//	AdjList *array;
//};
//
//
//// A utility function to create a new adjacency list node
//AdjListNode *newAdjListNode(int newData)
//{
//	AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
//	newNode->data = newData;
//	newNode->next = NULL;
//	return newNode;
//}
//
//// A utility function that creates a graph of numberVertices vertices
//Graph *createGraph(int numberVertices)
//{
//	Graph *graph = (Graph *)malloc(sizeof(Graph));
//	graph->V = numberVertices;
//
//	graph->array = (AdjList *)malloc(numberVertices * sizeof(AdjList));
//	for (int vertexIndex = 0; vertexIndex < numberVertices; vertexIndex++)
//		graph->array[vertexIndex].head = NULL;
//
//	return graph;
//}
//
//// Adds an edge to an undirected graph
//void addEdge(Graph *graph, int src, int dest)
//{
//	// Add a edge from src to dest
//	AdjListNode *newNode = newAdjListNode(dest);
//	newNode->next = graph->array[src].head;
//	graph->array[src].head = newNode;
//
//	// Add a edge from dest to src (since the graph is undirected)
//	newNode = newAdjListNode(src);
//	newNode->next = graph->array[dest].head;
//	graph->array[dest].head = newNode;
//}
//
//// A utility function to print the adjacency list
//void printGraph(Graph *graph)
//{
//	for (int v = 0; v < graph->V; v++)
//	{
//		AdjListNode *temp = graph->array[v].head;
//		printf("\n Adjacency list of vertex %d\n head ", v);
//		while (temp)
//		{
//			printf("-> %d", temp->data);
//			temp = temp->next;
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int V = 5;
//	Graph *graph = createGraph(V);
//	addEdge(graph, 0, 1);
//	addEdge(graph, 0, 4);
//	addEdge(graph, 1, 2);
//	addEdge(graph, 1, 3);
//	addEdge(graph, 1, 4);
//	addEdge(graph, 2, 3);
//	addEdge(graph, 3, 4);
//
//	printGraph(graph);
//
//	getchar();
//	return 0;
//}
