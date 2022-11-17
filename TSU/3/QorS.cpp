#include <new>
#include "QorS.h"

using namespace std;

// Stack Constructor
QorS::QorS()
    : myTop(0), size(0){
    puts("[!] Default Constructor");
};

void QorS::add(const int& val1, int pos1, const int& val2, int pos2, const int& val3, int pos3) {
    QorS::add(val1, pos1);
    QorS::add(val2, pos2);
    QorS::add(val3, pos3);
};

// Class-is method amatebs node elements QorS Shi. (Default-ad Siis Boloshi)
void QorS::add(const int& val, int pos) {
    if (pos == -1) {
        pos = size;
    }

    if (pos > size) {
        cout << "[!] Elementi Ver Daemateba [" << pos << "] Poziciaze [" << pos << "], max=" << size << endl;
    }
    else if (pos == size) {
        myTop = new Node(val, myTop);
        myTop->nodeId = id++;
        size++;
    }
    else {
        // Elementebis 1-it gadaceva
        myTop = new Node(myTop->data, myTop); // nodis kopireba
        myTop->nodeId = id++;

        int temp_id = myTop->nodeId;

        myTop->nodeId = myTop->next->nodeId;
        //myTop->id = pos;

        Node* index = myTop->next;

        Node* cur;
        for (int i = 0; i < size - pos - 1; i++) {
            cur = index;
            index->data = cur->next->data;

            index->nodeId = cur->next->nodeId;

            index = index->next;
        }
        index->data = val;
        index->nodeId = temp_id;
        size++;
    }
}

// Copy Constructor
QorS::QorS(QorS& origQorS)
    : myTop(origQorS.myTop), size(origQorS.size) 
{
    Node* copyNode=0;

    for (Node* ptr = origQorS.myTop;ptr!=0;ptr=ptr->next) {
        cout << "Copied Node :)\n";
        copyNode = new(nothrow) Node(ptr, copyNode);
    }
    myTop = copyNode;
}

bool QorS::isEmpty() {
    if (myTop == 0) return true;
    return false;
}

void QorS::RemoveLIFO() {
    if (size) {
        int maxId = myTop->nodeId;
        Node* temp = 0;
        // Search Biggest Node ID to Delete later
        for (Node* ptr = myTop; ptr != 0; ptr = ptr->next) {
            if (ptr->nodeId > maxId) {
                maxId = ptr->nodeId;
                temp = ptr;

            }
        }

        // Delete
        for (Node* ptr = myTop; ptr != temp; ptr = ptr->next) {
            // Tu Siis Sataveshia
            if (ptr->nodeId == maxId && ptr == myTop) {
                temp = ptr;
                myTop = ptr->next;
                delete temp;
                size--;
                break;
            } // Tu Siis Boloshia
            else if (ptr->next == 0 && ptr->next->next->nodeId == maxId) {
                temp = ptr->next;
                ptr->next = 0;
                delete temp;
                size--;
                break;
            }
            else if (ptr->next->nodeId == maxId) {
                temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
                display(cout);
                size--;
                break;
            }
        }
    }

}

void QorS::RemoveFIFO() {
    if (size) {
        int minId = myTop->nodeId;
        Node* temp = 0;
        // Search Biggest Node ID to Delete later
        for (Node* ptr = myTop; ptr != 0; ptr = ptr->next) {
            if (ptr->nodeId < minId) {
                minId = ptr->nodeId;
                temp = ptr;

            }
        }
        // Delete
        for (Node* ptr = myTop; ptr != temp; ptr = ptr->next) {
            // Tu Siis Sataveshia
            if (ptr->nodeId == minId && ptr == myTop) {
                temp = ptr;
                myTop = ptr->next;
                delete temp;
                size--;
                break;
            } // Tu Siis Boloshia
            else if (ptr->next == 0 && ptr->next->next->nodeId == minId) {
                temp = ptr->next;
                ptr->next = 0;
                delete temp;
                size--;
                break;
            }
            else if (ptr->next->nodeId == minId) {
                temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
                display(cout);
                size--;
                break;
            }
        }
    }

}

void QorS::display(ostream& out) const {
    if (!size) {
        cout << "[-] Empty QorS\n";
    }
    Node* ptr;
    for (ptr = myTop; ptr != 0; ptr = ptr->next) {
        out << ptr->nodeId << ") " << ptr->data << "\tAddr(" << ptr << ")" << "\tNext(" << ptr->next << ")\n";
    }
}
