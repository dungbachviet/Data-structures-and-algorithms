#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100

struct stack
{
	int top;
	int items[STACKSIZE];
};

void push(struct stack *ps, int x)
{
	if (ps->top == STACKSIZE - 1)
	{
		printf("Error : Stack Overflow");
		getchar();
		exit(0);
	}
	else
	{
		ps->items[++(ps->top)] = x;
	}
}

bool isEmpty(struct stack *ps)
{
	return (ps->top == -1) ? true : false;
}

int pop(struct stack *ps)
{
	if (ps->top == -1)
	{
		printf("Error : Stack Underflow \n");
		getchar();
		exit(0);
	}
	else
	{
		return ps->items[(ps->top)--];
	}
}

// Display NGE of each element in array
void printNGE(int arr[], int n)
{
	// Create a new stack
	struct stack s;
	s.top = -1;

	// push the first element of array to stack
	push(&s, arr[0]);

	// iterate for rest of the elements
	int element, next;
	for (int i = 1; i < n; i++)
	{
		next = arr[i];

		if (isEmpty(&s) == false)
		{
			element = pop(&s);

			// Print out elements in stack that less than next
			while (element < next)
			{
				printf("\n %d  --> %d", element, next);
				if (isEmpty(&s) == true)
					break;

				element = pop(&s);
			}

			// Push element back to stack if next is not NGE of it
			if (element >= next)
				push(&s, element);
		}

		// Push next to stack
		push(&s, next);
	}

	// After iterating over the loop, the remaining elements in stack do not have the next greater elements, so print -1 for them
	while (isEmpty(&s) == false)
	{
		printf("\n %d --> %d ", pop(&s), -1);
	}
}


void printNGE_TwoFor(int arr[], int n)
{
	int next;
	for (int i = 0; i < n; i++)
	{
		next = -1;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				next = arr[j];
				break;
			}
		}

		printf("\n %d --> %d ", arr[i], next);
	}
		
	
}

int main()
{

	int arr[] = { 11, 13, 21, 21, 21 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("\n Find NGE using Stack : \n");
	printNGE(arr, n);

	printf("\n\n Find NGE using 2 For : \n");
	printNGE_TwoFor(arr, n);

	getchar();
	return 0;
}