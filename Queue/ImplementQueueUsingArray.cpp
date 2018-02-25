#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a queue
struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int *array;
};

// Create a new queue of given capacity as well as initializes size of queue as 0
Queue *createQueue(unsigned capacity)
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = queue->capacity - 1;
	queue->array = (int *)malloc(queue->capacity * sizeof(int));
	return queue;
}

// Queue is full if size becomes equal to the capacity
int isFull(Queue *queue)
{
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(Queue *queue)
{
	return (queue->size == 0);
}

// Gets front of queue
int front(Queue *queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Gets rear of queue
int rear(Queue *queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

// Add an item to the queue, it changes rear and size
void enqueue(Queue *queue, int item)
{
	// Check queue if it is full
	if (isFull(queue))
		return;

	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d is enqueued to queue \n", item);
}

// Remove an item from queue. It changes front and size
int dequeue(Queue *queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	printf("%d is dequeued from queue \n", item);
	return item;
}

int main()
{
	Queue *queue = createQueue(1000);
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);

	dequeue(queue);
	dequeue(queue);
	dequeue(queue);

	getchar();
	return 0;
}