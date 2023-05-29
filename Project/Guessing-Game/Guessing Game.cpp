#include<iostream>
#include"Guessing Game.h"
using namespace std;

int main()
{
	Bag myBag;

	int a;
	for (int i = 0; i < 6; i++) {
		a = rand() % 100;
		myBag.add(a);
	}

	int counter = 0;
	int guess_time = 0;
	int score = 0;
	int guess;
	bool found = false;

	while (guess_time < 10 && !myBag.isEmpty()) {
		cout << "Please pick your number: " << endl;
		cin >> guess;
		if (myBag.contains(guess)) {
			cout << "The number you guessed is in the bag! " << endl;
			score += 10;
			counter++;
			myBag.remove(guess);
		}
		if (guess > a) {
			found = false;
		}
		else if (guess < a) {
			found = false;
		}
		else if (guess == a) {
			found = true;
		}
		guess_time++;
	}
	if (found == true) {
		cout << "You found all of them before your guess ran out here your score: " << score << " and a bonus: " << score + 200 << endl;
	}
	else {
		cout << "GAME OVER!!!!!" << endl;
	}
	cout << "Here is your score: " << score << endl;
	return 0;
}