#include<iostream>
using namespace std;
class QueueLL {
public:
	int val;
	QueueLL* next;
};
int isFull(QueueLL* front) {
	QueueLL* n = new QueueLL();
	if (n == NULL) {
		return 1;
	}
	return 0;
}
int isEmpty(QueueLL* front) {
	if (front == NULL) {
		return 1;
	}
	return 0;
}
void enqueue(QueueLL** front, QueueLL** rear, int value) {
	if (isFull(*front)) {
		cout << "Queue FULL" << endl;
	}
	else {
		QueueLL* n = new QueueLL();
		n->val = value;
		n->next = NULL;
		if (*front == NULL) {
			*front = n;
			*rear = n;
		}
		else {
			(*rear)->next = n;
			(*rear) = n;
		}
		cout << n->val << " has been added to the queue" << endl;
	}
}
void dequeue(QueueLL** front) {
	if (isEmpty(*front)) {
		cout << "Queue Empty" << endl;
	}
	else {
		QueueLL* ptr = *front;
		*front = (*front)->next;
		cout << ptr->val << " is being dequeued" << endl;
		free(ptr);
	}
}
int main() {
	QueueLL* front = NULL;
	QueueLL* rear = NULL;
	enqueue(&front, &rear, 10);
	enqueue(&front, &rear, 20);
	dequeue(&front);
	dequeue(&front);
	dequeue(&front);
}