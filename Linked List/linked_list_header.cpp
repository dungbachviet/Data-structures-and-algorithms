#include "linked_list_header.h";

int x = 500; // definition for a variable that declared in header file "linked_list_header.h"

// Insert a new node on the front of the list
void insertHead(struct Node** head_addr, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_addr);
	(*head_addr) = new_node;
}

// Insert a new node after a given node
void insertAfter(struct Node* prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		printf("The given previous node can't be NULL");
		return;
	}

	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

// Insert a new node at tail of linked list
void insertTail(struct Node** head_addr, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_addr == NULL)
	{
		*head_addr = new_node;
		return;
	}

	struct Node* last = *head_addr;
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
}

// Prints contents of linked list starting from any node to the tail of that linked list
void printList(struct Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

// Deletes the first of occurrence of key in linked list
void deleteNode(struct Node **head_addr, int key)
{
	struct Node *temp = *head_addr, *prev = NULL;

	// If head node holds the key to be deleted
	if (temp != NULL && temp->data == key)
	{
		(*head_addr) = (*head_addr)->next;
		free(temp);
		return;
	}

	// Search for the key to be deleted, keep track of the previous node as we need to change "pre->next"
	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	// If key was not present in linked list
	if (temp == NULL) return;

	// Unlink the node from the linked list
	prev->next = temp->next;
	free(temp); // Free memory
}

// Deletes a node at given position (a position starts from 0 to n-1)
void deleteNodeAtPosition(struct Node **head_addr, int position)
{
	struct Node *temp = *head_addr, *prev = NULL;

	// If head's position == 0
	if (temp != NULL && position == 0)
	{
		*head_addr = temp->next;
		free(temp);
		return;
	}

	// Search for position need to be deleted
	int i = 0;
	while (temp != NULL && i < position)
	{
		prev = temp;
		temp = temp->next;
		i++;
	}

	// If position is more than number of nodes in linked list
	if (temp == NULL) return;

	// Unlink the node from the linked list
	prev->next = temp->next;
	free(temp);
}

// Get count of linked list
int getCount(struct Node *head)
{
	int count = 0;
	struct Node *temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return count;
}

// Get count of linked list using Recursive (dùng đệ quy)
int getCountRecursive(struct Node *head)
{
	if (head == NULL) return 0;
	return 1 + getCountRecursive(head->next);
}

// Swap nodes x and y in linked list by changing link (consumes : each note's data is different)
void swapNodes(struct Node** head_addr, int x, int y)
{
	// Nothing to do if x and y are same
	if (x == y) return; 

	// Search for x (keep track of prevX and currX)
	struct Node *prevX = NULL, *currX = *head_addr;
	while (currX && currX->data != x)
	{
		prevX = currX;
		currX = currX->next;
	}

	// Search for y (keep track of prevY and currY)
	struct Node *prevY = NULL, *currY = *head_addr;
	while (currY && currY->data != y)
	{
		prevY = currY;
		currY = currY->next;
	}

	// If either x or y is not present in linked list, nothing to do
	if (currX == NULL || currY == NULL) return;

	// If x is not head of linked list
	if (prevX != NULL)
		prevX->next = currY;
	else // Else make y as new head
		(*head_addr) = currY;

	// If y is not head of linked list
	if (prevY != NULL)
		prevY->next = currX;
	else // Else make x as new head
		(*head_addr) = currX;

	struct Node *temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;

}

// Swap 2 pointers using reference (not using 2-level pointers)
void swap(struct Node*& a, struct Node*& b)
{
	struct Node *temp = a;
	a = b;
	b = temp;
}

// Swap optimally nodes x and y in linked list by changing link
void swapNodesOptimal(struct Node **head_addr, int x, int y)
{
	// Nothing to do if x and y are same
	if (x == y) return;

	// Search x and y in linked list and store their pointer's address in a, b
	struct Node **a = NULL, **b = NULL;
	while (*head_addr != NULL)
	{
		if ((*head_addr)->data == x)
			a = head_addr;
		else if ((*head_addr)->data == y)
			b = head_addr;
		
		// Point to address of next pointer (means : 2-level pointer - con trỏ cấp 2)
		head_addr = &((*head_addr)->next);	
	}

	// If a and b are both present in linked list
	if (a && b)
	{
		swap(*a, *b); // Similar to : prevX->next = currY; prevY->next = currX;
		swap((*a)->next, (*b)->next); // Similar to : temp = currX->next; currX->next = currY->next; currY->next = temp
	}
}

// Reverse the linked list (Đảo ngược linked list)
void reverse(struct Node **head_addr)
{
	Node *prev = NULL, *curr = *head_addr, *next = NULL;

	// Traverse all nodes in linked list
	while (curr != NULL)
	{
		next = curr->next; // Store the next node of current node
		curr->next = prev; // Change the direction of link
		prev = curr; // update prev
		curr = next; // update curr
	}

	// change head of linked list
	(*head_addr) = prev;
}

// Reverse recursively the linked list (Đảo ngược sử dụng Đệ quy)
void recursiveReverse(struct Node **head_addr)
{
	// Store the first and rest of linked list at each time
	Node *first = NULL, *rest = NULL;

	// Empty list
	if ((*head_addr) == NULL) return;

	// 1->2->3->4->NULL : first = 1->2->3->4->NULL, rest = 2->3->4->NULL
	first = *head_addr;
	rest = (*head_addr)->next;

	// Linked list has only one node
	if (rest == NULL) return;

	// Reverse recursively the rest of list and point pointer of rest to the last node of linked list (not first node as when begining)
	recursiveReverse(&rest);

	// Change link from first -> last to first <- last
	first->next->next = first;

	// First node is now changed into last node of linked list
	first->next = NULL;
	
	// Change head of linked list
	(*head_addr) = rest;
}

// Reverse the linked list using tail recursion (Đảo ngược sử dụng đệ quy đuôi)
void tailRecursiveReverse(Node *curr, Node *prev, Node **head_addr)
{
	// If curr is last node, label it to head of linked list
	if (!curr->next)
	{
		*head_addr = curr;
		curr->next = prev;
		return;
	}

	// Store the next node of current node
	Node *next = curr->next;
	
	// Change link into : prev <- curr 
	curr->next = prev;
	tailRecursiveReverse(next, curr, head_addr);
}

// Function calls to tailRecursiveReverse(...)
void tailReverse(Node **head_addr)
{
	if ((*head_addr) == NULL) return;
	tailRecursiveReverse(*head_addr, NULL, head_addr);

}

