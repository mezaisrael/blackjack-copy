#ifndef JACKBLACKSIMULATOR_cpp
#define JACKBLACKSIMULATOR_cpp

#include "../headers/JackBlackSimulator.h"

//the constructor determines what files will be used for the game
JackBlackSimulator::JackBlackSimulator(int argc, char const *argv[]) {
	deckFile = "../defaultDeck.data";
	playersFile = "../defaultPlayers.data";

	//if only no arguments are passed in
	//in console use default files
	if (argc == 1) {
		cout << "No deck file provided. Using default deck file instead" << endl;
		cout << "No file file provided. Using default player file instead" << endl;
	}//else if only deck file was passed
	else if(argc == 2) {
		deckFile = argv[1];
		cout << "No file file provided. Using default player file instead" << endl;
	} //if both files were provided in console input
	else {
		deckFile = argv[1];
		playersFile = argv[2];
	}
	//pase data from files
	parseData();
}

void JackBlackSimulator::parseData () {
	ifstream fin;
    fin.open(deckFile);

    cout << deckFile << endl;

    if (fin.fail()) {
      cerr << "Error while openin deck file. Make sure the path is correct" << endl;
    }
    //insert data to deck
    fin >> myDeck;
    fin.close(); 
    //now parse the players file
    fin.open(playersFile);

    if (fin.fail()) {
      cerr << "Error while opening player file. Make sure the path is correct" << endl;
    }
    int numOfPlayers;
    fin >> numOfPlayers;

    Player currentPlayer;
    for (int i = 0; i < numOfPlayers; ++i) {
    	fin >> currentPlayer; //inputs name and max Hit to player
    	players.push_back(currentPlayer);
    }
}

void JackBlackSimulator::startGame() {
	cout << "Running simulation with players: " << endl;
	for (unsigned int i = 0; i < players.size(); ++i) {
		cout << players.at(i) <<endl;
	}

	cout << endl;
	while (!isGameOver()){
		startRound();
	}
	displayRounds();
	finalTally();
	gameAnalysis();
}

void JackBlackSimulator::startRound() {
	vector<Player> playersInRound = players; //playersInRound should start with clean hand 
	Player *currentPlayerPtr; //using pointer make it easy to build info and add to round
	
	//loop through every player so they can get a turn to hit
	for (unsigned int i = 0; i < playersInRound.size(); ++i) {
		currentPlayerPtr = &playersInRound.at(i);

		while(currentPlayerPtr->canHit() && !isGameOver()) {
			currentPlayerPtr->hitFrom(myDeck);		
		}
	}


	Round round(playersInRound);
	round.getRoundResult();
	//record players hand info in Round
	//only if game is not over
	if(!isGameOver()){
		rounds.push(round);
	}
}

void JackBlackSimulator::displayRounds() {
	queue<Round> _rounds = rounds;
	for (unsigned int i = 0; i < rounds.size(); ++i) {
		cout << "ROUND " << i+1 << endl;
		_rounds.front().displayRound();
		_rounds.pop();
	}
}

void JackBlackSimulator::finalTally() {
	int wins = 0;
	int losses = 0;
	int ties = 0;
	Round *currRound;
	queue<Round> _rounds;
	//loop over every player and tally whether he/she lost
	for (unsigned int i = 0; i < players.size(); ++i) {
		wins = 0;
		losses = 0;
		ties = 0;

		_rounds = rounds;
		for (unsigned int j = 0; j < rounds.size(); ++j) {
			currRound = &_rounds.front();
			if(currRound->playerAt(i).didWin()){
				wins++;
			} else if (currRound->playerAt(i).didTie()) {
				ties++;
			} else {
				losses++;
			}
			_rounds.pop();
		}
		cout << players.at(i).getName() << ". "
		<< "wins: "<< wins
		<< " LOSSES: "<< losses
		<< " TIES: "<< ties << ". " << endl;
	}
}

void JackBlackSimulator::gameAnalysis() {
	avrHitPerPlayerPerRound();
	avrNumOfCardInWinHand();
	avrNumOfCardInLosHand();

	cout << endl;
	avrNumOfCardTypes();
}

void JackBlackSimulator::avrHitPerPlayerPerRound() {
	double totalHits = 0;
	queue<Round> _rounds = rounds;

	//get total hits
	for (unsigned int i = 0; i < _rounds.size(); ++i) {
		totalHits += _rounds.front().getHits();
		_rounds.pop();
	}
	double avrHit = totalHits/players.size()/rounds.size();
	cout << "Average number of hits per player per round: " << avrHit << endl;
}

void JackBlackSimulator::avrNumOfCardInWinHand() {
	double numOfCardsInWinHand = 0;//average formula numerator
	int roundsWithWins = 0; //average formula denominator
	queue<Round> _rounds = rounds;//get a copy of rounds
	Player roundWinner;
	
	//get total
	for (unsigned int i = 0; i < rounds.size(); ++i) {
		if (_rounds.front().didEndInWin()){
			roundWinner = _rounds.front().getWinner();
			numOfCardsInWinHand += roundWinner.getHand().size();
			roundsWithWins++;
		}
		_rounds.pop();
	}
	double average = numOfCardsInWinHand/roundsWithWins;
	cout << "Average number of cards in winning hand ";

	if (roundsWithWins == 0){
		cout << "Undefine. no winners in game" << endl;
	} else {
		cout << average << endl;
	}
}

void JackBlackSimulator::avrNumOfCardInLosHand() {
	double CardsInLoserHand = 0;
	queue<Round> _rounds = rounds;
	Player currentPlayer;

	int amountOfLosers;
	//loop through round
	for (unsigned int i = 0; i < rounds.size(); ++i) {
		//loop through player to see the size of losing hand
		for (unsigned int j = 0; j < players.size(); ++j) {
			currentPlayer = _rounds.front().playerAt(j);
			if(currentPlayer.didLose()){
				CardsInLoserHand += currentPlayer.getHand().size();
				amountOfLosers++;
			}
		}
		_rounds.pop();
	}
	double average = CardsInLoserHand/amountOfLosers;
	cout << "Average number of cards in losing hands " << average << endl;
}

void JackBlackSimulator::avrNumOfCardTypes() {
	double numberCards = 0;
	double symbolCards = 0;
	double wordCards = 0;

	queue<Round> _rounds = rounds;
	int roundsWithWinner = 0;
	for (unsigned int i = 0; i < rounds.size(); ++i) {
		if(_rounds.front().didEndInWin()) {
			roundsWithWinner ++;
			Hand winnerHand = _rounds.front().getWinner().getHand();
			numberCards += winnerHand.totNumCards();
			symbolCards += winnerHand.totSymCards();
			wordCards += winnerHand.totWordCards();
		}
		_rounds.pop();
	}
	double avrNum = numberCards/roundsWithWinner;
	double avrWord = wordCards/roundsWithWinner;
	double avrSym = symbolCards/roundsWithWinner;
	if(roundsWithWinner == 0) {
		cout << "No winner in round. Cant calculate average with no winning hand" << endl;
	}
	cout<< "Average number of number cards in winning hand " << avrNum << endl;
	cout<< "Average number of word cards in winning hand " << avrWord << endl;
	cout<< "Average number of symbol cards in winning hand " << avrSym << endl;
}

#endif