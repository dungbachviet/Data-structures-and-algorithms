#include "header_doubly_linked_list.h"

// Insert a new node at head of doubly linked list
void insertHead(Node **head_addr, int new_data)
{
	// Allocates memory and initializes value for new node
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = new_data;

	new_node->right = (*head_addr);
	new_node->left = NULL;

	// If list is not empty
	if ((*head_addr) != NULL)
		(*head_addr)->left = new_node;

	//  Change head of list
	(*head_addr) = new_node;
	
}

// Insert a new node after a given node
void insertAfter(Node *prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		printf("\n The given previous node cannot be NULL ");
		return;
	}
	
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = new_data;

	new_node->right = prev_node->right;
	new_node->left = prev_node;
	prev_node->right = new_node;

	if (new_node->right != NULL)
		new_node->right->left = new_node;
}

// Insert a new node at last of doubly linked list
void insertLast(Node **head_addr, int new_data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = new_data;

	// This new node is going to be the last node, so make next of it as NULL
	new_node->right = NULL;

	// If list is empty, new node becomes head of list
	if ((*head_addr) == NULL)
	{
		new_node->left = NULL;
		(*head_addr) = new_node;
		return;
	}

	// Find last node of list
	Node *last = (*head_addr);
	while (last->right != NULL)
		last = last->right;

	new_node->left = last;
	last->right = new_node;
}

// Insert a new node before a given node
void insertBefore(Node **head_addr, Node *after_node, int new_data)
{
	if (after_node == NULL)
	{
		printf("After node cannot be NULL");
		return;
	}

	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = new_data;

	new_node->right = after_node;
	new_node->left = after_node->left;
	after_node->left = new_node;

	// If after_node is head of list, need to change head of list
	if (new_node->left == NULL)
		(*head_addr) = new_node;
	else
		new_node->left->right = new_node;

}

// Display the doubly linked list
void printList(Node *head)
{
	if (head != NULL)
	{
		Node *last_node = NULL;
		
		printf("\n Traversal in forward direction : ");
		while (head != NULL)
		{
			printf("%d ", head->data);
			last_node = head;
			head = head->right;
		}

		printf("\n Traversal in reverse direction : ");

		while (last_node != NULL)
		{
			printf("%d ", last_node->data);
			last_node = last_node->left;
		}

	}
}

// Deletes the given node
void deleteNode(Node **head_addr, Node *deleted_node)
{
	// If list is empty or deleted node does not exist
	if ((*head_addr) == NULL || deleted_node == NULL)
		return;

	// If deleted node is head of list
	if (deleted_node == (*head_addr))
		(*head_addr) = deleted_node->right;

	// If next of deleted node is not be NULL
	if (deleted_node->right != NULL)
		deleted_node->right->left = deleted_node->left;

	// If prior of deleted node is not be NULL
	if (deleted_node->left != NULL)
		deleted_node->left->right = deleted_node->right;

	free(deleted_node);
}

// Reverse doubly linked list
void reverse(Node **head_addr)
{
	Node *current = *head_addr;
	Node *temp = NULL;

	while (current != NULL)
	{
		// Swaps current->prev and current->next
		temp = current->left;
		current->left = current->right;
		current->right = temp;

		// Update status of current
		current = current->left;
	}

	// If list is more than 1 node, change head of list
	if (temp != NULL)
		(*head_addr) = temp->left;
}

// Gather leftList and rightList into a new doubly circle list
Node *concatenate(Node *leftList, Node *rightList)
{
	// If either left list or right list is empty
	if (leftList == NULL)
		return rightList;
	if (rightList == NULL)
		return leftList;

	// Gets last node of each list
	Node *lastLeft = leftList->left, *lastRight = rightList->left;

	// Join last node of left list to head of right list
	lastLeft->right = rightList;
	rightList->left = lastLeft;

	// Join last node of right list to head of left list
	lastRight->right = leftList;
	leftList->left = lastRight;

	return leftList;
}

// Convert from Binary Tree to Doubly Circle List
Node *BinaryTreeToCircleList(Node *root)
{
	// If Binary Tree is empty
	if (root == NULL)
		return NULL;

	// Recursive call for left child tree
	Node *left = BinaryTreeToCircleList(root->left);

	// Recursive call for right child tree
	Node *right = BinaryTreeToCircleList(root->right);
	
	// Make a new doubly circle list of itself 
	root->left = root->right = root;

	// Gather all of doubly circle lists into a new large doubly cirle list 
	return concatenate(concatenate(left, root), right);
}

// Display the doubly circle list
void DisplayDoublyCircleList(Node *head)
{
	if (head != NULL)
	{
		Node *temp = head;
		do
		{
			cout << temp->data << " ";
			temp = temp->right;
		} while (temp != head);
	}
}

// Create a new node
Node *newNode(int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

// swap two elements
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Find last node of doubly linked list
Node *lastNode(Node *head)
{
	// If list is empty
	if (head == NULL) return NULL;

	Node *last = head;
	while (last->right != NULL)
		last = last->right;

	return last;
}

// Considers last element as pivot
Node *partition(Node *l, Node *r)
{
	// Get last element as pivot
	int pivot = r->data;

	Node *i = l->left;
	for (Node *j = l; j != r; j = j->right)
	{
		if (j->data <= pivot)
		{
			i = (i == NULL) ? l : i->right;
			swap(&(i->data), &(j->data));
		}
	}

	i = (i == NULL) ? l : i->right;
	swap(&(i->data), &(r->data));

	return i;
}

// Sort linked list using Quick Sort algorithm
void quickSort(Node *l, Node *r)
{

	if (l != NULL && r != NULL && l != r && l->left != r)
	{
		Node *pivot = partition(l, r);
		quickSort(l, pivot->left);
		quickSort(pivot->right, r);
	}
}

// Wrapper function to call main function of quickSort
void callQuickSort(Node *head)
{
	Node *last = lastNode(head);
	quickSort(head, last);
}

// Split a list into 2 half of list
Node *split(Node *head)
{
	Node *fast = head, *slow = head;
	while (!fast->right && !fast->right->right)
	{
		slow = slow->right;
		fast = fast->right->right;
	}

	// Points to second list
	Node *second = slow->right;

	// last node of first list
	slow->right = NULL;
	return second;
}

// Merge two orderd lists into one ordered list
Node *merge(Node *first, Node *second)
{
	// Either first list or second list is empty
	if (!first)
		return second;
	if (!second)
		return first;

	// Compare two of first nodes in two lists
	if (first->data < second->data)
	{
		first->right = merge(first->right, second);
		first->right->left = first;
		first->left = NULL;
		return first;
	}
	else
	{
		second->right = merge(first, second->right);
		second->right->left = second;
		second->left = NULL;
		return second;
	}

}

// Sort list increasingly using Merge Sort algorithm
Node *mergeSort(Node *head)
{
	// If list has less than 2 nodes
	if (!head || !head->right)
		return head;

	// Split list into 2 half of list
	Node *second = split(head);

	// Recursive merge sort on each half list
	head = mergeSort(head);
	second = mergeSort(second);

	// Merge two orderd list into one ordered list
	return merge(head, second);
}