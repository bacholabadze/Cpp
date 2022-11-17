#include <iostream>
#include "QorS.h"

using namespace std;

int main() {
    cout << "Welcome to the QorS!\n";
    QorS myQorS;
    myQorS.add(0);
    myQorS.add(1, 1);
    myQorS.add(2, 2);
    myQorS.add(3, 3);
    myQorS.add(4);
    myQorS.add(5, 5);
    myQorS.add(6, 2);
    myQorS.display(cout);

    cout << "\n\t 1 Ready To Delete LIFO\n\n";
    myQorS.RemoveLIFO();
    myQorS.display(cout);

    cout <<"\n\ 2 Ready To Delete LIFO\n\n";
    myQorS.RemoveLIFO();
    myQorS.display(cout);
    cout<<endl;

    cout <<"\n\ 3 Ready To Delete LIFO\n\n";
    myQorS.RemoveLIFO();
    myQorS.display(cout);
    cout<<endl;
    
    cout << "\n\t4 Ready To Delete LIFO\n\n";
    myQorS.RemoveLIFO();
    myQorS.display(cout);
    cout<<endl;

    cout << "\n\t5 Ready To Delete LIFO\n\n";
    myQorS.RemoveLIFO();
    myQorS.display(cout);
    cout << endl;

    cout << "\n\t6 Ready To Delete LIFO\n\n";
    myQorS.RemoveLIFO();
    myQorS.display(cout);
    cout << endl;

    cout << "\n\t7 Ready To Delete LIFO\n\n";
    myQorS.RemoveLIFO();
    myQorS.display(cout);
    cout << endl;

    cout << "\n\t8 Ready To Delete Empty LIFO\n\n";
    myQorS.RemoveLIFO();
    myQorS.display(cout);
    cout << endl;
    cout << "\n\t[+] Refill QorS\n\n";
    myQorS.add(1);
    myQorS.add(2);
    myQorS.add(3);
    myQorS.add(4);
    myQorS.add(5,1);
    myQorS.add(6);
    myQorS.add(7, 2);
    myQorS.display(cout);

    cout << "\n\t9 Ready To Delete [!] FIFO\n\n";
    myQorS.RemoveFIFO();
    myQorS.display(cout);
    cout << endl;

    cout << "\n\t10 Ready To Delete [!] FIFO\n\n";
    myQorS.RemoveFIFO();
    myQorS.display(cout);
    cout << endl;

    cout << "\n\t11 Ready To Delete [!] FIFO\n\n";
    myQorS.RemoveFIFO();
    myQorS.display(cout);
    cout << endl;

    cout << "\n\t12 Ready To Delete [!] FIFO\n\n";
    myQorS.RemoveFIFO();
    myQorS.display(cout);
    cout << endl;

    cout << "\n\t13 Ready To Delete [!] FIFO\n\n";
    myQorS.RemoveFIFO();
    myQorS.display(cout);
    cout << endl;
    QorS copiedQorS = myQorS;

    cout << "\n\t14 Ready To Delete [!] FIFO\n\n";
    myQorS.RemoveFIFO();
    myQorS.display(cout);
    cout << endl;

    cout << "\n\t15 Ready To Delete [!] FIFO\n\n";
    myQorS.RemoveFIFO();
    myQorS.display(cout);
    cout << endl;

    cout << "\n\t16 Ready to Display Copied QorS [!]\n\n";
    copiedQorS.display(cout);

    cout << "\n\t17 Ready to Add QorS (Copied) Elements, 3 at time [!]\n\n";
    copiedQorS.add(0, 0, 1, 1, 2, 2);
    copiedQorS.display(cout);

    cout << "\n\t18 Ready to Display Original QorS [!]\n\n";
    myQorS.display(cout); // Empty

	return 1;
}
