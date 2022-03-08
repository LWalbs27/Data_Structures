#include <iostream>
#include <fstream>
using namespace std;

class BinaryWordTree {

	struct node {
		string wordVal;
		node * left;
		node * right;
	};



	node * root;


	bool isEmpty(node * t) {
		if (t == NULL) {
			return true;
		} else {
			return false;
		}
	}


	node * insert(node* temp, string toAdd) {

		if (temp == NULL) {

			temp = new node;
			temp->wordVal = toAdd;
			temp->left = NULL;
			temp->right =NULL;




		} else if (temp->wordVal > toAdd) {
			temp->left = insert(temp->left, toAdd);

		} else if(temp->wordVal < toAdd) {
			temp->right = insert(temp->right,toAdd);
		}

		return temp;
	}

	public:
	BinaryWordTree() {
		root = NULL;
	}

	void insert(string toAdd) {

		root = insert(root,toAdd);
	}

	void inOrderPrint(node * tree, string k1, string k2) {
		if (tree == NULL) {
			return;
		}

		if (k1 < tree->wordVal) {
			inOrderPrint(tree->left,k1,k2);
		}
		if (k1 <= tree->wordVal && k2 >= tree->wordVal) {
			cout << tree->wordVal << endl;
		}

		if (k2 > tree->wordVal) {
			inOrderPrint(tree->right,k1,k2);
		}

	}


	void printTree(string k1, string k2) {
		inOrderPrint(root, k1, k2);
	}
};







int main() {

	BinaryWordTree tree;
	string line;
	ifstream file ("words.txt");

	string k1,k2;


	cout << "Please enter string k1: ";

	cin >> k1;

	cout << "\nPlease enter string k2: ";

	cin >> k2;


	if (file.is_open()) {
		while(getline(file, line) )
		{
			tree.insert(line);
		}
	} else {
		cout << "File isn't opened" << endl;
	}




	tree.printTree(k1,k2);



	return 0;
}




