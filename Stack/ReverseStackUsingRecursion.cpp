// C program to reverse a stack using recursion
#include<stdio.h>
#include<stdlib.h>
#define bool int

/* structure of a stack node */
struct sNode
{
	char data;
	struct sNode *next;
};

/* Function Prototypes */
void push(struct sNode** top_ref, int new_data);
int pop(struct sNode** top_ref);
bool isEmpty(struct sNode* top);
void print(struct sNode* top);

void insertAtBottom(struct sNode **top_ref, int item)
{
	if (isEmpty(*top_ref))
		push(top_ref, item);
	else
	{
		// Pop out the top element of stack
		int top = pop(top_ref);

		// Wait until meeting base case to insert item to bottom of stack
		insertAtBottom(top_ref, item);

		// Push the top element back to stack after item inserted at bottom of stack
		push(top_ref, top);
	}
}

void reverse(struct sNode **top_ref)
{
	if (!isEmpty(*top_ref))
	{
		// Get top of stack
		int top = pop(top_ref);

		// Reverse for child problem
		reverse(top_ref);

		// Insert top element at bottom of reversed child stack
		insertAtBottom(top_ref, top);
	}
}

int main()
{

	struct sNode *s = NULL;
	push(&s, 4);
	push(&s, 3);
	push(&s, 2);
	push(&s, 1);

	printf("\n Original Stack : ");
	print(s);
	reverse(&s);
	printf("\n Reversed Stack : ");
	print(s);

	

	getchar();
	return 0;
}






/* Function to check if the stack is empty */
bool isEmpty(struct sNode* top)
{
	return (top == NULL) ? 1 : 0;
}

/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data)
{
	/* allocate node */
	struct sNode* new_node =
		(struct sNode*) malloc(sizeof(struct sNode));

	if (new_node == NULL)
	{
		printf("Stack overflow \n");
		exit(0);
	}

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*top_ref);

	/* move the head to point to the new node */
	(*top_ref) = new_node;
}

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
	char res;
	struct sNode *top;

	/*If stack is empty then error */
	if (*top_ref == NULL)
	{
		printf("Stack overflow \n");
		exit(0);
	}
	else
	{
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

/* Functrion to pront a linked list */
void print(struct sNode* top)
{
	printf("\n");
	while (top != NULL)
	{
		printf(" %d ", top->data);
		top = top->next;
	}
}