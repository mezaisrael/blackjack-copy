#ifndef ROUND_H
#define ROUND_H

#include <vector>
#include "Deck.h"
#include "Player.h"

class Round
{
public:
	Round(vector<Player> _players);
	//@param players is a copy of players that will be in the round.
	//@param deck is a reference to Deck object.
	// void startWith(vector<Player> players, Deck &deck);
	void displayRound();

	//determines who won or tide in the round
	void getRoundResult();

	//@param i is the index position of player you want to retreive 
	//from the round
	Player playerAt(int i) { return players.at(i); }

	//returns the total amount of hits in the round
	int getHits();
	Player getWinner() { return winner; }
	bool didEndInWin() { return winnerInRound;}
private:
	//a round is a vector of Players
	//each element coresponds to a player 
	vector<Player> players;
	bool winnerInRound;
	Player winner;
};


#endif