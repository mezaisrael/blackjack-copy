#ifndef SYMBOLCARD_H
#define SYMBOLCARD_H

#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

class SymbolCard : public Card
{
public:
	SymbolCard() : Card('S') {}

	int getMinVal() { return min; }
	int getMaxVal() { return max; }
	//sets card value to low
	void useLowValue();
	void printCard();
	int getValue() { return value;}
	
	friend istream& operator>> (istream &in, SymbolCard &symbolCard);
	friend ostream& operator<< (ostream &out, SymbolCard &symbolCard);
private:
	int min;
	int max;
	int value;
	char symbol;
	
};
#endif