#include<iostream>
using namespace std;
class Tree {
public:
	int data;
	Tree* left;
	Tree* right;
};
Tree* createNode(int data) {
	Tree* n = new Tree();
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}
void preorder(Tree* n)
{
	if (n != NULL) {
		cout << n->data << " ";
		preorder(n->left);
		preorder(n->right);
	}
}
void postorder(Tree* n) {
	if (n != NULL) {
		postorder(n->left);
		postorder(n->right);
		cout << n->data << " ";
	}
}
void inorder(Tree* n) {
	if (n != NULL) {
		inorder(n->left);
		cout << n->data << " ";
		inorder(n->right);
	}
}
int main() {
	Tree* p = createNode(20);
	Tree* p1 = createNode(25);
	Tree* p2 = createNode(30);
	Tree* p3 = createNode(35);
	Tree* p4 = createNode(40);

	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;
	/*
	      20
         /  \
		25  30
	   /  \
	  35  40

	*/
	cout << "Preorder Traversal: ";
	preorder(p);
	cout << endl;
	cout << "Postorder Traversal: ";
	postorder(p);
	cout << endl;
	cout << "Inorder Traversal: ";
	inorder(p);
}