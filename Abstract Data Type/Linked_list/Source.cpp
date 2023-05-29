#include<iostream>
#include"Node.h"
#include"List.h"
using namespace std;

int main()
{
	List<int> aList;

	//Test Insert() function
	for (int i = 0; i < 5; i++) {
		aList.insert(1, i + 1);
	}
	cout << "The numbers in the List are: \n";
	aList.displayList();
	cout << "====================\n";
	aList.insert(10,5);
	cout << "====================\n";
	aList.insert(0,5);
	cout << "====================\n";
	aList.insert(5,100);
	cout << "====================\n";
	cout << "The number in the list are: \n";
	aList.displayList();
	aList.insert(7,500);
	cout << "====================\n";
	cout << "The number in the list are: \n";
	aList.displayList();
	cout << "====================\n";

	//Test Removal() function
	aList.remove(0);
	aList.remove(10);
	cout << "====================";
	aList.remove(7);
	aList.displayList();
	cout << "====================";
	aList.remove(3);
	aList.displayList();
	cout << "====================";

	/*//Test getLength(), getEntry, and setEntry() Function
	cout << "The length of the list is: " << aList.getLength() << endl;
	cout << "====================";
	cout << "The number in the second position is " << aList.getEntry(2) << endl;
	cout << "====================\n";
	aList.setEntry(4, 800);
	aList.displayList();
	cout << "====================\n";

	//Test copy construction and clear() function
	List<int> bList(aList);
	cout << "====================\n";
	aList.clear();
	aList.displayList();
	cout << "====================\n";
	bList.displayList();
	cout << "====================\n";*/
	return 0;
}