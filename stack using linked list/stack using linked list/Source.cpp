#include<iostream>
using namespace std;
class LinkedList {
public:
	LinkedList* next;
	int value;
	int count;
};
int isEmpty(LinkedList* top) {
	if (top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
int isFull(LinkedList* top) {
	LinkedList* p = new LinkedList();
	if (p == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
LinkedList* push(LinkedList* top, int value) {
	if (isFull(top)) {
		cout << "Stack Overflow" << endl;
	}
	else {
		LinkedList* first = new LinkedList();
		first->value = value;
		first->next = top;
		top = first;
		return top;
	}

}
int pop(LinkedList** top) {
	if (isEmpty(*top)) {
		cout<<"Stack Underflow"<<endl;
	}
	else {
		LinkedList* n = *top;
		*top = (*top)->next;
		int x = n->value;
		free(n);
		return x;
	}
}
void peek(LinkedList* top, int pos) {
	if (isEmpty(top)) {
		cout << "No elements in stack" << endl;
	}
	else {
		LinkedList* pk = top;
		for (int i = 0; (i < pos-1 && pk!=NULL); i++) {
			pk = pk->next;
		}
		if (pk != NULL) {
			cout << "Element at position " << pos << " of the stack is " << pk->value << endl;
		}
	}
}
void StackTop(LinkedList* top) {
	if (isEmpty(top)) {
		cout << "stack empty" << endl;
	}
	else {
		cout << top->value << endl;
	}
}
void StackBottom(LinkedList* top) {
	if (isEmpty(top)) {
		cout << "stack empty" << endl;
	}
	else {
		for (int i = 0; top->next != NULL; i++) {
			top = top->next;
		}
		cout << top->value << endl;
	}
}
void LinkedListTraversal(LinkedList* top) {
	while (top != NULL) {
		cout << "Element: " << top->value << endl;
		top = top->next;
	}
}
int main()
{
	LinkedList* top = NULL;
	top = push(top, 78);
	top=push(top, 7);
	top = push(top, 8);
	top = push(top, 20);
	int x = pop(&top);
	cout << "popped element is " << x << endl;
	LinkedListTraversal(top);
	peek(top, 2);
	peek(top, 1);
	StackTop(top);
	StackBottom(top);
}