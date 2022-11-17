#include <iostream>
using namespace std;

//#ifndef QorS
//#define QorS
class QorS {
public:
    int id;
    // Definition of QorS Constructor
    QorS();

    // QorS -shi nodebis damateba
    void add(const int& val, int pos = -1);
    void add(const int& val1, int pos1, const int& val2, int pos2, const int& val3, int pos3);


    // Funqcia Abrunebs QorS Carielia tu ara
    bool isEmpty();

    // Copy Constructor
    QorS(QorS& origQorS);

    // Remove Elements from top or bot
    void RemoveLIFO();
    void RemoveFIFO();

    // Display QorS
    void display(ostream& out) const;

    void displayRemoved(ostream& out) const;

private:
    class Node {
    public:
        int data;
        Node* next;
        int nodeId;
        // Node Constructor
        Node(int val, Node* link = 0) : data(val), next(link){}
        //~Node() {
        //    delete next;
        //};

        // Node Copy Constructor
        Node(Node* origNode, Node* link = 0) :
            data(origNode->data), nodeId(origNode->nodeId), next(link){}
    };

    Node* myTop;
    int size;

};
//#endif
