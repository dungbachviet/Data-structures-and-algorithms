#include "header_doubly_linked_list.h"


int main()
{
	Node *head = NULL;
	insertHead(&head, 6);
	insertHead(&head, 5);
	insertHead(&head, 4);
	insertHead(&head, 1);
	printf("\n\n Test Function insertHead :");
	printList(head); // 1 4 5 6 || 6 5 4 1 

	insertAfter(head, 2);
	insertAfter(head->right, 3);
	printf("\n\n Test Function insertAfter :");
	printList(head); // 1 2 3 4 5 6 || 6 5 4 3 2 1

	insertLast(&head, 7);
	insertLast(&head, 8);
	insertLast(&head, 9);
	printf("\n\n Test Function insertLast :");
	printList(head); // 1 2 3 4 5 6 7 8 9 || 9 8 7 6 5 4 3 2 1

	insertBefore(&head, head, 0);
	insertBefore(&head, head, -1);
	insertBefore(&head, head, -2);
	printf("\n\n Test Function insertBefore :"); // -2 -1 1 0 2 3 4 5 6 7 8 9 ||  9 8 7 6 5 4 3 2 0 1 -1 -2
	printList(head);

	deleteNode(&head, head);
	deleteNode(&head, head);
	deleteNode(&head, head);
	printf("\n\n Test Functioni deleteNode : "); // 1 2 3 4 5 6 7 8 9 || 9 8 7 6 5 4 3 2 1
	printList(head);

	reverse(&head);
	printf("\n\n Reverse List : ");
	printList(head);//  9 8 7 6 5 4 3 2 1 ||  1 2 3 4 5 6 7 8 9

	Node *treeRoot = newNode(10);
	treeRoot->left = newNode(5);
	treeRoot->right = newNode(15);
	treeRoot->left->left = newNode(2);
	treeRoot->left->right = newNode(7);
	treeRoot->right->left = newNode(13);

	Node *head1 = BinaryTreeToCircleList(treeRoot);
	printf("\n\n Test Function BinaryTreeToCircleList : ");
	DisplayDoublyCircleList(head1); // 2 5 7 10 13 15 (increasing order)

	Node *head2 = NULL;
	insertHead(&head2, 5);
	insertHead(&head2, 3);
	insertHead(&head2, 10);
	insertHead(&head2, 1);
	insertHead(&head2, 6);
	printf("\n\nTest Quick Sort");
	printf("\n Original List : ");
	printList(head2);
	callQuickSort(head2);
	printf("\n After Quick Sort : ");
	printList(head2);


	Node *head3 = NULL;
	insertHead(&head3, 5);
	insertHead(&head3, 1);
	insertHead(&head3, 10);
	insertHead(&head3, 2);
	insertHead(&head3, 7);
	insertHead(&head3, 4);
	printf("\n\n Test Function MergeSort : ");
	printf("\n Unsorted list  : ");
	printList(head3);
	printf("\n Sorted List : ");
	head3 = mergeSort(head3);
	printList(head3);


	getchar();
	return 0;
}