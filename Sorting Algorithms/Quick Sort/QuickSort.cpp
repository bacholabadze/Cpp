#include <iostream>
using namespace std;

int Partition(int arr[], int start, int end) {
	int pivot = arr[end];
	int partitionIndex = start;  // set start index as initial partition index
	for (int i = start; i < end; i++) {
		if (arr[i] > pivot) {
			swap(arr[i], arr[partitionIndex]);  // swap if element is less than pivot
			partitionIndex++;
		}
	}
	swap(arr[partitionIndex], arr[end]);  // swap pivot with element at partition index 
	return partitionIndex;
}

void QuickSort(int arr[], int start, int end) {
	if (start < end) {
		int partitionIndex = Partition(arr, start, end);
		QuickSort(arr, start, partitionIndex - 1);
		QuickSort(arr, partitionIndex + 1, end);
	}
}
int main() {
	cout << "Sheikvane Elementebis Raodenoba: ";
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	QuickSort(arr,0, n-1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

}
