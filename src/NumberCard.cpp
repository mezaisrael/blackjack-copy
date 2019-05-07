#ifndef NUMBERCARD_CPP
#define NUMBERCARD_CPP

#include "../headers/NumberCard.h"

istream& operator>> (istream &in, NumberCard &numberCard) {
	in >> numberCard.value;
	return in;
}

// ostream& operator<< (ostream &out, NumberCard &numberCard) {
// 	out << numberCard.value << endl;
// 	return out;
// }

#endif