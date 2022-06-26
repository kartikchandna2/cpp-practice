#include<iostream>
using namespace std;
class BST {
public:
	int data;
	BST* left;
	BST* right;
};
//find the inorder predecessor
BST* inpre(BST* root) {
	//right most element of the left sub tree

	root = root->left;
	while (root->right != NULL) {
		root=root->right;
	}
	return root;
}
//delete a node from the tree

BST* deleteNode(BST* root, int data) {
	BST* ipre;
	if (root == NULL) {
		return NULL;
	}

	//first search for the element
	if (data < root->data) {
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = deleteNode(root->right, data);
	}
	else {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		else if (root->left == NULL) {
			BST* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL) {
			BST* temp = root->left;
			free(root);
			return temp;
		}
		ipre = inpre(root);
		root->data = ipre->data;
		root->left = deleteNode(root->left, ipre->data);
	}
	return root;

}
//create node

BST* createNode(int data) {
	BST* node = new BST();
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return node;
}
//insert noode to an existing tree

void insert(BST* node, int data) {
	BST* prev = NULL;
	while (node != NULL) {
		prev = node;
		if (node->data == data) {
			cout << "cannot add element" << endl;
			return;
		}
		if (node->data < data) {
			node = node->right;
		}
		else {
			node = node->left;
		}
	}
	BST* post = createNode(data);
	if (prev->data < data) {
		prev->right = post;
	}
	else {
		prev->left = post;
	}
}
//inorder traversal

void inorder(BST* node) {
	if (node != NULL) {
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}
}
int main() {
	BST* node1 = createNode(20);
	BST* node2 = createNode(30);
	BST* node3 = createNode(40);
	BST* node4 = createNode(50);
	BST* node5 = createNode(60);
	node4->right = node5;
	node4->left = node2;
	node2->left = node1;
	node2 ->right = node3;
	/*
			50
		   /  \
	      30   60
		 /  \
		20   40	
	*/

	inorder(node4);
	cout << endl;
	insert(node4, 45);
	inorder(node4);
	cout << endl;
	insert(node4, 20);
	/*
			50
		   /  \
		  30   60
		 /  \
		20   40
			  \
			   45
	*/
	deleteNode(node4, 30);
	cout << endl;
	inorder(node4);
}