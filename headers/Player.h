#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"

class Player {
public:
	Player();
	string getName() { return name; }
	void displayStatistics();
	void hitFrom(Deck &myDeck);
	bool canHit();
	bool isBust();

	//return Hand
	Hand getHand() { return hand; }

	//returns amount of times player hit in a round
	int getHits() { return hits; }
	void setWon();
	void setTide();
	void setLost();
	bool didWin(){ return won;}
	bool didTie() { return tide;}
	bool didLose() { return lost; }
	friend istream& operator>> (istream &in, Player &Player);
	friend ostream& operator<< (ostream &out, Player &player); 
private:
	string name;
	int maxHit;
	int hits;
	bool won;
	bool lost;
	bool tide;
	Hand hand;
};

#endif