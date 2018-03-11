#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int key;
	Node *left, *right;
};

Node *newNode(int item)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// Search a node contains of key
Node *search(Node *root, int key)
{
	if (root == NULL || root->key == key)
		return root;

	if (root->key < key)
		return search(root->right, key);
	
	return search(root->left, key);
}

// Insert a new node with key to BST
Node *insert(Node *node, int key)
{
	if (node == NULL) return newNode(key);
	
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}

void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

// Find node of minimum value
Node *minValueNode(Node *node)
{
	Node *current = node;
	while (current->left != NULL)
		current = current->left;

	return current;
}

// Delete node with value of key
Node *deleteNode(Node *root, int key)
{
	if (root == NULL) return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node *temp = root->left;
			free(root);
			return temp;
		}
		Node *temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}

	return root;
}

void findPreSuc(Node *root, Node*& pre, Node*& suc, int key)
{
	if (root == NULL) return;

	if (root->key == key)
	{
		if (root->left != NULL)
		{
			Node *tmp = root->left;
			while (tmp->right)
			{
				tmp = tmp->right;
			}
			pre = tmp;
		}

		if (root->right != NULL)
		{
			Node *tmp = root->right;
			while (tmp->left)
				tmp = tmp->left;
			suc = tmp;
		}
		
		return;
	}

	if (root->key > key)
	{
		suc = root;
		findPreSuc(root->left, pre, suc, key);
	}
	else
	{
		pre = root;
		findPreSuc(root->right, pre, suc, key);
	}
}


int main()
{
	Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	inorder(root);

	printf("\nSearch for key = 60 : %d\n", search(root, 60)->key);

	printf("\nDelete 20\n");
	root = deleteNode(root, 20);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\n\nDelete 70\n");
	root = deleteNode(root, 70);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nMinimum value in BST is : %d", minValueNode(root)->key);

	getchar();
	return 0;
}