#include<iostream>
using namespace std;
class Stack {
public:
	int top;
	int size;
	int* arr;
};
int isEmpty(Stack* s) {
	if (s->top == -1) {
		cout << "Stack Underflow" << endl;
		return 1;
	}
	else {
		return 0;
	}
}
int isFull(Stack* s) {
	if (s->top == s->size-1) {
		cout << "Stack overflow" << endl;
		return 1;
	}
	else {
		return 0;
	}
	
}
void push(int x, Stack* s) {
	if(!isFull(s)){
		s->top++;
		s->arr[s->top] = x;
		cout << x << " has been added to the stack" << endl;
	}

}
void pop(Stack* s) {
	if (!isEmpty(s)) {
		cout << s->arr[s->top] << " has been removed from the stack" << endl;
		s->top--;
	}
}
int main()
{
	Stack* s = new Stack();
	s->top = -1;
	s->size = 4;
	s->arr = new int(s->size);
	push(20, s);
	push(30, s);
	push(40, s);
	push(50, s);
	push(60, s);
	cout << s->top << endl;
	pop(s);
	pop(s);
	pop(s);
	pop(s);
	pop(s);
}