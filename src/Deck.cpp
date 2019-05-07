#ifndef DECK_CPP
#define DECK_CPP

#include "../headers/Deck.h"


Card* Deck::dealCard() {
	Card *nextCard = cards.top();
	 	cards.pop();
		return nextCard;
}

int Deck::size() {
	return cards.size();
}

istream& operator>> (istream &in, Deck &deck) {
	int numOfCards;
	in >> numOfCards;

	//in.ignore();

	NumberCard *numCardptr;
	SymbolCard *symCardptr;
	WordCard *wordCardptr;
	for (int i = 0; i < numOfCards; ++i) {
		char typeOfCard;
		in >> typeOfCard;
		
		switch (typeOfCard) {
			case 'N':
				numCardptr = new NumberCard;
				in >> *numCardptr;
				deck.cards.push(numCardptr);
				break;
			case 'S':
				symCardptr = new SymbolCard;
				in >> *symCardptr;
				deck.cards.push(symCardptr);
				break;
			case 'W':
				wordCardptr = new WordCard;
				in >> *wordCardptr;
				deck.cards.push(wordCardptr);
				break;
		}
	}

	cout << "there are " << numOfCards << " added to deck" << endl;
	return in;
}

#endif