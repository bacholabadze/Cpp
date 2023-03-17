#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> s1{ 23, 56, 5, 18, 78, 2, 90 };
	set<int> s2{ 12, 2, 90, 5, 24, 89, 10, 11, 28 };
	set<int>::iterator it;
	cout << "s1:\n";
	for (it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
		cout << &*it << endl;
	}
	cout << "\n\n\ns2:\n";
	for (it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
		cout << &*it << endl;
	}

	set<int> s1Us2(s1.begin(), s1.end());
	for (it = s2.begin(); it != s2.end(); it++) {
		s1Us2.insert(*it);
	}

	cout << "\n\n\ns1Us2:\n";
	for (it = s1Us2.begin(); it != s1Us2.end(); it++) {
		cout << *it << " ";
		cout << &*it << endl;
	}

	set<int> tan;
	for (it = s1.begin(); it != s1.end(); it++) {
		if (s2.find(*it) != s2.end())
			tan.insert(*it);
	}

	cout << "\n\n\ns1tans2:\n";
	for (it = tan.begin(); it != tan.end(); it++) {
		cout << *it << " ";
		cout << &*it << endl;
	}

	set<int> minus;
	for (it = s1.begin(); it != s1.end(); it++) {
		if (s2.find(*it) == s2.end())
			minus.insert(*it);
	}

	cout << "\n\n\ns1minuss2:\n";
	for (it = minus.begin(); it != minus.end(); it++) {
		cout << *it << " ";
		cout << &*it << endl;
	}

	cout << "\n\n\nmultiset:\n";

	multiset<int> ms1 = { 1, 37, 32, 12, 4, 5, 6, 37, 12, 37 };
	for (it = ms1.begin(); it != ms1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << ms1.erase(37) << " erase " << endl;
	for (it = ms1.begin(); it != ms1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
