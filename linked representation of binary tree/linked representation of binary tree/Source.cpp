#include<iostream>
using namespace std;
class Tree {
public:
	int x;
	Tree* left;
	Tree* right;
};
Tree* createNode(int data) {
	Tree* n = new Tree();
	n->x = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}
int main() {
	Tree*p = createNode(20);
	Tree* p1 = createNode(30);
	Tree* p2 = createNode(40);
	p->left = p1;
	p->right = p2;
	cout << p->x << " " << (p->left)->x << " " << (p->right)->x << endl;
}