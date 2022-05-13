#include<iostream>
using namespace std;
//stable algorithm
//adaptive algorithm

void insertSort(int A[], int size) {
	//if (size <= 1) {
		//return;
	//}
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int key = A[i];
		while (j >= 0 && A[j]>key) {
			A[i] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}
/*void insertSortRecursion(int A[], int size){
	if (size <= 1) {
		return;
	}
	insertSortRecursion(A, size-1)
	int key = A[size - 1];
	int j = n-2;
	while (j >= 0 && A[j]>key) {
		A[j+1] = A[j];
		j--;
	}
	A[j+1] = key;
}
*/
int main() {
	int A[] = { 20, 7, 3, 1, 21, 2 };
	int size = 6;
	insertSort(A, size);
	for (int i = 0; i < size; i++) {
		cout << A[i] << endl;
	}
}