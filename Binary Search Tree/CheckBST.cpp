#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// Find max value of BST
int maxValue(Node *root)
{
	if (root == NULL)
		return INT_MIN;
	int temp = root->data;
	int leftMax = maxValue(root->left);
	int rightMax = maxValue(root->right);

	if (temp < leftMax)
		temp = leftMax;
	if (temp < rightMax)
		temp = rightMax;
	return temp;
}

// Find min value of BST
int minValue(Node *root)
{
	if (root == NULL)
		return INT_MAX;
	
	int temp = root->data;
	int leftMin = minValue(root->left);
	int rightMin = minValue(root->right);

	if (temp > leftMin)
		temp = leftMin;
	if (temp > rightMin)
		temp = rightMin;

	return temp;
}

int isBST_1(Node *node)
{
	if (node == NULL)
		return true;

	if (node->left != NULL && maxValue(node->left) > node->data)
		return false;

	if (node->right != NULL && minValue(node->right) < node->data)
		return false;

	if (!isBST_1(node->left) || !isBST_1(node->right))
		return false;

	return true;
}

int isBSTUtil(Node *node, int min, int max)
{
	if (node == NULL)
		return 1;
	
	if (node->data < min || node->data > max)
		return 0;
	return isBSTUtil(node->left, min, node->data - 1) &&
		isBSTUtil(node->right, node->data + 1, max);
}

int isBST_2(Node *node)
{
	return isBSTUtil(node, INT_MIN, INT_MAX);
}

bool isBST_3(Node *root, Node *min = NULL, Node *max = NULL)
{
	if (root == NULL)
		return true;
	if (min != NULL && root->data < min->data)
		return false;

	if (max != NULL && root->data > max->data)
		return false;

	return isBST_3(root->left, min, root) &&
		isBST_3(root->right, root, max);
}

bool isBST_4(Node *root)
{
	static Node *prev = NULL;

	if (root)
	{
		if (!isBST_4(root->left))
			return false;
		if (prev != NULL && root->data <= prev->data)
			return false;
		prev = root;

		return isBST_4(root->right);
	}
}

int main()
{

	Node *root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(3);

	if (isBST_1(root))
		printf("\nIs BST");
	else
		printf("\nNot a BST");

	if (isBST_2(root))
		printf("\nIs BST");
	else
		printf("\nNot a BST");

	if (isBST_3(root))
		printf("\nIs BST");
	else
		printf("\nNot a BST");

	if (isBST_4(root))
		printf("\nIs BST");
	else
		printf("\nNot a BST");

	getchar();
	return 0;
}