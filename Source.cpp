#include <iostream>
#include <cstdlib>
using namespace std;
int balance;
int limit;
int stake;
void mainmenu(int balance);
void game(int balance);
int main() {
	cout << "========DICE GAME========" << "\n";
	cout << "Enter the balance you want to start with: ";
	cin >> balance;
	cout << "Enter the limit value: ";
	cin >> limit;
	mainmenu(balance);
}
void mainmenu(int balance) {
	char choice;
	if (balance == 0) {
		cout << "You've spent all the money! Game over!" << "\n";
		exit(0);
	}
	else {
		cout << "Your balance is: " << balance << "$\n";
		cout << "Enter your choice:\n" << "(r)oll the dice;\n" << "e(x)it;\n";
		cin >> choice;
		if (choice == 'r') game(balance);
		else if (choice == 'x') exit(0);
		else mainmenu(balance);
	}
}
void game(int balance) {
	int randint;
	int newbalance;
	int border = limit * 2;
	cout << "Enter your stake: ";
	cin >> stake;
	if (stake <= balance) {
		randint = rand() % border + 1;
		if (randint < limit) {
			newbalance = balance - stake;
			cout << "Random number is " << randint << "\n";
			cout << "Unfortunately, your stake had burned! Current balance is: " << newbalance << "\n";
			mainmenu(newbalance);
		}
		else if (randint == limit) {
			newbalance = balance * 2;
			cout << "Random number is " << randint << "\n";
			cout << "Random number equals limit! Your score gets doubled! Current balance is: " << newbalance << "\n";
			mainmenu(newbalance);
		}
		else {
			newbalance = balance + stake;
			cout << "Random number is " << randint << "\n";
			cout << "Your stake has passed! Current balance is: " << newbalance << "\n";
			mainmenu(newbalance);
		}
	}
	else {
		cout << "You can't bet more than you have!\n";
		game(balance);
	}
}
