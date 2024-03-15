#include <iostream>
#include <set>
#include <iterator>
#include <typeinfo>

using namespace std;

void printSet(set<int>s) {
    set<int>::iterator it;
    cout << "\n\nPrinting Set:\n";
    for (it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;
}
int main() {
    
    set<int> s1 = {10,2,-5,4,5};
    cout << "S1: " << endl;
    printSet(s1);
    s1.insert(-2);
    printSet(s1);

    // S2 ის გადაწერა S1 დან
    cout << "S2: " << endl;
    set<int>s2(s1.begin(), s1.end());
    s2.insert(-100);
    printSet(s2);
    cout << "S1: " << endl;
    printSet(s1);

    // წაშლის ოპერატორი
    auto result = s2.erase(s2.find(-5));
    cout << "type: " << typeid(result).name() << endl;
}
