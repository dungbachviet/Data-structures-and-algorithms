#include <iostream>
using namespace std;

#define MAX 100

class Deque
{
	int arr[MAX];
	int front, rear, size;

public:
	Deque(int size)
	{
		front = -1;
		rear = -1;
		this->size = size;
	}

	// Operationis on Deque
	void insertFront(int key);
	void insertRear(int key);
	void deleteFront();
	void deleteRear();
	bool isFull();
	bool isEmpty();
	int getFront();
	int getRear();

};

// Checks whether Deque is full or not
bool Deque::isFull()
{
	return ((front == 0 && rear == size - 1) || front == rear + 1);
}

// Checks whether Deque is empty or not
bool Deque::isEmpty()
{
	return (front == -1 && rear == -1);
}

// Insert key to front of deque
void Deque::insertFront(int key)
{
	// If deque is full
	if (isFull())
	{
		cout << "Overflow\n" << endl;
		return;
	}

	// If deque is empty (change front and rear to 0)
	if (isEmpty())
	{
		front = 0;
		rear = 0;
	}

	// Else if front points to 0
	else if (front == 0)
		front = size - 1;

	else // Else decrement front by 1
		front = front - 1;

	// Insert current element into Deque
	arr[front] = key;
	cout << "Insert " << key << "at front of Dequeu" << endl;
}

// Insert a key to rear of deque
void Deque::insertRear(int key)
{
	// If list is full
	if (isFull())
	{
		cout << "Overflow\n" << endl;
		return;
	}

	// If list is empty, change front and rear to 0
	if (isEmpty())
	{
		front = 0;
		rear = 0;
	}
	
	// If rear is last position of deque
	else if (rear == size - 1)
		rear = 0;

	// Increment rear end by 1
	else
		rear++;

	// Insert current element into Deque
	arr[rear] = key;
	cout << "Insert " << key << "at rear of Dequeu" << endl;
}

// Deletes element at front end of Deque
void Deque::deleteFront()
{
	// check whether Deque is empty or not
	if (isEmpty())
	{
		cout << "Queue Underflow\n" << endl;
		return;
	}

	int key = arr[front];
	// if deque has only one element
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	
	// if front end at last position of deque
	else if (front == size - 1)
		front = 0;

	// increment front end by 1
	else
		front++;

	cout << "Deletes "<< key << "at front of Dequeu" << endl;
}

// Delete element at rear end of Deque
void Deque::deleteRear()
{
	// If Deque is empty
	if (isEmpty())
	{
		cout << "Underflow\n" << endl;
		return;
	}

	int key = arr[rear];
	// if deque has only one element
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}

	// if rear end at first of queue
	else if (rear == 0)
		rear = size - 1;

	// Decrement rear end by 1
	else
		rear--;

	cout << "Deletes " << key << "at rear of Dequeu" << endl;
}

// Returns front element of Deque
int Deque::getFront()
{
	// check whether Deque is empty or not
	if (isEmpty())
	{
		cout << "Underflow\n" << endl;
		return INT_MIN;
	}
	return arr[front];
}

// Returns rear element of Deque
int Deque::getRear()
{
	// check whether deque is empty or not
	if (isEmpty())
	{
		cout << "Underflow \n" << endl;
		return INT_MIN;
	}
	return arr[rear];
}

int main()
{
	Deque dq(5);
	dq.insertFront(3);
	dq.insertFront(2);
	dq.insertFront(1);

	dq.insertRear(4);
	dq.insertRear(5);
	dq.insertRear(6);

	dq.deleteFront();
	dq.deleteFront();

	dq.deleteRear();
	dq.deleteRear();

	cout << "\ngetFront : " << dq.getFront();
	cout << "\ngetFront : " << dq.getFront();

	cout << "\ngetRear : " << dq.getRear();
	cout << "\ngetRear : " << dq.getRear();


	getchar();
	return 0;
}