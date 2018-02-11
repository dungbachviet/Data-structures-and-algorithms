#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack type
struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

// Stack Operations
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	// Check if stack is allocated successfully
	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->array = (int*)malloc(stack->capacity * sizeof(int));

	// Check if array is allocated successfully
	if (!stack->array)
		return NULL;
	return stack;
}

// Check whether or not stack is empty
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

// Return top of stack
char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

// Pop top of node out of stack
char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}

// Push new item to stack
void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

// A utility function to check if given character is operand
int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
	switch (ch)
	{
	case '+' :
	case '-' :
		return 1;
		
	case '*' :
	case '/' : 
		return 2;

	case '^' :
		return 3;
	}

	return -1;
}

// if both pred1 and pred2 are operator ^
int isRightToLeft(int pred1, int pred2)
{
	return (pred1 == pred2) && (pred1 == 3);
}

int infixToPostfix(char *expression)
{
	int i, k;

	// Create new stack
	Stack *stack = createStack(strlen(expression));

	// Check if stack is allocated successfully
	if (stack == NULL)
		return -1;

	for (i = 0, k = -1; expression[i]; i++)
	{
		// If character is operand, output it
		if (isOperand(expression[i]))
			expression[++k] = expression[i];
		
		// If character is '(', push it to stack
		else if (expression[i] == '(')
			push(stack, expression[i]);

		// If character is ')', pop stack until meet '('
		else if (expression[i] == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				expression[++k] = pop(stack);
			
			// If stack is empty or character is '('
			pop(stack);
		}
		else
		{
			while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)))
			{
				if (isRightToLeft(precedence(expression[i]), precedence(peek(stack))))
					break;
				else
					expression[++k] = pop(stack);
			}

			push(stack, expression[i]);
		}
	}

	// Get remaining characters out of stack
	while (!isEmpty(stack))
		expression[++k] = pop(stack);

	expression[++k] = '\0';
	printf("%s \n", expression);

	return 1;
}

// Check if ch is a number
int isDigit(char ch)
{
	return (ch >= '0') && (ch <= '9');
}

int evaluatePostfix(char *postfixExp)
{
	Stack *stack = createStack(strlen(postfixExp));

	// See if stack was created successfully
	if (!stack)
		return -1;

	for (int i = 0; postfixExp[i]; i++)
	{
		// If character is number, push it into stack
		if (isDigit(postfixExp[i]))
			push(stack, postfixExp[i] - '0');

		else // Else character is a operator, gets two of operands and calculates it
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (postfixExp[i])
			{
			case '+': push(stack, val2 + val1); break;
			case '-': push(stack, val2 - val1); break;
			case '*': push(stack, val2 * val1); break;
			case '/': push(stack, val2 / val1); break;
			}
		}
	}

	return pop(stack);
}

void reverseUsingStack(char str[])
{
	// Create a stack of capacity equal to length of string
	int n = strlen(str);
	Stack *stack = createStack(n);

	// Push all characters of string to stack
	for (int i = 0; i < n; i++)
		push(stack, str[i]);

	// Pop all characters of string and put them back to str
	for (int i = 0; i < n; i++)
		str[i] = pop(stack);
}

void swap(char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

void reverse(char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n / 2; i++)
		swap(&str[i], &str[n - 1 - i]);
}



int main()
{
	char expression[] = "a+b*(c^d-e)^(f+g*h)-i";
	printf("Test Function infixToPostfix \n");
	infixToPostfix(expression);
	
	
	char postfixExp[] = "231*+9-";
	printf("\n\n Test Function evaluatePostfix : ");
	printf("\n Value of %s is %d", postfixExp, evaluatePostfix(postfixExp));

	printf("\n\n Test function reverse of a string :");
	char myString[] = "i love vietnam";
	printf("\n Original string : %s", myString);
	reverseUsingStack(myString);
	//reverse(myString);
	printf("\n Reversed string : %s", myString);

	getchar();
	return 0;
}