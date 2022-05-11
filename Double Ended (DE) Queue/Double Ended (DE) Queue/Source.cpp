#include<iostream>
using namespace std;
class DEQ {
public:

	int size;
	int front;
	int rear;
	int* arr;
};
int isFull(DEQ* deq) {
	if (deq->front == -1 && deq->rear == deq->size - 1) {
		return 1;
	}
	return 0;
}
int isEmpty(DEQ* deq) {
	if (deq->rear == deq->front) {
		return 1;
	}
	return 0;
}
void enqueueFront(DEQ* deq, int val) {
	if (isFull(deq)) {
		cout << "queue full" << endl;
	}
	else {
		if (deq->front > -1) {
			deq->arr[deq->front] = val;
			cout << deq->arr[deq->front] << " has been enqueued from front" << endl;
			deq->front--;
		}
		else {
			cout << "full from front" << endl;
		}
	}
}
void enqueueRear(DEQ* deq, int val) {
	if (isFull(deq)) {
		cout << "queue full" << endl;
	}
	else {
		if (deq->rear < deq->size - 1) {
			deq->rear++;
			deq->arr[deq->rear] = val;
			cout << deq->arr[deq->rear] << " has been enqueued from the rear" << endl;
		}
		else {
			cout << "full from rear" << endl;
		}
	}
}
void dequeueFront(DEQ* deq) {
	if (isEmpty(deq)) {
		cout << "queue empty" << endl;
	}
	else {
		deq->front++;
		cout << deq->arr[deq->front] << " has been dequeued from front" << endl;
	}
}
void dequeueRear(DEQ* deq) {
	if (isEmpty(deq)) {
		cout << "queue empty" << endl;
	}
	else {
		cout << deq->arr[deq->rear] << " has been dequeued from the rear" << endl;
		deq->rear--;
	}
}
int main() {
	DEQ* deq = new DEQ();
	deq->size = 4;
	deq->front = deq->rear = -1;
	deq->arr = new int(deq->size);
	enqueueRear(deq, 10);
	enqueueRear(deq, 20);
	enqueueRear(deq, 30);
	enqueueRear(deq, 40);
	enqueueRear(deq, 50);
	dequeueFront(deq);
	dequeueFront(deq);
	dequeueRear(deq);
	dequeueRear(deq);
	dequeueRear(deq);
	enqueueFront(deq, 10);
	enqueueFront(deq, 20);
	enqueueFront(deq, 30);
}
