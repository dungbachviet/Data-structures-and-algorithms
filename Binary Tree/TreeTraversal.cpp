#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	return node;
}

// Given a binary tree, print its nodes according to the "bottom-up" postorder traversal
void printPostorder(Node *root)
{
	if (root == NULL)
		return;

	// recur on the left subtree
	printPostorder(root->left);

	// recur on the right subtree
	printPostorder(root->right);

	// print the data of node
	printf("%d ", root->data);
}

// Given a binary tree, print its nodes in inoder
void printInorder(Node *root)
{
	if (root == NULL)
		return;
	
	// recur on the left subtree
	printInorder(root->left);

	// print the data of node
	printf("%d ", root->data);

	// recur on the right tree
	printInorder(root->right);
}

// Given a binary tree, print its nodes in preorder
void printPreorder(Node *root)
{
	if (root == NULL)
		return;

	// prints data of root
	printf("%d ", root->data);

	// recurs on the left subtree
	printPreorder(root->left);

	// recurs on the right subtree
	printPreorder(root->right);
}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("\n Preorder traversal of binary tree is : ");
	printPreorder(root);

	printf("\n Inorder traversal of binary tree is : ");
	printInorder(root);

	printf("\n Postorder traversal of binary tree is : ");
	printPostorder(root);
	

	getchar();
	return 0;
}
