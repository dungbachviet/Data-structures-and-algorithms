// C program to sort a stack using recursion
#include <stdio.h>
#include <stdlib.h>

// Stack is represented using linked list
struct stack
{
	int data;
	struct stack *next;
};

// Utility function to initialize stack
void initStack(struct stack **s)
{
	*s = NULL;
}

// Utility function to check if stack is empty
int isEmpty(struct stack *s)
{
	if (s == NULL)
		return 1;
	return 0;
}

// Utility function to push an item to stack
void push(struct stack **s, int x)
{
	// create new node
	struct stack *p = (struct stack *)malloc(sizeof(struct stack));

	if (p == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		return;
	}

	p->data = x;
	p->next = *s;
	*s = p;
}

// Utility function to remove an item from stack
int pop(struct stack **s)
{
	int x;
	struct stack *temp;

	x = (*s)->data;
	temp = *s;
	(*s) = (*s)->next;
	free(temp);

	return x;
}

// Function to find top item
int top(struct stack *s)
{
	return (s->data);
}

// Utility function to print contents of stack
void printStack(struct stack *s)
{
	while (s)
	{
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}

void sortedInsert(struct stack **s, int x)
{
	// Sorted increasingly
	if (isEmpty(*s) || x < top(*s))
	{
		push(s, x);
		return;
	}

	// If top is greater x, remove the top item and recur
	int temp = pop(s);
	sortedInsert(s, x);

	// Put back the top item removed ealier
	push(s, temp);

}

// Sort stack
void sortStack(struct stack **s)
{
	if (!isEmpty(*s))
	{
		// Remove the top item
		int x = pop(s);

		// Sort remaining stack (conquers child problem)
		sortStack(s);

		// Push the top item back in sorted stack
		sortedInsert(s, x);
	}
}


int main()
{
	struct stack *top;
	initStack(&top);

	push(&top, 30);
	push(&top, -5);
	push(&top, -5);
	push(&top, 18);
	push(&top, 14);
	push(&top, -3);

	printf("Stack elements before sorting : \n");
	printStack(top);

	sortStack(&top);
	printf("\n\n");

	printf("Stack elements after sorting : \n");
	printStack(top);




	getchar();
	return 0;
}