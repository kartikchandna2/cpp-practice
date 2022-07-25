#include<iostream>
#include<vector>
using namespace std;

//Selection Sort

void selectionSort(int n, vector<int>& a, int start) {
	if (start == n) {
		return;
	}
	int pivot = start;
	for (int i = start+1; i < n; i++) {
		if (a[i] <= a[pivot]) {
			pivot = i;
		}
	}
	swap(a[start], a[pivot]);
	selectionSort(n , a, start+1);
}

//Insertion Sort

void insertionSort(int n, vector<int>& a) {
	if (n == 1 || n == 0) {
		return;
	}
	insertionSort(n - 1, a);
	int x = a[n-1];
	int i = n - 2;
	while (i >= 0 && a[i] > x) {
		a[i + 1] = a[i];
		i--;
	}
	
	a[i+1] = x;

}

//Bubble Sort

void bubbleSort(int n, vector<int>& a) {
	if (n == 1 || n==0)
		return;
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i + 1]) {
			swap(a[i], a[i + 1]);
		}
	}
	bubbleSort(n - 1, a);
}

//Merge Sort

void merge(vector<int>& a, int start, int end) {
	int mid = (start + end) / 2;
	int size1 =  mid - start + 1;
	int size2 = end - mid;

	int* first = new int[size1]; // for part 2 of a
	int* second = new int[size2]; // for part 1 of a

	//add elements to first and second from a
	int i = start;
	for (int j = 0; j < size1; j++) {
		 first[j] = a[i++];
	}
	i = mid + 1;
	for (int j = 0; j < size2; j++) {
		second[j] = a[i++];
	}

	//merge these arrays assuming they are sorted
	
	i = start;
	int ind1 = 0;
	int ind2 = 0;
	while (ind1 < size1 && ind2 < size2) {
		if (first[ind1] < second[ind2]) {
			a[i++] = first[ind1++];
		}
		else {
			a[i++] = second[ind2++];
		}
	}
	while (ind1 < size1) {
		a[i++] = first[ind1++];
	}
	while (ind2 < size2) {
		a[i++] = second[ind2++];
	}
}
void mergeSort(vector<int>& a, int start, int end) {
	if (start >= end) return;
	int mid = (start + end) / 2;
	mergeSort(a, start, mid);
	mergeSort(a, mid + 1, end);

	merge(a, start, end);
}


//Quick Sort

int partition(vector<int>& a, int start, int end) {
	int pivot = a[start];
	int count = 0;
	for (int i = start+1; i <= end; i++) {
		if (a[i] <= pivot) {
			count++;
		}
	}
	int pivind = start+count;
	swap(a[pivind], a[start]);
	int i = start, j = end;
	while (i<pivind && j>pivind) {
		while (a[i] <= pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}
		if(i<pivind && j>pivind) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	return pivind;
}

void QuickSort(vector<int>& a, int start, int end) {
	if (start >= end) return;
	int x = partition(a, start, end);

	QuickSort(a, start, x - 1);
	QuickSort(a, x + 1, end);
}




int main() {
	int n = 10;
	vector<int> a = { 3, 19, 2, 22, 23, 25, 1, 1, 4, 30 };
	//bubbleSort(n, a);
	//selectionSort(n, a, 0);
	//insertionSort(n, a);
	//mergeSort(a, 0, n - 1);
	QuickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}