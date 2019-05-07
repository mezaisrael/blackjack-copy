/*Author: Israel Meza
JackBlack is a game siilar to BlackJack but to the palyer closes
to 31 wins. A Jackblack game uses number cards, word cards, and symbol.

JackBlackSimulator is the heart of the game. Its contructor takes
arguments passed from console input and use them to make the Deck
and Players.
*/

#ifndef JACKBLACKSIMULATOR_H
#define JACKBLACKSIMULATOR_H

#include <vector>
#include <fstream>
#include <string>
#include <queue>

#include "Deck.h"
#include "Player.h"
#include "Round.h"

using namespace std;

class JackBlackSimulator {
public:
  //take console input to create deck and players
  JackBlackSimulator(int argc, char const *argv[]);

  //Call this function when you want the game to start
  void startGame();
private:
	string deckFile; //deck file to use for deck
	string playersFile; //players file to use for players
	Deck myDeck; //deck used for game

  //rounds that will play in game.
  //Note that Hand data is not stored here 
  vector<Player> players;

  //holds all the rounds the game had. Responsible
  //for recording playes hand
  queue<Round> rounds;

  //-- Helper functions
  //returns true if game is over, false otherwise
  bool isGameOver() { return myDeck.size() <= 0; }

  //takes files and inputs data into deck and players
  void parseData();

  //starts a new round of jackblack
  void startRound();

  //display all rounds with palyers hand in each round
  void displayRounds();

  //dipalys a final tally of each player's standing in the round
  void finalTally();

  //display the game statistic (averages)
  void gameAnalysis();
  
  //gameAnalysis() helper finction
  void avrHitPerPlayerPerRound();

  //gameAnalysis() helper finction
  void avrNumOfCardInWinHand();

  //gameAnalysis() helper finction
  void avrNumOfCardInLosHand();

  //gameAnalysis() helper finction
  void avrNumOfCardTypes();
};

#endif
