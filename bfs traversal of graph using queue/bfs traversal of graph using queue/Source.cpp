#include<iostream>
using namespace std;
class Queue {
public:
	int* arr;
	int front;
	int rear;
	int size;
};
int isEmpty(Queue* q) {
	if (q->front == q->rear) {
		return 1;
	}
	return 0;
}
int isFull(Queue* q) {
	if (q->rear == q->size - 1) {
		return 1;
	}
	return 0;
}
void enqueue(Queue* q, int data) {
	if (isFull(q)) {
		cout << "Cannot enqueue" << endl;
	}
	else {
		q->rear++;
		q->arr[q->rear] = data;
	}
}
int dequeue(Queue* q) {
	int a = -1;
	if (isEmpty(q)) {
		cout << "Cannot dequeue" << endl;
	}
	else {
		q->front++;
		a = q->arr[q->front];
	}
	return a;
}
int main() {
	Queue* explored = new Queue();
	explored->arr = new int();
	explored->size = 400;
	explored->front = explored->rear = 0;

	int visited[7] = { 0,0,0,0,0,0,0 };

	int i = 2;
	int node;

	int adjacency_matrix[7][7] = {
		{0,1,1,1,0,0,0},
		{1,0,0,1,0,0,0},
		{1,0,0,1,1,0,0},
		{1,1,1,0,0,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0}
	};
	/*
			0----1
			|\   |
			| \  |
			|  \ |
			|   \|
  			2----3
			 \  /
			  \/
			   4
			  / \
			 /   \
			5     6
	
	*/

	cout << i<<endl;
	visited[i] = 1; //i has been visited
	enqueue(explored, i); //for exploration of i

	while (!isEmpty(explored)) {
		node = dequeue(explored);

		for (int j = 0; j < 7; j++) {
			if (adjacency_matrix[node][j] == 1 && visited[j] == 0) { //if the nodes are connected and it has not been visited
				cout << j << endl;
				visited[j] = 1;
				enqueue(explored, j);
			}
		}
	}
}