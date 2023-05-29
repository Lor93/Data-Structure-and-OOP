#include<iostream>
#include "Stack.h"
#include<string>

using namespace std;

/*Prototypes*/
bool balanced_Checking(string str);
bool balanced_Checking_2(string str);

int main() 
{
	string test = "{abc{def}}";
	cout << test << (balanced_Checking(test) == true ? " is balance." : " is NOT balance.") << endl;
	
	string test2 = "{abc{def}";
	cout << test2 << (balanced_Checking(test2) == true ? " is balance." : " is NOT balance.") << endl;
	
	return 0;
}

bool balanced_Checking(string str)
{
	Stack<char> charStack;

	int i = 0;
	while (str[i] != '\0') {	//loop to traverse the string
		if (str[i] == '{' or str[i] == '(') {
			//return false;
			charStack.push(str[i]);
			i++;
		}
		else {
			if (str[i] == '}') {
				if (charStack.isEmpty() or charStack.peek() != '{') {
					return false;
				}
				else {
					charStack.pop();
					i++;
				}
			}
			else {
				if (str[i] == ')') {
					if (charStack.isEmpty() or
						charStack.peek() != '(') {
						return false;
					}
					else {
						charStack.pop();
						i++;
					}
				}
				else {
					i++;
				}
			}
		}
		if (charStack.isEmpty()) {
			return true;
		}
		else {
			//return false;
		}
	}
}
