#ifndef HAND_CPP
#define HAND_CPP

#include "../headers/Hand.h"


void Hand::addCard(Card* card) {
	//pointing to symbol cards in a 
	//different vector makes it easier to
	//change their value when needed
	if (card->getType() == 'S') {
		SymbolCard* symCard = dynamic_cast<SymbolCard*>(card);
		symbolCards.push_back(symCard);
	}

	//tally type of card for game analysis
	if (card->getType() == 'N'){
		totalNumberCards++;
	}else if(card->getType() == 'W'){
		totalWordCards++;
	}
	cards.push_back(card);
}

int Hand::total() {
	int sum = 0;
	for (unsigned int i = 0; i < cards.size(); ++i) {
		sum += cards.at(i)->getValue();
	}

	return sum;
}

//a player can decide to switch if he want to
// use symbol cards low values
void Hand::useSymCardsMin() {
	for (unsigned  int i = 0; i < symbolCards.size(); ++i) {
		symbolCards.at(i)->useLowValue();
	}
}

ostream& operator<<(ostream &out, const Hand &hand) {
	//out << "player has "<< hand.cards.size() << " cards";
	Card *currentCardPtr;
	for (unsigned int i= 0; i < hand.cards.size(); i++) {
		//TODO: implement showCard() with polymorphism
		currentCardPtr = hand.cards.at(i);
		currentCardPtr->printCard();
		cout <<", "; 
	}
	return out;
}

#endif