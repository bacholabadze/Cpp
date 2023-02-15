#include <iostream>
//#include <algorithm>
using namespace std;

void heapify(int A[], int n, int i) {
	int Lix = i * 2 + 1;
	int Rix = i * 2 + 2;
	int large = i;

	if (Lix < n && A[Lix] > A[i]) {
		large = Lix;
	}
	if (Rix < n && A[Rix] > A[large]) {
		large = Rix;
	}
	if (i != large) {
		swap(A[i], A[large]);
		heapify(A, n, i);
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
		swap(A[0], A[i]);
		heapify(A, i, 0);
	}
}


int main() {
	cout << "Sheikvane Elementebis Raodenoba: ";
	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	heapSort(A, n);
	for (int i = 0; i < n; i++) {
		cout<<A[i]<<" ";
	}

}
