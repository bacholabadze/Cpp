#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>* A, int start, int end) {
	int pivot = (*A)[end];
	int partitionIndex = start;
	for (int i = start; i < end; i++) {
		if ((*A)[i] > pivot) {
			swap((*A)[i], (*A)[partitionIndex]);
			partitionIndex++;
		}
	}
	swap((*A)[end], (*A)[partitionIndex]);
	return partitionIndex;
}

void QuickSort(vector<int>* A, int start, int end) {
	if (start < end) {
		int partitionIndex = Partition(A, start, end);
		QuickSort(A, start, partitionIndex - 1);
		QuickSort(A, partitionIndex + 1, end);
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

	QuickSort(&A, 0, A.size()-1);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i]<<" ";
	}
}
