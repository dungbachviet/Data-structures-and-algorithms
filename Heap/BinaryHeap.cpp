#include <iostream>
#include <climits>
using namespace std;

// Prototype of a utility function to swap two intergers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{
	int *harr; // Pointer to array of elements in heap
	int capacity; // Maximum possible size of min heap
	int heap_size; // Current number of elements in min heap

public :
	// Constructor
	MinHeap(int capacity);

	// to heapify a subtree with root at a given index
	void MinHeapify(int);

	// return the index of parent of a node
	int parent(int i) { return (i - 1) / 2; }

	// return the index of left child
	int left(int i) { return (2 * i + 1); }

	// return the index of right child
	int right(int i) { return (2 * i + 2); }

	// extract the root which is the minimum element
	int extractMin();

	// decreases key value of key at index i to new_val
	void decreaseKey(int i, int new_val);

	// returns the minimum key (at root) from min heap
	int getMin() { return harr[0]; }

	// deletes a key stored at index i
	void deleteKey(int i);

	// insert a new key 'k'
	void insertKey(int k);

	void printHeap()
	{
		cout << endl;
		for (int i = 0; i < heap_size; i++)
			cout << harr[i] << " ";
		cout << endl;
	}

};

// constructor : Builds a heap with capcity of cap
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

// Insert a new key "k"
void MinHeap::insertKey(int k)
{
	// Check if heap is full
	if (heap_size == capacity)
	{
		cout << "\nOverflow : Could not insertKey\n";
		return;
	}

	// Insert new key to last of array
	int i = heap_size;
	harr[i] = k;
	heap_size++;
	
	// Fix the Min Heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[parent(i)], &harr[i]);
		i = parent(i);
	}
}

// Decreases value of key at index "i" to new_val. It is assumed that new_val is smaller than harr[i]
void MinHeap::decreaseKey(int i, int new_val)
{
	if (i >= heap_size)
	{
		cout << "Error : Index i exceeds the size of array\n";
		return;
	}

	// Assign the smaller value at index i
	harr[i] = new_val;

	// Fix the violation of property if it has
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[parent(i)], &harr[i]);
		i = parent(i);
	}
}

// Remove minimum element (root) from Min Heap
int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[heap_size];
	}

	// store the minimum value, and remove it from Min Heap
	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0); // Fix to maintain the property(characteristic) of Min Heap

	return root;
}

void MinHeap::deleteKey(int i)
{
	// Assign deleted node to INT_MIN, and fix Min Heap Tree to push the deleted node to root
	decreaseKey(i, INT_MIN);

	// Deletes root and fix to maintain the property of Min Heap
	extractMin();
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	// Find the index of minimum value among : current node, left child node, right child node
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[smallest] > harr[l])
		smallest = l;
	if (r < heap_size && harr[smallest] > harr[r])
		smallest = r;

	// If smallest is not be current node, let's heapify Min Heap
	if (smallest != i)
	{
		swap(&harr[smallest], &harr[i]);
		MinHeapify(smallest);
	}
}

// swap value of two elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}



int main()
{
	MinHeap h(11);
	cout << "Insert 3, 2 : ";
	h.insertKey(3);
	h.insertKey(2);
	h.printHeap();

	cout << "\nDeletes node of index 1";
	h.deleteKey(1);
	h.printHeap();

	cout << "\nInsert 15, 5, 4, 45";
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	h.printHeap();

	cout << "\nAfter extractMin ";
	h.extractMin();
	h.printHeap();

	cout << "\nDecrease element at index 2 down to value of 1 : ";
	h.decreaseKey(2, 1);
	h.printHeap();

	getchar();
	return 0;
}