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

	getchar();
	return 0;
}



  