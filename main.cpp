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
	const int shuffles = 2;
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
		for (int j = 0; j < 52; j++) {
		this_thread::sleep_for(chrono::milliseconds(500));
		x= generateRandomNumber(1, 52);
		y = j;
		temp = wholeDeck.at(x);
		wholeDeck.at(x) = wholeDeck.at(y);
		wholeDeck.at(y) = temp;
		}
	}
	cout << "Shuffled Deck:" << endl;

	printDeck(wholeDeck);
	
	return 0;
}