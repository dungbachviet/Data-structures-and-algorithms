#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	Node *left, *right;
};

Node *newNode(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printGivenLevel(Node *root, int level);
int height(Node *node);
void printLevelOrder(Node *root);

// Find the height of binary tree
int height(Node *node)
{
	if (node == NULL)
		return 0;
	else
	{
		// compute the height of each subtree
		int lheight = height(node->left);
		int rheight = height(node->right);
		
		// use height of larger subtree, then add 1 
		if (lheight > rheight)
			return lheight + 1;
		else 
			return (rheight + 1);
	}
}

// Print nodes at a given level
void printGivenLevel(Node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

// Print Level Order Traversal a tree
void printLevelOrder(Node *root)
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
		printGivenLevel(root, i);
}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Level Order Traversal of Binary Tree : ");
	printLevelOrder(root);

	getchar();
	return 0;
}