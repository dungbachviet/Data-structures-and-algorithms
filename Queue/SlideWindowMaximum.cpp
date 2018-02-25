#include <iostream>
#include <deque>

using namespace std;

// Prints maximum element of all subarrays of size k
void printKMax(int arr[], int n, int k)
{
	// Create a build-in deque
	deque<int> Deque(k);

	// Process first k elements (first window) of array
	int i;
	for (i = 0; i < k; i++)
	{
		// Remove the useless element (that less than other right-side elements) 
		while (!Deque.empty() && arr[i] >= arr[Deque.back()])
			Deque.pop_back();

		// Push arr[i] at rear of Deque
		Deque.push_back(i);
	}

	// Process rest of the elements from arr[k] to arr[n-1]
	for (; i < n; i++)
	{
		cout << arr[Deque.front()] << " ";

		// Remove the elements which are out of this window
		while (!Deque.empty() && Deque.front() <= i - k)
			Deque.pop_front();
		 
		// Remove all elements smaller than currently being added element (remove useless elements)
		while (!Deque.empty() && arr[i] >= arr[Deque.back()])
			Deque.pop_back();

		// Add current element at the rear of Deque
		Deque.push_back(i);
	}

	// Print the maximum element of last window
	cout << arr[Deque.front()];
}

int main()
{
	int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	printKMax(arr, n, k); // 78 90 90 90 89

	getchar();
	return 0;
}