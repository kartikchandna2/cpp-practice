#include<iostream>
using namespace std;
class BST {
public:
	int data;
	BST* left;
	BST* right;
};
BST* createNode(int val) {
	BST* node = new BST();
	node->left = NULL;
	node->right = NULL;
	node->data = val;
	return node;
}
void inorder(BST* p) {
	if (p != NULL) {
		inorder(p->left);
		cout << p->data << " ";
		inorder(p->right);
	}
}
int search(BST* root, int k) {
	if (root != NULL) {
		if (root->data == k) {
			return 1;
		}
		else if (root->data > k) {
			return search(root->left, k);
		}
		else {
			return search(root->right, k);
		}
	}
	else {
		return 0;
	}
}

int iterativeSearch(BST* node, int k) {
	
	while (node != NULL) {
		
		if (node->data == k) {
			return 1;
		}
		else if (node->data < k) {
			node = node->right;
		}
		else {
			node = node->left;
		}
	}
	if (node == NULL) {
		return 0;
	}
}

int isBst(BST* root) {
	static BST* prev = NULL;
	if (root != NULL) {
		if (!isBst(root->left)) {
			return 0;
		}
		if (prev != NULL && root->data <= prev->data) {
			return 0;
		}
		prev = root;
		return isBst(root->right);
	}
	else {
		return 1;
	}
}
int main() {
	BST* p1 = createNode(10);
	BST* p2 = createNode(20);
	BST* p3 = createNode(30);
	BST* p4 = createNode(40);
	BST* p5 = createNode(50);
	/*
			40
		   /  \
		  20  50
		 /  \   
		10  30  	
	*/
	p4->left = p2;
	p4->right = p5;
	p2->left = p1;
	p2->right = p3;
	inorder(p4);
	cout << endl;
	cout << isBst(p4) << endl;
	cout << endl;
	cout << "Looking for 30: "<<search(p4, 30);
	cout << endl;
	cout << "Looking for 35: "<<search(p4, 35);
	cout << endl;
	cout << "Looking for 30: " << iterativeSearch(p4, 30) << endl;
	cout << "Looking for 35: " << iterativeSearch(p4, 35) << endl;
}