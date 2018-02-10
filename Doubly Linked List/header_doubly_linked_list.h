#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *right;
	struct Node *left;
};


// Insert a new node at head of doubly linked list
void insertHead(Node **head_addr, int new_data);

// Insert a new node after a given node
void insertAfter(Node *prev_node, int new_data);

// Insert a new node at last of doubly linked list
void insertLast(Node **head_addr, int new_data);

// Insert a new node before a given node
void insertBefore(Node **head_addr, Node *after_node, int new_data);

// Display the doubly linked list
void printList(Node *head);

// Deletes the given node
void deleteNode(Node **head_addr, Node *deleted_node);

// Reverse doubly linked list
void reverse(Node **head_addr);

// Gather leftList and rightList into a new doubly circle list
Node *concatenate(Node *leftList, Node *rightList);

// Convert from Binary Tree to Doubly Circle List
Node *BinaryTreeToCircleList(Node *root);

// Display the doubly circle list
void DisplayDoublyCircleList(Node *head);

// Create a new node
Node *newNode(int data);

// swap two elements
void swap(int *a, int *b);

// Find last node of doubly linked list
Node *lastNode(Node *head);

// Considers last element as pivot
Node *partition(Node *left, Node *right);

// Wrapper function to call main function of quickSort
void callQuickSort(Node *head);

// Sort linked list using Quick Sort algorithm
void quickSort(Node *left, Node *right);

// Split a list into 2 half of list
Node *split(Node *head);

// Merge two orderd lists into one ordered list
Node *merge(Node *first, Node *second);

// Sort list increasingly using Merge Sort algorithm
Node *mergeSort(Node *head);
