#ifndef ROUND_cpp
#define ROUND_cpp

#include "../headers/Round.h"

//constructor takes in vector of players
Round::Round(vector<Player> _players) {
	players = _players;
	winnerInRound = true;
}


void Round::displayRound() {
	Player currentPlayer;
	// loop diplayes hand of each player
	for (unsigned int i = 0; i < players.size(); ++i) {
		currentPlayer = players.at(i);
		cout << currentPlayer.getName() << ": " 
		<< currentPlayer.getHand()
		<< " Total: " << currentPlayer.getHand().total();
		if (currentPlayer.isBust()) {
			cout << " (Bust)";
		}

		cout << endl;
	}

	// this loop displays the winner or ties of the round
	string roundResult;
	winnerInRound? roundResult = "WINNER: " : roundResult = "TIDE: ";
	for (unsigned int i = 0; i < players.size(); ++i) {
		currentPlayer = players.at(i);

		if (currentPlayer.didWin()){
			roundResult += currentPlayer.getName();
		} else if(currentPlayer.didTie()) {
			roundResult += currentPlayer.getName();
			if((i + 1) != players.size()) {
				roundResult +=  ", ";
			}
		}
	}

	cout << roundResult <<"\n" << endl;
}

void Round::getRoundResult() {
	int highestScore = 0;
	Player *winner;

	int playersHandTotal; 
	for (unsigned int i = 0; i < players.size(); ++i) {
		playersHandTotal = players.at(i).getHand().total();
		if(playersHandTotal > highestScore && !players.at(i).isBust()) {
			highestScore = playersHandTotal;
			winner = &players.at(i);
		}
	}

	//now that we have winner check if anyone tide with him/her
	for (unsigned int i = 0; i < players.size(); ++i) {
		playersHandTotal = players.at(i).getHand().total();
		if(winner != &players.at(i)) {
			if (players.at(i).getHand().total() == highestScore) {
				winnerInRound = false;
				players.at(i).setTide();
				winner->setTide();
			}
		}
	}

	if(!winnerInRound) {
		//if winner tide(no winner). change status
		winner->setTide();
	} else {
		winner->setWon();
		this->winner = *winner;
	}
}

int Round::getHits(){
	int totalHitsInRound = 0;
	for (unsigned int i = 0; i < players.size(); ++i) {
		totalHitsInRound += players.at(i).getHits();
	}
	return totalHitsInRound;
}

#endif
