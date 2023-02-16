#include <iostream>
using namespace std;
#define SPACE 10

class TreeNode {
public:
	int value;
	TreeNode* Left;
	TreeNode* Right;

	// Default Constructor
	TreeNode() {
		value = 0;
		Left = NULL;
		Right = NULL;
	}

	// Constructor with value passed
	TreeNode(int v) {
		value = v;
		Left = NULL;
		Right = NULL;
	}
};

class AVL {
public:
	TreeNode* root;
	
	// Default Constructor
	AVL() {
		root = NULL;
	}

	// Check if AVL Tree is empty
	bool isEmpty() {
		if (root == NULL) {
			return true;
		}
		return false;
	}

	// Get Height 
	int height(TreeNode* r) {
		if (r == NULL) {
			return -1;
		}
		else {
			// Compute the height of each subtree
			int lheight = height(r->Left);
			int rheight = height(r->Right);

			// Use the larger one
			if (lheight > rheight)
				return lheight + 1;
			else return rheight + 1;
		}
	}

	// Get Balance
	int getBalance(TreeNode* n) {
		if (n == NULL) {
			return -1;
		}
		return height(n->Left) - height(n->Right);
	}

	// Right Rotation
	TreeNode* RightRotate(TreeNode* y) {
		TreeNode* x = y->Left;
		TreeNode* xr = x->Right;

		// Perform Rotation
		x->Right = y;
		y->Left = xr;

		return x;
	}

	// Left Rotation
	TreeNode* LeftRotate(TreeNode* y) {
		TreeNode* x = y->Right;
		TreeNode* xl = x->Left;

		// Perform Rotation
		x->Left = y;
		y->Right = xl;

		return x;
	}

	TreeNode* insert(TreeNode* r, TreeNode* new_node) {
		if (r == NULL) {
			r = new_node;
			cout << "Value inserted successfully" << endl;
			return r;
		}

		if (new_node->value < r->value) {
			r->Left = insert(r->Left, new_node);
		}
		else if (new_node->value > r->value) {
			r->Right = insert(r->Right, new_node);
		}
		else {
			cout << "Duplicate values are not allowed!" << endl;
			return r;
		}

		int balance = getBalance(r);
		// Left Left Case
		if (balance > 1 && new_node->value < r->Left->value) {
			return RightRotate(r);
		}

		// Right Right Case
		if (balance < -1 && new_node->value > r->Right->value) {
			return LeftRotate(r);
		}
		// Left Right Case
		if (balance > 1 && new_node->value > r->Left->value) {
			r->Left = LeftRotate(r->Left);
			return RightRotate(r);
		}
		// Right Left Case
		if (balance < -1 && new_node->value < r->Right->value) {
			r->Right = RightRotate(r->Right);
			return LeftRotate(r);
		}

		// Return Unchanged node pointer;
		return r;
	}

	void PrintAVL(TreeNode* r, int space) {
		if (r == NULL)   // Base Case
			return;
		space += SPACE;  // Increase distance between levels
		PrintAVL(r->Right, space);  // Process Right Child first
		cout << endl;
		for (int i = SPACE; i < space; i++) {
			cout << " ";
		}
		cout << r->value << endl;
		PrintAVL(r->Left, space); // Process Left Child
	}

	TreeNode* searchNode(TreeNode* r, int val) {
		if (r == NULL || r->value == val)
			return r;
		else if (val < r->value)
			return searchNode(r->Left, val);
		else
			return searchNode(r->Right, val);
	}
};



int main() {
	AVL obj;
	int option, val;
	do {
		cout << "What operation do you want to perform? "
			<< " Select option number. ENTER 0 TO EXIT." << endl;
		cout << "1. Insert Node" << endl;
		cout << "2. Search Node" << endl;
		cout << "3. Print AVL Tree ( < shaped )" << endl;
		cout << "4. Height of the Tree" << endl;
		cout << "0. Exit Program" << endl;

		cin >> option;
		TreeNode* new_node = new TreeNode();

		switch (option) {
		case 0:
			break;
		case 1:
			cout << "Enter Value of tree node to insert in AVL Tree: ";
			cin >> val;
			new_node->value = val;
			obj.root = obj.insert(obj.root, new_node);
			cout << endl;
			break;
		case 2:
			cout << "Enter Value of tree node to search in AVL Tree: ";
			cin >> val;
			new_node = obj.searchNode(obj.root, val);
			if (new_node != NULL) {
				cout << "Value Found!" << endl;
			}
			else {
				cout << "Value Not Found!" << endl;
			}
			break;
		case 3:
			cout << "Enter Value of spaces: ";
			cin >> val;
			obj.PrintAVL(obj.root, val);
			break;
		case 4:
			cout << obj.height(obj.root) << endl;
			break;
		default:
			break;
		}
	} while (option);
}
