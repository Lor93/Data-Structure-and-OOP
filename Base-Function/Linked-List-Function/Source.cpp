#include<iostream>
#include "Node Function.h"
using namespace std;

void display(Node<int>* list);
int getSum(Node<int>* list);
//Looking for the max in Linked List
int getMax(Node<int>* list);
//Looking for the Smallest in Linked List
int getLast(Node<int>* list);
//Set 'a' as head and as long as it not equl to NULL continue to getlenth.
int getLength(Node<int>* list);
bool contain(Node<char>* list, char item);



int main()
{
	Node<int>* intHead = NULL;
	Node<char>* charHead = NULL;

	string str = "test st";
	Node<char>* newNode;

	for (int i = 0; i < str.size(); i++) {
		newNode = new Node<char>(str[i], charHead);
		charHead = newNode;
	}
	//Node<char>* c = charHead;
	//while (c != NULL) { cout << c->getItem() << "  "; c = c->getNext(); }
	if (contain(charHead, ' ')) {
		cout << "Yes, it is in the list." << endl;
	}
	else {
		cout << "No, it is not in the list." << endl;
	}
	
	//Node<int>* head = NULL;
	Node<int>* newIntNode;
	int newItem;
	int c;
	cout << " How many nodes do you want to create?" << endl;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cout << "Please enter an integer .\n";
		cin >> newItem;
		newIntNode = new Node<int>(newItem, intHead);
		intHead = newIntNode;
	}
	//Display Data Items in the Linked List
	display(intHead);
	//Display the Sum of the Linked List
	int s;
	s = getSum(intHead);
	cout << "The sum is " << s << endl;

	if (contain(charHead, '*' )) {
		cout << "Yes, it is in the list." << endl;
	}
	else {
		cout << "No, it is not in the list." << endl;
	}
	//Display the length of the Linked List
	int a;
	a = getLength(intHead);
	cout << "The length of the list is " << a <<endl;
	//Dispaly the MAX interger of the linked list
	int m;
	m = getMax(intHead);
	cout << "The MAX integer is " << m << endl;
	//Display the LAST item of the Liinked List
	int l;
	l = getLast(intHead);
	cout << "The last item in the Linked List is " << l << endl;
	
	return 0;
}




