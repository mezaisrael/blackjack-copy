#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card
{
public:
	//Card() {}
	Card(char _type) : type(_type) {}

	char getType() { return type; }

	virtual int getValue() = 0;
	virtual void printCard() = 0;

	// friend ostream& operator<<(ostream &out, const Card &card) {
	// 	card.printCard();
	// 	return out;
	// }

protected:
	char type;
};

#endif