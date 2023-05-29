#ifndef _Stack
#define _Stack
#include<iostream>
using namespace std;
template<class ItemType>

class Stack
{
private:
	ItemType item[100];
	int top;
	int getCurrentTop() {
		return top;
	}
	void setCurrentTop(int s) {
		top = s;
	}
public:
	Stack();
	bool isEmpty();
	bool push(ItemType newItem);
	bool pop();
	ItemType peek();
	void clean();
	bool display();
};
template<class ItemType>
Stack <ItemType>::Stack()
{
	setCurrentTop(-1);
}
template<class ItemType>
bool Stack< ItemType>::isEmpty()
{
	return (top == -1);
}
template<class ItemType>
bool Stack <ItemType>::push(ItemType newItem)
{
	if (top == 99) {
		cout << "Push failed, the stack is full!\n";
		return false;
	}
	else {
		item[++top] = newItem;
		return true;
	}
}
template<class ItemType>
bool Stack <ItemType>::pop()
{
	if (isEmpty()) {
		cout << "Pop failed, the stack is empty\n";
		return false;
	}
	else {
		top--;
		return true;
	}
}
template<class ItemType>
ItemType Stack <ItemType>::peek()
{
	if (isEmpty()) {
		cout << "The stack us empty, program aborted!\n";
		exit(0);
	}
	else {
		return item[top];
	}
}
template<class ItemType>
void Stack <ItemType> ::clean()
{
	setCurrentTop(-1);
}
template<class ItemType>
bool Stack <ItemType>::display()
{
	if (isEmpty()) {
		cout << "It is an empty stack!\n";
		return false;
	}
	else {
		cout << "The stack contains following items: \n";
		for (int i = 0; i <= top; i++)
			cout << item[i] << endl;
		return true;
	}
}
#endif _Stack