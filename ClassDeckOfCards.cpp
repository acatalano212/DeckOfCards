#include <iostream>
#include<vector>

using namespace std;

class PlayingCard {
public:

	string faceValue;
	int cardValue;
	string suit;

};


int main() {

	PlayingCard card1;
	card1.faceValue = "King";
	card1.cardValue = 13;
	card1.suit = "Heart";

	vector <PlayingCard> mainDeck;
	mainDeck[0].cardValue = 12;
	mainDeck[0].faceValue = "Queen";
	mainDeck[0].suit = "Diamond";


	return 0;
}