#include <stdlib.h>
#include <stdio.h>


// A linked list node to store a queue entry
struct QNode
{
	int key;
	struct QNode *next;
};


// Queue for managing front and rear of queue
struct Queue
{
	// point to front and rear of queue
	struct QNode *front, *rear;
};

// Create a new node
QNode *newNode(int key)
{
	QNode *new_node = (QNode *)malloc(sizeof(QNode));
	new_node->key = key;
	new_node->next = NULL;
	return new_node;
}

// Create an empty queue
Queue *createQueue()
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue->front = queue->rear = NULL;
	return queue;
}


// Add a key to queue
void enQueue(Queue *queue, int key)
{
	// Create a new node
	QNode *new_node = newNode(key);

	// Check if queue is empty
	if ((queue->rear) == NULL)
	{
		queue->front = queue->rear = new_node;
		printf("%d is enqueued to queue \n", key);
		return;
	}

	// Add the new node to the end of queue and change rear
	queue->rear->next = new_node;
	queue->rear = new_node;

	printf("%d is enqueued to queue \n", key);
}

// Remove a key from given queue
QNode *deQueue(Queue *queue)
{
	// If queue is empty
	if (queue->front == NULL)
		return NULL;

	QNode *temp = queue->front;
	queue->front = queue->front->next;
	temp->next = NULL;

	if (queue->front == NULL)
		queue->rear = NULL;

	printf("%d is dequeued from queue \n", temp->key);
	return temp;
}

int main()
{
	Queue *queue = createQueue();

	enQueue(queue, 1);
	enQueue(queue, 2);
	enQueue(queue, 3);
	enQueue(queue, 4);

	printf("\n");
	deQueue(queue);
	deQueue(queue);


	getchar();
	return 0;
}
