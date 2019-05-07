#ifndef WORDCARD_H
#define WORDCARD_H value

#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

class WordCard : public Card
{
public:
	WordCard() : Card('W') {}
	int getValue() { return value; }
	void printCard() {cout << word << " (" << value <<")"; }
	friend istream& operator>> (istream &in, WordCard &wordCard);
	friend ostream& operator<< (ostream &out, WordCard &wordCard);
	
private:
	int value;
	string word;
	int getValFromWord();
	bool isVowel(char target);
};
#endif