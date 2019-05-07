#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>
#include "Card.h"
#include "SymbolCard.h"

using namespace std;

class Hand
{
public:
	Hand() :totalNumberCards(0), totalWordCards(0) {}
	int total();
	void useSymCardsMin();
	void addCard(Card* card);
	int size() {return cards.size();}
	int totSymCards() {return symbolCards.size(); }
	int totNumCards() { return totalNumberCards;}
	int totWordCards() { return totalWordCards;}
	friend ostream& operator<<(ostream &out, const Hand &hand);

private:
	vector<Card*> cards;
	//this vector will only point to
	//symbol cards in hand
	vector<SymbolCard*> symbolCards;
	int totalNumberCards;
	int totalWordCards;
};

#endif