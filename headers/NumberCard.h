#ifndef NUMBERCARD_H
#define NUMBERCARD_H

#include <iostream>
#include "Card.h"

using namespace std;

class NumberCard : public Card
{
public:
	NumberCard() : Card('N') {}
	int getValue() { return value; }
	void printCard() { cout << value; }

	friend istream& operator>> (istream &in, NumberCard &numberCard);
	friend ostream& operator<< (ostream &out, NumberCard &numberCard);
private:
	int value;
	
};

//#include "../src/NumberCard.cpp"

#endif
