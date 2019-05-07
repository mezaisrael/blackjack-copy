#ifndef DECK_H
#define DECK_H

#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include <fstream>

#include "Card.h"
#include "NumberCard.h"
#include "SymbolCard.h"
#include "WordCard.h"

using namespace std;

class Deck
{
 public:
	Deck () {}
	
	//returns Card pointer to the top card in the deck
	//also removes the top card from cards
	Card* dealCard();

	int size();

	friend istream& operator>> (istream &in, Deck &deck);
 private:
 	//stack of Card pointers
 	stack<Card*> cards;
};


#endif