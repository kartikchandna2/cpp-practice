#include<iostream>
using namespace std;
void merge(int A[], int start, int middle, int end) {
	int B[100];
	int i = start, j = middle + 1, k = start;
	while (i <= middle && j <= end) {
		if (A[i] <= A[j]) {
			B[k] = A[i];
			i++;
			k++;
		}
		else {
			B[k] = A[j];
			j++;
			k++;
		}
	}
	while (i <= middle) {
		B[k] = A[i];
		i++;
		k++;
	}
	while (j <= end) {
		B[k] = A[j];
		j++;
		k++;
	}
	for (int a = start; a <= end; a++) {
		A[a] = B[a];
	}
}
void mergeSort(int A[], int start, int end) {
	int middle;
	if (start < end) {
		middle = (start + end) / 2;
		mergeSort(A, start, middle);
		mergeSort(A, middle + 1, end);
		merge(A, start, middle, end);
	}
	

}
int main() {
	int A[] = { 2, 3, 10, 1, 9, 4 };
	int size = 6;
	mergeSort(A, 0, size - 1);
	for (int i = 0; i < size; i++) {
		cout << A[i] << endl;
	}
}