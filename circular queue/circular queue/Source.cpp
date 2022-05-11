#include<iostream>
using namespace std;
class circularQueue {
public:
	int size;
	int front;
	int rear;
	int* arr;
};
int isFull(circularQueue* cq) {
	if ((cq->rear + 1) % cq->size == cq->front) {
		return 1;
	}
	return 0;
}
int isEmpty(circularQueue* cq) {
	if (cq->rear == cq->front) {
		return 1;
	}
	return 0;
}
void enqueue(circularQueue* cq, int value) {
	if (isFull(cq)) {
		cout << "Circular Queue Overflow" << endl;
	}
	else {
		cq->rear = (cq->rear + 1) % cq->size;
		cq->arr[cq->rear] = value;
		cout << cq->arr[cq->rear] << " has been added to the circular queue" << endl;
	}
}
int dequeue(circularQueue* cq) {
	if (isEmpty(cq)) {
		cout << "Circular Queue Undeflow" << endl;
	}
	else {
		cq->front = (cq->front + 1) % cq->size;
		return cq->arr[cq->front];
	}
}
int main() {
	circularQueue* cq = new circularQueue();
	cq->size = 4;
	cq->rear = cq->front = 0;
	cq->arr = new int(cq->size);
	enqueue(cq, 10);
	enqueue(cq, 20);
	enqueue(cq, 30);
	enqueue(cq, 40);
	int value = dequeue(cq);
	cout << value << " dequeued" << endl;
	int value1 = dequeue(cq);
	cout << value1 << " dequeued" << endl;
	int value2 = dequeue(cq);
	cout << value2 << " dequeued" << endl;
	int value3 = dequeue(cq);
	cout << value3 << " dequeued" << endl;
}