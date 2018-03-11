#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX_Q_SIZE 500

using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node **createQueue(int *front, int *rear)
{
	Node **queue = (Node **)malloc(sizeof(Node *) * MAX_Q_SIZE);

	(*front) = (*rear) = 0;
	return queue;
}

void enQueue(Node **queue, int *rear, Node *new_node)
{
	queue[*rear] = new_node;
	//(*rear) = (*rear + 1) % MAX_Q_SIZE;
	(*rear)++;
}

Node *deQueue(Node **queue, int *front, int *rear)
{
	// When queu is empty
	if (*front >= *rear)
		return NULL;
	int temp = *front;
	*front = (*front + 1) % MAX_Q_SIZE;
	return queue[temp];

}

struct Node* newNode(int data)
{
	struct Node* node = (Node *)
		malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

void printLevelOrder(Node *root)
{
	int rear, front;
	Node **queue = createQueue(&front, &rear);
	Node *temp_node = root;

	while (temp_node)
	{
		printf("%d ", temp_node->data);
		if (temp_node->left)
			enQueue(queue, &rear, temp_node->left);

		if (temp_node->right)
			enQueue(queue, &rear, temp_node->right);

		temp_node = deQueue(queue, &front, &rear);
		
		
	}

}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Level Order traversal of binary tree is : ");
	printLevelOrder(root);

	getchar();
	return 0;
}




