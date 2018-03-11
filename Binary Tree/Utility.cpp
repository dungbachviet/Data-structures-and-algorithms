#include <stdio.h>
#include <stdlib.h>

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

// Find the size of the binary tree
int size(Node *root)
{
	if (root == NULL)
		return 0;
	else
		return (size(root->left) + 1 + size(root->right));
}

// Find the max element in the tree
int findMax(Node *root)
{

	if (root == NULL)
		return INT_MIN;

	int res = root->data;
	int lres = findMax(root->left);
	int rres = findMax(root->right);

	if (res < lres)
		res = lres;
	if (res < rres)
		res = rres;

	return res;
}

// Print the left view of binary tree
void leftViewUtil(Node *root, int level, int *max_level)
{
	if (root == NULL)
		return;
	if (*max_level < level)
	{
		printf("%d ", root->data);
		*max_level = level;
	}

	leftViewUtil(root->left, level + 1, max_level);
	leftViewUtil(root->right, level + 1, max_level);
}

// Function to call the function leftViewUtil(...)
void leftView(Node *root)
{
	int max_level = 0;
	leftViewUtil(root, 1, &max_level);
}


int main()
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("\nNumber of nodes in binary tree : %d", size(root)); // 5

	printf("\n Find Max : %d", findMax(root)); // 5
	
	printf("\n Left View : ");
	leftView(root);

	getchar();
	return 0;
}
