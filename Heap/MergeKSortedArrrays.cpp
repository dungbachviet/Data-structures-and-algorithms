#include <iostream>
#include <limits.h>
using namespace std;

#define n 4

// A Min Heap node
struct MinHeapNode
{
	int element; // store the value of element
	int i; // index of the array from which the element is taken
	int j; // index of the next element to be picked from array
};

// Prototype of a utility function to swap two min heap nodes
void swap(MinHeapNode *x, MinHeapNode *y);

// A class for Min Heap
class MinHeap
{
	MinHeapNode *harr; // pointer to array of elements in heap
	int heap_size; // size of min heap

public : 
	// constructor to create a min heap of given size
	MinHeap(MinHeapNode a[], int size);

	// to heapify a subtree with root at given size
	void MinHeapify(int);

	// to get index of left child of node at index i
	int left(int i) { return (2 * i + 1); }

	// to get index of right child of node at index i
	int right(int i) { return (2 * i + 2); }

	// to get the root
	MinHeapNode getMin() { return harr[0]; }

	// to replace root with new node x and heapify new root
	void replaceMin(MinHeapNode x) 
	{
		harr[0] = x; 
		MinHeapify(0);
	}
};

// Build a Min Heap from a given array a[] of given size
MinHeap::MinHeap(MinHeapNode a[], int size)
{
	heap_size = size;
	harr = a;
	// point to the last internal node
	int i = (heap_size - 2) / 2;
	// to heapify on each internal node
	while (i >= 0)
	{
		MinHeapify(i);
		i = i - 1;
	}
}

void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[smallest].element > harr[l].element)
		smallest = l;
	if (r < heap_size && harr[smallest].element > harr[r].element)
		smallest = r;

	if (smallest != i)
	{
		swap(&harr[smallest], &harr[i]);
		MinHeapify(smallest);
	}
}

void swap(MinHeapNode *x, MinHeapNode *y)
{
	MinHeapNode temp = *x;
	*x = *y;
	*y = temp;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

// Merge K sorted array using Min Heap
int *mergeKArrays(int arr[][n], int k)
{
	// store ouput sorted array
	int *output = new int[n*k];

	// Create array for Min Heap with k nodes
	MinHeapNode *harr = new MinHeapNode[k];
	for (int i = 0; i < k; i++)
	{
		harr[i].element = arr[i][0];
		harr[i].i = i;
		harr[i].j = 1;
	}

	// Customized Data Structure for Heap : Provide some of useful methods for Min Heap
	MinHeap hp = MinHeap(harr, k); 

	// Now one by one get the minimum element from min heap and replace it with next element of its array
	for (int count = 0; count < n*k; count++)
	{
		// Copy the minimum element from Min Heap
		MinHeapNode root = hp.getMin();
		
		// Save to output array
		output[count] = root.element;

		// Check whether has any elements from the array containing root
		if (root.j < n)
		{
			// Get the next element from the array containing root
			root.element = arr[root.i][root.j];
			// point to new next element in the array
			root.j += 1;
		}
		else // If the array (containing root) has not any more elements, assign root to INT_MAX
			root.element = INT_MAX;
		 
		// Change root to new value and heapify Min Heap
		hp.replaceMin(root);
	}

	return output;
}

int main()
{
	int arr[][n] = { { 2, 6, 12, 34 }, { 1, 9, 20, 1000 }, { 23, 34, 90, 2000 } };

	int k = sizeof(arr) / sizeof(arr[0]);
	int *output = mergeKArrays(arr, k);
	cout << "Merged array is : " << endl;
	printArray(output, n*k);

	getchar();
	return 0;
}