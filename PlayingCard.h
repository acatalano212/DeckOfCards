#ifndef PlAYINGCARD_H
#define PlAYINGCARD_H

#include <iostream>
#include <string>

using namespace std;

class PlayingCard {
public:
	PlayingCard();
	void setFaceValue(string);
	void setCardValue(int);
	void setSuit(string);
	void printCard();

private:
	string faceValue;
	int cardValue;
	string cardSuit;

}; 
#endif