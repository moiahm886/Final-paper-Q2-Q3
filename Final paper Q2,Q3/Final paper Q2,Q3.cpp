#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* right;
	Node* left;
};
Node* NewNode(Node* root, int val)
{
	Node* newnode = new Node();
	newnode->data = val;
	newnode->left = newnode->right = NULL;
	return newnode;
}
Node * minimum(Node* root)
{
	if (root == NULL)return root;
	for (root; root->left == NULL; root = root->left)
	{
		if (root->left == NULL)
		{
			return root;
		}
	}
}
Node* insertion(Node* root, int val)
{
	if (root == NULL)return NewNode(root,val);
	if(val>0)
	{
		if (root->data > val)
		{
			root->left = insertion(root->left, val);
		}
		else if (root->data < val)
		{
			root->right = insertion(root->right, val);
		}
		else
		{
			cout << "Duplication not allowed\n";
		}
	}
	return root;
}
Node* deletion(Node* root,int val)
{
	if (root == NULL)
	{
		return root;
	}
	if (val < root->data)
	{
		root->left = deletion(root->left, val);
	}
	else if (val > root->data)
	{
		root->right = deletion(root->right, val);
	}
	else
	{
		if (root->right == NULL && root->left == NULL)
		{
			return NULL;
		}
		else if (root->right == NULL)
		{
			Node* temp = root->left;
			free(root);
			return temp;
		}
		else if(root->left == NULL)
		{
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else
		{
			Node* temp = minimum(root->right);
			root->data = temp->data;
			root->right = deletion(root->right, temp->data);

		}
	}
	return root;
}
bool search(Node* root, int val)
{
	if (root == NULL)return false;
	search(root->left,val);
	if (root->data == val)
	{
		return true;
	}
	search(root->left, val);
}
void inorder(Node* root)
{
	if (root == NULL)return;
	inorder(root->left);
	cout << root->data << "\t";
	inorder(root->right);
}
void displayless(Node* root, int val)
{
	if (root == NULL)return;
	if (!search(root, val))
	{
		displayless(root->left, val);
		if (root->data < val)
		{
			cout << root->data << "\t";
		}
		displayless(root->right, val);
	}
	else
	{
		cout << "Number already exists\n";
	}
}
int main()
{
	Node* root = NULL;
	int number = 0;
	inorder(root);
	do
	{
		cout << "Enter Number\n";
		cin >> number;
		root = insertion(root, number);
	} while (number > 0);
	inorder(root);
	cout << endl;
	if (search(root, 34))
	{
		cout << "found\n";
	}
	root=deletion(root, 1);
	displayless(root, 7);
	inorder(root);
}