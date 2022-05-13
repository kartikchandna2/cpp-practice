#include<iostream>
using namespace std;
//not stable sorting algorithm
//not adaptive sorting algorithm

void selectionSort(int A[], int size) {
	if (size <= 1) {
		return;
	}
	int isSorted = 0;
	int key = 0;
	for (int i = 1; i < size; i++) {
		isSorted = 1;
		cout << "pass: " << i << endl;
		if (A[i] < A[key]) {
			isSorted = 0;
			key = i;
			
		}
	}
	swap(A[0], A[key]);
	if (isSorted == 1) {
		return;
	}
	selectionSort(A+1, size - 1);
}
int main() {
	int A[] = {1,2,3,4,5,6,7 };
	int size = 7;
	selectionSort(A, size);
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<endl;
	}
}