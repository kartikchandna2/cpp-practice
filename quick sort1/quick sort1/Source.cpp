#include<iostream>
using namespace std;
int partition(int A[], int start, int end) {
	int key = A[start];
	int count = 0;
	for (int i = start+1; i <= end; i++) {
		if (A[i] <= key) {
			count++;
		}
	}
	int pivot = start+count;
	swap(A[start], A[pivot]);
	int i = start;
	int j = end;
	while (i < pivot && j > pivot) {
		if (A[i] <= key) {
			i++;
		}
		else if (A[j] > key) {
			j--;
		}
		else {
			swap(A[i], A[j]);
			i++;
			j--;
		}
	}
	return pivot;
}
void quickSort(int A[], int start, int end) {
	if (start>=end) {
		return;
	}
	int i = partition(A, start, end);
	quickSort(A, start, i-1);
	quickSort(A, i + 1, end);

}
int main() {
	int A[] = { 10, 3, 22, 24, 1, 2, 9 };
	int size = 7;
	quickSort(A, 0, size-1);
	for (int i = 0; i < size; i++) {
		cout << A[i] << endl;
	}
}