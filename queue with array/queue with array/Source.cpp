#include<iostream>
using namespace std;
class Queue {
public:
	int size;
	int front;
	int back;
	int* arr;
};
int isFull(Queue* q) {
	if (q->back == q->size - 1) {
		return 1;
	}
	return 0;
}
int isEmpty(Queue* q) {
	if (q->back == q->front) { return 1; }
	return 0;
}
void enqueue(Queue* q, int val) {
	if (isFull(q)) {
		cout << "Queue overflow" << endl;
	}
	else {
		q->back++;
		q->arr[q->back] = val;
		cout << q->arr[q->back] << " has been added to the queue" << endl;
	}
}
int dequeue(Queue* q) {
	if (isEmpty(q)) {
		cout << "Queue underflow" << endl;
	}
	else {
		q->front++;
		return q->arr[q->front];
	}
}
int main() {
	Queue* q = new Queue();
	q->front = -1;
	q->back = -1;
	q->size = 5;
	q->arr = new int(q->size);
	enqueue(q, 30);
	enqueue(q, 50);
	int x = dequeue(q);
	cout << x << " has been removed from the queue" << endl;
}