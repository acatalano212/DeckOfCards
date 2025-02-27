#include <iostream>
#include<vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include "PlayingCard.h"

using namespace std;


int main() {

	PlayingCard CardTemp;
	string FaceValueTemp;
	int CardValueTemp;
	string SuitTemp;

	vector <PlayingCard> mainDeck;
	
	ifstream cardsIn;

	cardsIn.open("DetailedDeck.txt");

	if (cardsIn.fail())
	{
		cerr << "File failed to open: temps.txt";
		abort();
	}
	cout << "Loading Deck from file..." << endl;

	for (int i = 0; i < 52; i++) {
		while (!cardsIn.eof())
		{
			cardsIn >> FaceValueTemp >> CardValueTemp >> SuitTemp;
			CardTemp.setFaceValue(FaceValueTemp);
			CardTemp.setCardValue(CardValueTemp);
			CardTemp.setSuit(SuitTemp);
			mainDeck.push_back(CardTemp);

		}
	}
	cout << "Deck sucessfully loaded..." << endl;
	cout << "Printing Deck of Cards..." << endl;
		for (int i = 0; i < 52; i++) {
			mainDeck[i].printCard();
		}
		cout << "Suffelling Cards..." << endl;
		random_device rd;
		mt19937 g(rd());
		shuffle(mainDeck.begin(), mainDeck.end(), g);
		
		cout << "Printing Shuddelled Deck of Cards..." << endl;
		for (int i = 0; i < 52; i++) {
			mainDeck[i].printCard();
		}
		cout << "Printing Deck of Cards..." << endl;

		return 0;
	}