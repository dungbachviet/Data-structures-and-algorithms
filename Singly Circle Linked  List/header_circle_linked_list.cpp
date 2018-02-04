#include "header_circle_linked_list.h"

// Add a new node to an empty circle linked list
Node *addToEmptyList(Node *last, int data)
{
	// if list is not empty, nothing to do
	if (last != NULL) return last;

	// create new node
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;

	// points to itself
	temp->next = temp;

	return temp;
}

// Add a new node to first of the circle linked list
Node *addFirst(Node *last, int data)
{
	// When list is empty
	if (last == NULL)
		return addToEmptyList(last, data);

	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->next = last->next;
	last->next = temp;

	return last;
}

// Add a new node to last of the circle linked list
Node *addLast(Node *last, int data)
{
	if (last == NULL)
		return addToEmptyList(last, data);

	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->next = last->next;
	last->next = temp;
	last = temp;

	return last;
}

// Add a new node to after of the node having value of item
Node *addAfter(Node *last, int data, int item)
{
	if (last == NULL) return NULL;

	Node *temp = last, *new_node = NULL;
	do 
	{	
		temp = temp->next;
		if (temp->data == item)
		{
			new_node = (Node *)malloc(sizeof(Node));
			new_node->data = data;
			new_node->next = temp->next;
			temp->next = new_node;

			// If last holds item
			if (temp == last)
				last = new_node;

			return last;
		}

	} while (temp != last);

	printf("\n Item is not present in circle linked list");
	return last;
}

// Print singly circle linked list with last node
void printCircleListWithLastNode(Node *last)
{
	// Empty list
	if (last == NULL) return;

	Node *temp = last;
	do
	{
		temp = temp->next;
		printf(" %d ", temp->data);
	} while (temp != last);

}

// Print singly circle linked list with first node
void printCircleListWithFirstNode(Node *head)
{
	// Empty list
	if (head == NULL) return;

	Node *temp = head;
	do
	{
		printf(" %d ", temp->data);
		temp = temp->next;
	} while (temp != head);
}

// Push a new node at head of circle list 
void push(Node **head_addr, int data)
{
	// Create new node
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;

	Node *temp = *head_addr;

	// If list is not empty
	if ((*head_addr) != NULL)
	{
		while (temp->next != *head_addr)
			temp = temp->next;

		new_node->next = temp->next;
		temp->next = new_node;
	}
	else // Else list is empty
		new_node->next = new_node;

	(*head_addr) = new_node; // Change head of list
}

// Split a circle list into 2 half of original list; head1_addr, head2_addr points to head of these half lists
void splitCircleList(Node *head, Node **head1_addr, Node **head2_addr)
{
	// If circle list is empty
	if (head == NULL) return;

	// Using fast_ptr goes faster two time than slow_ptr does 
	Node *fast_ptr = head, *slow_ptr = head;
	while (fast_ptr->next != head && fast_ptr->next->next != head)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}

	// If number of list is even (chẵn), faster_ptr is still not at last of list
	if (fast_ptr->next->next == head)
		fast_ptr = fast_ptr->next; // last of circle list

	// Set the head pointer of first half (thiết lập con trỏ head cho nửa list thứ nhất)
	(*head1_addr) = head;

	// Set the head pointer of second half if number of list must more than 2 nodes
	if (head->next != head)
		(*head2_addr) = slow_ptr->next;

	// Make second half circle
	fast_ptr->next = slow_ptr->next;

	// Make first half circle
	slow_ptr->next = head;

}

// Insert a new node in a linked list in sorted way
void sortedInsert(Node **head_addr, Node *new_node)
{
	Node *current = (*head_addr);

	// Case 1 : circle list is empty
	if (current == NULL)
	{
		new_node->next = new_node;
		(*head_addr) = new_node;
	}
	// Case 2 : new_node must be head of list
	else if (current->data >= new_node->data) 
	{ 
		// Find the last of cirle list
		while (current->next != *head_addr)
			current = current->next;

		new_node->next = *head_addr;
		current->next = new_node;
		(*head_addr) = new_node;
	}
	// Case 3 : new_node must be inserted at somewhere after head
	else 
	{
		// Locate the node before the point of insertion
		while (current->next != (*head_addr) && current->next->data < new_node->data)
			current = current->next;

		new_node->next = current->next;
		current->next = new_node;
	}
}