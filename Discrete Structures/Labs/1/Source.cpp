#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> s{ 38,14,20,43,5 };
	//set<int>::iterator it;  // custom iterator
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
	s.insert(25);
	s.insert(14);
	
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
	auto i = s.find(20);
	if (i != s.end()) {
		cout << "20 is found" << endl;
		s.erase(i);
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
		//s.erase(it);
	}
	//cout << "after " << endl;
	//for (auto it = s.begin(); it != s.end(); it++)
	//	cout << *it << " ";
}
