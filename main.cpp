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
	//vector <string> shuffeldCards;
	ifstream cardsIn; 
	const int shuffles = 1000;
	int x, y = 0;


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
		x = generateRandomNumber(1, 52);
		y = generateRandomNumber(1, 52);
		temp = wholeDeck.at(x);
		wholeDeck.at(x) = wholeDeck.at(y);
		wholeDeck.at(y) = temp;
	}
	cout << "Shuffled Deck:" << endl;

	printDeck(wholeDeck);
	
	return 0;
}