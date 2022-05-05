#include<iostream>
using namespace std;
class Stack {
public:
	char *arr;
	int size;
	int top;
};
int isEmpty(Stack* s) {
	if (s->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}
int isFull(Stack* s) {
	if (s->top == s->size) {
		return 1;
	}
	else {
		return 0;
	}
}
void push(Stack* s, char x) {
	if (isFull(s)) {
		cout << "Stack Overflow" << endl;
	}
	else {
		s->top++;
		s->arr[s->top] = x;
		cout << x << " has been added to the stack" << endl;
	}
}
void pop(Stack* s) {
	if (isEmpty(s)) {
		cout << "stack Underflow" << endl;
	}
	else {
		cout << s->arr[s->top] << " has been popped from the stack" << endl;
		s->top--;
	}
}
void stackTraversal(Stack* s) {
	if (isEmpty(s)) {
		cout << "Stack Empty" << endl;
	}
	else {
		for (register int i = s->top; i >= 0; i--) {
			cout << "Elements: " << s->arr[i] << endl;
		}
	}

}
int parenthesisMatch(Stack** s, string str) {
	for (register int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '(':
		case '{':
		case '[':
			push(*s, str[i]);
			break;
		case ')':
			if ((*s)->arr[(*s)->top] == '(') {
				pop(*s);
			}
			else {
				return 0;
			}
			break;
		case '}':
			if ((*s)->arr[(*s)->top] == '{') {
				pop(*s);
			}
			else {
				return 0;
			}
			break;
		case ']':
			if ((*s)->arr[(*s)->top] == '[') {
				pop(*s);
			}
			else {
				return 0;
			}
			break;
		}
	}




	/*	if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			push(*s, str[i]);
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if (isEmpty(*s)) {
				return 0;
			}
			else if ((* s)->arr[(*s)->top] == str[i])
			{
				pop(*s);
			}
			else  {
				return 0;
			}
		}
		else {
			continue;
		}
	}*/
	if (isEmpty(*s)) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	Stack* s = new Stack();
	s->top = -1;
	s->size = 20;
	s->arr = new char(s->size);
	string str;
	cout << "Enter string to check for multiple parenthesis match: ";
	cin >> str;
	int ans = parenthesisMatch(&s, str);
	if (ans) {
		cout << "Parenthesis match" << endl;
	}
	else {
		cout << "Parenthesis not match" << endl;
	}
}