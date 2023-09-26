//Brenden Bilson
//CECS 325-02
//Prog1 - Fibo Solitaire
//09/26/2023
//I certify that this program is my own original work. I did not copy any part of this program from any other source. I
//further certify that I typed each and every line of code in this program.

#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card
{
private:
	int m_value;
	char m_rank;
	char m_suit;
public:
	Card();
	Card(char, char);
	int getValue();
	void show();	
};

#endif
