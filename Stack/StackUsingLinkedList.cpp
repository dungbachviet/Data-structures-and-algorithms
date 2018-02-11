#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct StackNode
{
	int data;
	StackNode *next;
};

// Create a new node
StackNode *newNode(int new_data)
{
	StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
	new_node->data = new_data;
	new_node->next = NULL;
	return new_node;
}

// Check whether or not stack is empty
int isEmpty(StackNode *root)
{
	return !root;
}

// Push a new node to stack
void push(StackNode **root, int data)
{
	StackNode *new_node = newNode(data);
	new_node->next = (*root);
	(*root) = new_node;
	printf("%d pushed to stack \n", data);
}

// Pop one node from stack
int pop(StackNode **root)
{
	if (isEmpty(*root))
		return INT_MIN;

	StackNode *popped_node = *root;
	int item = popped_node->data;
	(*root) = (*root)->next;
	free(popped_node);

	return item;
}

// Return top node of stack
int peek(StackNode *root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}


int main()
{
	StackNode *root = NULL;

	push(&root, 1);
	push(&root, 2);
	push(&root, 3);
	push(&root, 4);

	printf("\n %d is popped from stack", pop(&root));
	printf("\n %d is popped from stack", pop(&root));

	getchar();
	return 0;
}