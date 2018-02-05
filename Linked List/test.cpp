#include "linked_list_header.h";


int main() 
{
	struct Node* head = NULL;

	insertHead(&head, 1);
	insertTail(&head, 3);
	insertTail(&head, 4);
	insertAfter(head, 2);
	printList(head); // 1 2 3 4

	deleteNode(&head, 1);
	deleteNode(&head, 2);
	deleteNode(&head, 3);
	printf("\n");
	printList(head); // 4 

	insertTail(&head, 3);
	insertTail(&head, 2);
	insertTail(&head, 1);
	printf("\n");
	printList(head); // 4 3 2 1

	deleteNodeAtPosition(&head, 3); // remove the last node
	printf("\n");
	printList(head); // 4 3 2

	printf("\nNumber of list : %d", getCount(head)); // 3
	printf("\nNumber of list : %d", getCountRecursive(head)); // 3

	insertTail(&head, 1);
	printf("\n");
	printList(head); // 4 3 2 1
	swapNodes(&head, 4, 1);
	printf("\n");
	printList(head); // 1 3 2 4
	swapNodesOptimal(&head, 4, 1); // Optimal function of nodes swap
	printf("\n");
	printList(head); // 4 3 2 1

	reverse(&head);
	printf("\n Reverse : ");
	printList(head); // 1 2 3 4 

	recursiveReverse(&head);
	printf("\n Recursive Reverse : ");
	printList(head); // 4 3 2 1

	tailReverse(&head);
	printf("\n Tail Recursive Reverse : ");
	printList(head); // 1 2 3 4

	Node *a = NULL, *b = NULL;
	insertTail(&a, 1);
	insertTail(&a, 5);
	insertTail(&a, 10);
	insertTail(&a, 15);
	insertTail(&a, 18);

	printf("\n a : ");
	printList(a);

	insertTail(&b, 3);
	insertTail(&b, 4);
	insertTail(&b, 8);
	insertTail(&b, 20);
	insertTail(&b, 25);
	printf("\n b : ");
	printList(b);

	//Node *sortedMergeHead = SortedMerge_DummpyNode(a, b);
	//Node *sortedMergeHead = SortedMerge_ReferenceNode(a, b);
	Node *sortedMergeHead = SortedMerge_Recursive(a, b);
	printf("\n List of sorted merge : ");
	printList(sortedMergeHead);


	Node *head1 = NULL;
	insertTail(&head1, 5);
	insertTail(&head1, 9);
	insertTail(&head1, 1);
	insertTail(&head1, 10);
	insertTail(&head1, 3);
	printf("\n Unsorted List : ");
	printList(head1);
	MergeSort(&head1);
	printf("\n List after sorting : ");
	printList(head1);

	Node *head2 = NULL;
	insertTail(&head2, 1);
	insertTail(&head2, 2);
	insertTail(&head2, 3);
	insertTail(&head2, 4);
	insertTail(&head2, 5);
	insertTail(&head2, 6);
	insertTail(&head2, 7);
	insertTail(&head2, 8);
	printf("\n\n List before reverse : ");
	printList(head2);
	head2 = reverseGroup(head2, 3);
	printf("\n List after reverse each groups of size 3 : ");
	printList(head2);


	getchar();
	return 0;
}



  
