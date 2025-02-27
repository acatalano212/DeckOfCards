#include <iostream>
#include <string>
#include "PlayingCard.h"

using namespace std;

PlayingCard::PlayingCard() {
	faceValue = "";
	cardValue = 0;
	cardSuit = "";
}
void PlayingCard::setFaceValue(string face) {
	faceValue = face;
}
void PlayingCard::setCardValue(int card) {
	cardValue = card;
}
void PlayingCard::setSuit(string suit) {
	cardSuit = suit;
}
void PlayingCard::printCard() {
	cout << faceValue << " of " << cardSuit << " has a value of " << cardValue << endl;
}