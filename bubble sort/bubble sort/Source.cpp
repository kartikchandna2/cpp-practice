#include<iostream>
using namespace std;
//stable algorithm
//not adaptive algorithm

void bubbleSort(int A[], int size) {
	if (size == 1) {
		return;
	}
	int isSorted = 0;
	for (int i = 0; i < size-1; i++) {
		isSorted = 1;
		cout << "pass: " << i << endl;
		if (A[i] > A[i + 1]) {
			swap(A[i], A[i + 1]);
			isSorted = 0;
		}
	}
	if (isSorted == 1) {
		return;
	}
	
	bubbleSort(A, size - 1);
}
int main() {
	int A[] = { 1,2,3,20,4,5 };
	int size = 6;
	bubbleSort(A, size);
	for (int i = 0; i < size; i++) {
		cout << A[i] << endl;
	}
}