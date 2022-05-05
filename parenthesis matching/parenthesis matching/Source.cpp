#include<iostream>
#define MAX 50
using namespace std;

class Stack {
public:
	int size;
	char* arr;
	int top;
};
int isFull(Stack* s) {
	if (s->top == s->size) {
		return 1;
	}
	else {
		return 0;
	}
}
int isEmpty(Stack* s) {
	if (s->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}
void push(Stack* s, char x)
{
	if (isFull(s)) {
		cout << "Stack Overflow" << endl;
	}
	else {
		s->top++;
		s->arr[s->top] == x;
		cout << "Element " << x << " has been added to the stack" << endl;
	}
}
void pop(Stack* s) {
	if (isEmpty(s)) {
		cout << "Stack Underflow" << endl;
	}
	else {
		cout << s->arr[s->top] << " has been popped" << endl;
		s->top--;
	}
}
void StackTraversal(Stack* s) {
	for (int i = 0; i < s->top; i++) {
		cout << "Elements: "<< s->arr[i] << endl;
	}
}
int parenthesis_match(Stack** s, string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			cout << "( found" << endl;
			push(*s, '(');
		}
		else if (str[i] == ')') {
			if (isEmpty(*s)) {
				return 0;
			}
			else {
				cout << ") found" << endl;
				pop(*s);
			}

		}
		else {
			continue;
		}
	}
	if (isEmpty(*s)) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	string str;
	Stack* s = new Stack();
	s->size = MAX;
	s->arr = new char(s->size);
	s->top = -1;
	cout << "Enter a string: " << endl;
	cin >> str;
	int ans = parenthesis_match(&s, str);
	if (ans) {
		cout << "match" << endl;
	}
	else {
		cout << "not match" << endl;
	}
	
}
