//Brenden Bilson
//CECS 325-02
//Prog1 - Fibo Solitaire
//09/26/2023
//I certify that this program is my own original work. I did not copy any part of this program from any other source. I
//further certify that I typed each and every line of code in this program.

#include "card.h"

Card::Card()
{
	m_rank = 'X';
	m_suit = 'X';
	m_value = 0;
}

Card::Card(char r, char s)
{
	m_rank = r;
	m_suit = s;

	if (m_rank == 'A')
		m_value = 1;
	else if (m_rank == 'K' || m_rank == 'Q' || m_rank == 'J')
		m_value = 10;
	else
		m_value = int(m_rank) - 48;
}

int Card::getValue()
{
	return m_value;
}

void Card::show()
{
	std::cout << m_rank << m_suit;
}

