#ifndef SYMBOLCARD
#define SYMBOLCARD

#include "../headers/SymbolCard.h"

void SymbolCard::useLowValue() {
	value = min;
}

void SymbolCard::printCard() {
	cout << symbol << " ("
	<< min << "/" << max 
	<< " --> " << value << ")";
}

istream& operator>> (istream &in, SymbolCard &symbolCard) {
	in >> symbolCard.symbol;
	in >> symbolCard.min;
	in >> symbolCard.max;
	symbolCard.value = symbolCard.max;
	return in;
}

#endif
