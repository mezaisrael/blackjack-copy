#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "../headers/Player.h"

Player::Player(): name("n/a"), maxHit(0), hits(0), won(false), lost(true), tide(false) {}

void Player::displayStatistics() {

}

bool Player::canHit() {
	bool result = true;

	if(isBust()) {
		result = false;
	} else if (hand.total() > maxHit ) {
		result = false;
	}

	return result;
}

bool Player::isBust() {
	bool result = true;
	if( hand.total() > 31) {
		//try using low values if highes are busting
		hand.useSymCardsMin();
	} else {
		//total is less than the winning number(31)
		//hence busted is false
		result = false;
	}
	//check to see if total is still bust
	if ( hand.total() > 31) {
		result = true;
	}
	return result;
}

void Player::hitFrom(Deck &myDeck) {
	Card* dealedCard = myDeck.dealCard();
	hand.addCard(dealedCard);

	//add hit to player only if not the first card in hand
	if(hand.size() != 1) {
		hits++;
	}
}

void Player::setWon() {
	won = true;
	lost = false;
	tide = false;
}

void Player::setTide() {
	tide = true;
	won = false;
	lost = false;
}

void Player::setLost() {
	lost = true;
	won = false;
	tide = false;
}


istream& operator>> (istream &in, Player &player) {
	in >> player.name;
	in >> player.maxHit;

	return in;
}

//outputs "<Name>: (max Hit: <number>)"
ostream& operator<< (ostream &out, Player &player) {
	out << player.name 
	<< "(Max Hit: " << player.maxHit
	<< ")";

	return out;
}

#endif