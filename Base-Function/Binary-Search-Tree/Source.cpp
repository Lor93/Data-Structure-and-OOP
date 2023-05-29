#include<iostream>
#include"BinarySearchTree.h"
using namespace std;

int main() {

	int a = 5;
	BinarySearchTree<int> myTree;
	int testDate[7] = { 5,3,10,7,1,6,9 };
	for (int i = 0; i < 7; i++) {
		myTree.binarySearchAdd(testDate[i]);
	}
	cout << "====================" << endl;
	myTree.displayInorder();
	cout << "====================" << endl;
	myTree.binarySearchRemove(a);
	cout << "====================" << endl;
	myTree.displayInorder();
	cout << "====================" << endl;

	

	return 0;

}