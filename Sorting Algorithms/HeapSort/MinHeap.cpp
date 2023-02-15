#include <iostream>
using namespace std;

void heapify(int A[], int n, int i) {
	int Lix = i * 2 + 1;
	int Rix = i * 2 + 2;
	int small = i;

	if (Lix < n && A[Lix] < A[small]) {
		small = Lix;
	}
	if (Rix < n && A[Rix] < A[small]) {
		small = Rix;
	}
	if (i != small) {
		swap(A[i], A[small]);
		heapify(A, n, small);
	}
}

void buildHeap(int A[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(A, n, i);
	}
}

void heapSort(int A[], int n) {
	buildHeap(A, n);
	for (int i = n - 1; i >= 0; i--) {
		swap(A[i], A[0]);
		heapify(A, i, 0);
	}
}

int main() {
	cout << "Sheikvane elementebis raodenoba: ";
	int n;
	cin >> n;
	int* A = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	heapSort(A, n);

	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
}
