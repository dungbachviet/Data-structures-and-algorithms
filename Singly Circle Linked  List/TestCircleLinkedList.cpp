#include "header_circle_linked_list.h"

int main()
{
	Node *last = NULL;
	last = addToEmptyList(last, 1);
	printf("\n Add 1 into empty list : ");
	printCircleListWithLastNode(last); // 1

	last = addFirst(last, 0);
	printf("\n Add 0 at first : ");
	printCircleListWithLastNode(last); // 0 1

	last = addLast(last, 3);
	printf("\n Add 3 at last of cirle list : ");
	printCircleListWithLastNode(last); // 0 1 3

	last = addAfter(last, 2, 1);
	printf("\n Add 2 after node holds data of 1 : ");
	printCircleListWithLastNode(last); // 0 1 2 3
	last = addAfter(last, 4, 3);
	printf("\n Add 4 after node holds data of 3 : ");
	printCircleListWithLastNode(last); // 0 1 2 3 4


	Node *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	printf("\n\n New List : ");
	printCircleListWithFirstNode(head);

	Node *head1 = NULL, *head2 = NULL;
	splitCircleList(head, &head1, &head2);
	printf("\n First circle : ");
	printCircleListWithFirstNode(head1);
	printf("\n Second circle : ");
	printCircleListWithFirstNode(head2);

	Node *head_sorted_list = NULL, *new_node = NULL;
	int data[] = { 5, 7, 10, 9, 8 };
	for (int i = 0; i < 5; i++)
	{
		new_node = (Node *)malloc(sizeof(Node));
		new_node->data = data[i];
		sortedInsert(&head_sorted_list, new_node);
	}
	printf("\n Sorted Circle List : ");
	printCircleListWithFirstNode(head_sorted_list);


	getchar();
	return 0;
}