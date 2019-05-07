#ifndef WORDCARD_CPP
#define WORDCARD_CPP

#include "../headers/wordCard.h"

int WordCard::getValFromWord() {
	int val = 0;

	for(unsigned int i = 0; i < word.size(); i++) {
		//add 2 if the letter is a vowel, otherwise add 1
		isVowel(word[i]) ? val += 2 : val++;
	}
	
	return (val % 16) + 1;
}

bool WordCard::isVowel(char target) {
	string vowels = "aeiou";

	for (int i = 0; i < 5; ++i)
	{
		if (vowels[i] == target ) {
			return true;
		}
	}

	return false;
}

istream& operator>> (istream &in, WordCard &wordCard) {
	in >> wordCard.word;
	wordCard.value = wordCard.getValFromWord();
	
	return in;
}

ostream& operator<< (ostream &out, WordCard &wordCard) {
	out << wordCard.word << "(" << wordCard.value <<")" ;
	return out;	
}

#endif