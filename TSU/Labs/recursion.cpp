#include <iostream>
using namespace std;

int pow(int base, int power) {
	if (power == 0) {
		return 1;
	}
	else {
		return base * pow(base, power - 1);
	}
}

int factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int factorialIter(int n) {
	int calc = 1;
	for (int i = n; i > 0; i--) {
		calc *= i;
	}
	return calc;
}

int fib(int n) {
	if (n == 1 || n == 0) {
		return 1;
	}
	else {
		return fib(n - 2) + fib(n - 1);
	}
}

void binSearchIter(int* arr, int low, int high, int searchNum) {
	while (low <= high) {
		//cout << "While Loop!\n";

		int mid = (low + high) / 2;
		//cout << "Mid = " << mid << endl;
		//cout << "Low = " << low << endl;
		//cout << "High = " << high << endl<<endl;

		if (arr[mid]==searchNum) {
			cout << "Ipova\n";
			cout << mid<<endl;
			break;
		}
		else if (arr[mid] < searchNum) {
			low = mid+1;
		}
		else {
			high = mid-1;
		}
	}
	if(low>high)
		cout << "Ver Ipova!" << endl;


}

int binSearch(int* arr, int low, int high, int searchNum) {
	int mid = (low + high) / 2;
	//cout << "Mid = " << mid << endl;
	//cout << "Low = " << low << endl;
	//cout << "High = " << high << endl << endl;
	if (low >= high) {
		if (arr[mid] == searchNum) {
			return mid;
		}
		return -1;
	}
	else {
		if (arr[mid] > searchNum) {
			return binSearch(arr,low, mid - 1, searchNum);
		}
		else {
			return binSearch(arr, mid + 1, high, searchNum);
		}
	}
}
int main() {
	//int a = 30;
	//int b = 3;
	//cout << "A^B = " << pow(a, b) << endl;
	//cout << a << "! = " << factorial(a) << endl;
	//cout << a << "! = " << factorialIter(a) << endl;
	//cout << a << " fib = " << fib(a) << endl;
	int myArr[] = { 1, 2,3,4,5,6,7,8,9 };

	//cout << binSearch(myArr, 0, 8, 15) << " index";

	cout << "\n\nIteration: ";
	binSearchIter(myArr, 0, 8, 116);

	return 0;
}
