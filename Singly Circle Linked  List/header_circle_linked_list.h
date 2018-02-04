#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

// Add a new node to an empty circle linked list
Node *addToEmptyList(Node *last, int data);

// Add a new node to first of the circle linked list
Node *addFirst(Node *last, int data);

// Add a new node to last of the circle linked list
Node *addLast(Node *last, int data);

// Add a new node to after of the node having value of item
Node *addAfter(Node *last, int data, int item);

// Print singly circle linked list with last node
void printCircleListWithLastNode(Node *last);

// Print singly circle linked list with first node
void printCircleListWithFirstNode(Node *head);

// Push a new node at head of circle list 
void push(Node **head_addr, int data);

// Split a circle list into 2 half of original list; head1_addr, head2_addr points to head of these half lists
void splitCircleList(Node *head, Node **head1_addr, Node **head2_addr);

// Insert a new node in a linked list in sorted way
void sortedInsert(Node **head_addr, Node *new_node);