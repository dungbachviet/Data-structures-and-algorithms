#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
	char data;
	struct StackNode *next;
};

void push(struct StackNode **top_ref, int new_data)
{
	// Allocate node
	StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));

	// See if new node is allocated
	if (!new_node)
	{
		printf("Stack Overflow\n");
		getchar();
		exit(0);
	}

	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

char pop(StackNode **top_ref)
{
	// See if stack is empty
	if ((*top_ref) == NULL)
	{
		printf("Stack Overflow\n");
		getchar();
		exit(0);
	}
	
	StackNode *temp = (*top_ref);
	char data = temp->data;
	(*top_ref) = temp->next;
	free(temp);

	return data;
}

// Return true if character1 and character2 are matching
int isMatchingPair(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else if (character1 == '[' && character2 == ']')
		return 1;
	else
		return 0;
}

// Check if parenthesises are balanced
int areParenthesisBalanced(char expression[])
{
	// Create head of stack (using linked list)
	StackNode *stack = NULL;

	// Index to traverse all of expression
	int i = 0;

	// Traverse expression
	while (expression[i])
	{
		
		if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
			push(&stack, expression[i]);

			

		else if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')')
		{
			
			if (stack == NULL)
				return 0;
			else if (!isMatchingPair(pop(&stack), expression[i])) 
				return 0;
		
		}

		i++;
	}


	if (stack == NULL)
		return 1;
	else
		return 0;
}

int main() {
	char myTrueExp[] = "{[(({}))]}";
	char myFalseExp[] = "{[(({})}]}";

	printf("\nTrue Expression : %s : %d", myTrueExp, areParenthesisBalanced(myTrueExp));
	printf("\nFalse Expression : %s : %d", myFalseExp, areParenthesisBalanced(myFalseExp));

	getchar();
	return 0;
}