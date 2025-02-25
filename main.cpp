#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int generateRandomNumber(int min, int max) {
	srand(time(0));
	return rand() % (max - min + 1) + min;
}

void printDeck(vector <string>  deck)
{
	for (int i = 0; i < deck.size(); i++)
	{
		cout << deck.at(i) << endl;
	}
}

int main() {
	string temp="";
	vector <string> wholeDeck;
	vector <string> player1Cards;
	vector <string> player2Cards;
	vector <string> player3Cards;
	vector <string> player4Cards;

	ifstream cardsIn; 
	const int shuffles = 2;
	int x, y,players = 0;

	cardsIn.open("cards.txt");

	if (cardsIn.fail())
	{
		cerr << "File failed to open: temps.txt";
		abort();
	}

	while (!cardsIn.eof()) 
	{
		cardsIn >> temp;
		wholeDeck.push_back(temp);
	}

	cout << wholeDeck.size() << endl;
	 

	cardsIn.close(); 

	printDeck(wholeDeck);

	for (int i = 0; i < shuffles; i++)
	{
		for (int j = 0; j < 52; j++) {
		this_thread::sleep_for(chrono::milliseconds(100));
		x= generateRandomNumber(1, 52);
		y = j;
		temp = wholeDeck.at(x);
		wholeDeck.at(x) = wholeDeck.at(y);
		wholeDeck.at(y) = temp;
		}
	}
	cout << "Shuffled Deck:" << endl;

	cout << "How many players? 2, 3 or 4" << endl;
	cin >> players;

	switch (players){
		case 2:
			for (int i = 0; i < 26; i++)
			{
				temp = wholeDeck.back();
				player1Cards.push_back(temp);
				wholeDeck.pop_back();
				temp = wholeDeck.back();
				player2Cards.push_back(temp);
				wholeDeck.pop_back();
			}
			cout << "Player 1's cards are: " << endl;
			printDeck(player1Cards);
			cout << "Player 2's cards are: " << endl;
			printDeck(player2Cards);
			break;
		case 3:
			for (int i = 0; i < 17; i++)
			{
				temp = wholeDeck.back();
				player1Cards.push_back(temp);
				wholeDeck.pop_back();
				temp = wholeDeck.back();
				player2Cards.push_back(temp);
				wholeDeck.pop_back();
				temp = wholeDeck.back();
				player3Cards.push_back(temp);
				wholeDeck.pop_back();
			}
			cout << "Player 1's cards are: " << endl;
			printDeck(player1Cards);
			cout << "Player 2's cards are: " << endl;
			printDeck(player2Cards);
			cout << "Player 3's cards are: " << endl;
			printDeck(player3Cards);
			break;
		case 4:
			for (int i = 0; i < 13; i ++)
			{
				temp = wholeDeck.back();
				player1Cards.push_back(temp);
				wholeDeck.pop_back();
				temp = wholeDeck.back();
				player2Cards.push_back(temp);
				wholeDeck.pop_back();
				temp = wholeDeck.back();
				player3Cards.push_back(temp);
				wholeDeck.pop_back();
				temp = wholeDeck.back();
				player4Cards.push_back(temp);
				wholeDeck.pop_back();
			}
			cout << "Player 1's cards are: " << endl;
			printDeck(player1Cards);
			cout << "Player 2's cards are: " << endl;
			printDeck(player2Cards);
			cout << "Player 3's cards are: " << endl;
			printDeck(player3Cards);
			cout << "Player 4's cards are: " << endl;
			printDeck(player4Cards);
			break;
		default:
			cout << "Invlaid number of players." << endl;
			break;
		}
	
	return 0;
}