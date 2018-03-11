#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node *left, *right;
};

struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)
		malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

// Find height of the binary tree
int height(Node *root)
{
	if (root == NULL)
		return 0;

	return 1 + max(height(root->left), height(root->right));
}

// Find the diameter (duong kinh) of binary tree
int diameter(Node *tree)
{
	if (tree == NULL)
		return 0;

	// find height of left tree and right tree
	int leftHeight = height(tree->left);
	int rightHeight = height(tree->right);

	// recur to find the diameter of left tree and right tree
	int leftDiameter = diameter(tree->left);
	int rightDiameter = diameter(tree->right);

	// Find max of these 3 cases
	return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

int diameterOptimized(Node *root, int *height)
{
	int leftHeight = 0, rightHeight = 0;
	int leftDiameter = 0, rightDiameter = 0;

	if (root == NULL)
	{
		*height = 0;
		return 0;
	}

	leftDiameter = diameterOptimized(root->left, &leftHeight);
	rightDiameter = diameterOptimized(root->right, &rightHeight);
	*height = max(leftHeight, rightHeight) + 1;

	return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->right = newNode(5);
	root->left->right->right->right = newNode(5);
	

	printf("Diameter of the given binary tree is %d \n", diameter(root));

	int height = 0;
	printf("Diameter of the given binary tree is %d \n", diameterOptimized(root, &height));
	getchar();
	return 0;
}