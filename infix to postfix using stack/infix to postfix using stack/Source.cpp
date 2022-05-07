#include<iostream>
using namespace std;
class Stack {
public:
	int top;
	int size;
	char* arr;
};
int isEmpty(Stack* s) {
	if (s->top == -1) {
		return 1;
	}
	return 0;
}
int isFull(Stack* s) {
	if (s->top == s->size) {
		return 1;
	}
	return 0;
}
void push(Stack* s, char ele) {
	if (isFull(s)) {
		cout << "Stack Overflow" << endl;
	}
	else {
		s->top++;
		s->arr[s->top] = ele;
		cout << "Element " << ele << " has been added to the stack" << endl;
	}
}
char pop(Stack* s) {
	char element;
	if (isEmpty(s)) {
		cout << "Stack Underflow" << endl;
	}
	else {
		cout << "Element " << s->arr[s->top] << " has been popped out of the stack" << endl;
		element = s->arr[s->top];
		s->top--;
	}
	return element;
}
int checkPrecedence(char s) {
	
	switch (s) {
	case '*':
	case '/':
		return 2;
		break;
	case '+':
	case '-':
		return 1;
		break;
	case '^':
		return 3;
		break;
	}
}
string changeToPostfix(Stack* s, string str, string output) {
	char ch;
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '+':
		case '-':
		case '/':
		case '*':
		case '^':
			if (isEmpty(s) || (checkPrecedence(str[i]) > checkPrecedence(s->arr[s->top]))) {
				push(s, str[i]);
			}
			else {
		
				for (int j = 0; (checkPrecedence(s->arr[s->top]) >= checkPrecedence(str[i]) && s->top>=0); j++) {
					ch = pop(s);
					output += ch;
				}				
				push(s, str[i]);
				
			}
			break;
		default:
			output += str[i];
		}
	}
	while (!isEmpty(s)) {
		char ch1 = pop(s);
		output += ch1;
	}
	return output;
}
int main() {
	Stack* s = new Stack();
	s->size = 20;
	s->top = -1;
	s->arr = new char(s->size);
	string str = "x-y/z-k*d";
	//cout << "Enter string to convert to postfix: " << endl;
	//cin >> str;
	string final =  "";
	final = changeToPostfix(s, str, final);
	cout << final << endl;
}

