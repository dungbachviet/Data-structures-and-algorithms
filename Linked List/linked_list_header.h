// 2 Dòng đầu tiên và dòng cuối cùng trong file header này có vai trò : Phát hiện header này có bị include nhiều lần trong 1 file.cpp nào đó hay không? Giả sử trong file InsertNode.cpp, nếu ta include nhiều lần cùng một thư viện linked_list_header.h : trong trường hợp không có 2 dòng này thì trình biên dịch sẽ báo lỗi khi chạy chương trình; Trường hợp ngược lại, khi có thêm 2 dòng này (và 1 dòng cuối) compiler sẽ có thể phát hiện được như sau : ở lần include đầu tiên, nó sẽ include header đó thật, nhưng nếu sau đó lại gặp một lệnh include một header đã include trước đó thì nó sẽ không include nữa ==> Hiểu đơn giản như vậy ==> Nên chương trình sẽ không còn báo lỗi

#ifndef DUNGBV 
#define DUNGBV
// Ta có thể thay 2 lệnh trên và 1 lệnh cuối file = duy nhất 1 lệnh ở đây : #pragma once (chức năng tương tự, tức giúp ta chỉ include 1 header được tối đa 1 lần)
#include<stdio.h>
#include<stdlib.h>

extern int x; // declare global variable for any file including header "linked_list_header.h"
			  // Need to definition this variable in file linked_list_header.cpp (ex : int x = 500;)
			  // Khai biến trong file header giúp cho những file import thư viện này có thể sử dụng chung biến này !!!

struct Node
{
	int data;
	struct Node *next;
};

// Insert a new node on the front of the list
void insertHead(struct Node** head_addr, int new_data);

// Insert a new node after a given node
void insertAfter(struct Node* prev_node, int new_data);

// Insert a new node at tail of linked list
void insertTail(struct Node** head_addr, int new_data);

// Prints contents of linked list starting from any node to the tail of that linked list
void printList(struct Node* node);

// Deletes the first of occurrence of key in linked list
void deleteNode(struct Node **head_addr, int key);

// Deletes a node at given position (a position starts from 0 to n-1)
void deleteNodeAtPosition(struct Node **head_addr, int position);

// Get count of linked list
int getCount(struct Node *head);

// Get count of linked list using Recursive (dùng đệ quy)
int getCountRecursive(struct Node *head);

// Swap nodes x and y in linked list by changing link (consumes : each note's data is different)
void swapNodes(struct Node** head_addr, int x, int y);

// Swap 2 pointers using reference (not using 2-level pointers)
void swap(struct Node*& a, struct Node*& b);

// Swap optimally nodes x and y in linked list by changing link
void swapNodesOptimal(struct Node **head_addr, int x, int y);

// Reverse the linked list (Đảo ngược linked list)
void reverse(struct Node **head_addr);

// Reverse recursively the linked list (Đảo ngược sử dụng Đệ quy)
void recursiveReverse(struct Node **head_addr);

// Reverse the linked list using tail recursion (Đảo ngược sử dụng đệ quy đuôi)
void tailRecursiveReverse(Node *curr, Node *prev, Node **head);

// Function calls to tailRecursiveReverse(...)
void tailReverse(Node **head);



#endif
