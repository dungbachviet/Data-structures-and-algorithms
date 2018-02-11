#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Stack
{
	int top;
	unsigned capacity;
	int *array;
};

// Create new stack with given capcity
Stack *createStack(unsigned capacity)
{
	Stack *stack = (Stack *) malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int *) malloc(capacity * sizeof(int));
	return stack;
}

// Check whether or not stack is full
int isFull(Stack *stack)
{
	return stack->top == (stack->capacity - 1);
}

// Check whether or not stack is empty
int isEmpty(Stack *stack)
{
	return stack->top == -1;
}

// Add item to stack
void push(Stack *stack, int item)
{
	// If stack if full
	if (isFull(stack))
		return;
	
	stack->array[++(stack->top)] = item;
	printf("%d pushed in stack \n", item);
}

// Remove an item from stack
int pop(Stack *stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	int item = stack->array[(stack->top)--];
	printf("%d is popped from stack \n", item);
	return item;
}


int main()
{
	Stack *stack = createStack(2);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);
	
	printf("\n");
	pop(stack);
	pop(stack);
	pop(stack);
	getchar();
	return 0;
}