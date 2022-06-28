#include<iostream>
using namespace std;
class AVL {
public:
	int data;
	int height;
	AVL* left;
	AVL* right;
};
AVL* createNode(int key) {
	AVL* node = new AVL();
	node->data = key;
	node->height = 1;
	node->right = NULL;
	node->left = NULL;
	return node;
}
int getHeight(AVL* node) {
	if (node == NULL) {
		return 0;
	}
	return node->height;
}
int getBalanceFactor(AVL* node) {
	if (node == NULL) {
		return 0;
	}
	return getHeight(node->left) - getHeight(node->right);
}
int max(int a, int b) {
	return a > b ? a : b;
}
AVL* rightRotate(AVL* y) {
	AVL* x = y->left;
	AVL* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	return x;
}
AVL* leftRotate(AVL* x) {
	AVL* y = x->right;
	AVL* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(getHeight(x->left), getHeight(x->right))+1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

	return y;
}
AVL* insert(AVL* node, int key) {
	if (node == NULL) {
		return createNode(key);
	}
	if (node->data > key) {
		node->left = insert(node->left, key);
	}
	else if (node->data < key) {
		node->right = insert(node->right, key);
	}
	else {
		return node;
	}
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

	int bf = getBalanceFactor(node);

	if (bf > 1 && key < node->left->data) {
		return rightRotate(node);
	}
	if (bf<-1 && key>node->right->data) {
		return leftRotate(node);
	}
	if (bf > 1 && key > node->left->data) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (bf < -1 && key < node->right->data) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
void preorder(AVL* node) {
	if (node != NULL) {
		cout << node->data << " ";
		preorder(node->left);
		preorder(node->right);
	}
}

int main() {
	AVL* root = NULL;
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);
	preorder(root);

}