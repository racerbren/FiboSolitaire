//Brenden Bilson
//CECS 325-02
//Prog1 - Fibo Solitaire
//09/26/2023
//I certify that this program is my own original work. I did not copy any part of this program from any other source. I
//further certify that I typed each and every line of code in this program.

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "card.h"

class Deck
{
private:
	std::vector<Card> m_deck;
	char m_ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	char m_suits[4] = {'S', 'H', 'D', 'C'};	
public:
	Deck();
	void newDeck();
	Card deal();
	void shuffle();
	bool isEmpty();
	void show();
};

#endif
