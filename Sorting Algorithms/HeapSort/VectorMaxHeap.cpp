#include <iostream>
#include <vector>
using namespace std;

void Heapify(vector<int>* A, int n, int i) {
	int L = i * 2 + 1;
	int R = i * 2 + 2;
	int large = i;

	if (L<n && (*A)[L] > (*A)[large])
		large = L;
	if (R<n && (*A)[R] > (*A)[large])
		large = R;
	if (i != large) {
		swap((*A)[i], (*A)[large]);
		Heapify(A, n, large);
	}
}

void BuildHeap(vector<int>* A, int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(A, n, i);
	}
}

void HeapSort(vector<int>*A, int n) {
	BuildHeap(A, n);
	for (int i = n - 1; i >= 0; i--) {
		swap((*A)[0], (*A)[i]);
		Heapify(A, i, 0);
	}
}
int main() {
	vector<int> A;
	cout << "Sheikvane Ricxvebi. (-1 Gasatishad): ";
	int input = 0;
	while (true) {
		cin >> input;
		if (input == -1)
			break;
		A.insert(A.end(), input);
	}
	HeapSort(&A, A.size());

	for (int i = 0; i < A.size(); i++) {
		cout << A[i]<<" ";
	}
}
