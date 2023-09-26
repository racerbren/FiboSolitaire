//Brenden Bilson
//CECS 325-02
//Prog1 - Fibo Solitaire
//09/26/2023
//I certify that this program is my own original work. I did not copy any part of this program from any other source. I
//further certify that I typed each and every line of code in this program.

#include "deck.h"

Deck::Deck()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			m_deck.push_back(Card(m_ranks[j], m_suits[i]));
		}
	}
}

void Deck::newDeck()
{
	std::vector<Card> temp;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			temp.push_back(Card(m_ranks[j], m_suits[i]));
		}
	}
	m_deck = temp;
}

Card Deck::deal()
{	
	Card dealtCard;
	if(!m_deck.empty())
	{
		dealtCard = m_deck[0];
		m_deck.erase(m_deck.begin());
	}
	//Else card is joker
	return dealtCard;
}

void Deck::shuffle()
{
	//Create a random seed  based on the time and create a temporary vector
	srand(time(0));
	std::vector<Card> temp;

	while(!m_deck.empty())
	{
		//Generate number between 0 and current size of deck
		int newSpot = rand() % m_deck.size();
		
		//Put the random card from the deck into the temporary vector and delete the card from the deck
		temp.push_back(m_deck[newSpot]);
		m_deck.erase(m_deck.begin() + newSpot);
	}
	//Make the deck the temporary deck
	m_deck = temp;
}

bool Deck::isEmpty()
{
	return m_deck.empty();
}

void Deck::show()
{
	Card currentCard;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			currentCard = m_deck[j + i * 13];
			currentCard.show();
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

