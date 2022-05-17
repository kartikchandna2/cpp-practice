#include<iostream>
using namespace std;
void countSort(int A[], int size) {
	int max = A[0];
	int* B = new int(size + 1);
	for (int i = 1; i < size; i++) {
		if (A[i] > max) {
			max = A[i];
		}
		cout << "max: " << max << endl;
	}
	for (int i = 0; i <= max; i++) {
		B[i] = 0;
		cout << "B[" << i << "]: " << B[i] << endl;
	}
	for (int i = 0; i < size; i++) {
		B[A[i]]++;
		cout << "B[" << A[i] << "]: " << B[A[i]] << endl;
	}
	int i = 0;
	int j = 0;
	while (i <= max) {
		if (B[i] > 0) {
			A[j] = i;
			
			B[i]--;
			j++;
		}
		else {
			i++;
		}
				
	}
	//for (int k = 0; k < size; k++) {
		//A[k] = C[k];
	//}

}
int main() {
	int A[] = { 2, 1, 10, 3, 5, 4, 6, 11 };
	int size = 8;
	countSort(A, size);
	for (int i = 0; i < size; i++) {
		cout << A[i] << endl;
	}
}