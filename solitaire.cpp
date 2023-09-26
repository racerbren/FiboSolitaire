//Brenden Bilson
//CECS 325-02
//Prog1 - Fibo Solitaire
//09/26/2023
//I certify that this program is my own original work. I did not copy any part of this program from any other source. I
//further certify that I typed each and every line of code in this program.

#include "card.h"
#include "deck.h"

int main()
{
	Deck deck;
	std::vector<int> fiboNumbers = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};
	int gamesPlayed = 0;
	bool quit = false;	
	while(!quit)
	{
		int run = false;
		int win = false;

		std::cout << "Welcome to Fibonacci Solitaire!" << std::endl;
		std::cout << "1) Create New Deck" << std::endl;
		std::cout << "2) Display Deck" << std::endl;
		std::cout << "3) Shuffle Deck" << std::endl;
		std::cout << "4) Play Fibo Solitaire" << std::endl;
		std::cout << "5) Win Fibo Solitaire" << std::endl;
		std::cout << "6) Exit" << std::endl;

		int choice;
		std::cin >> choice;

		switch (choice)
		{
			case 1:
				std::cout << "Creating a new deck..." << std::endl;
				deck.newDeck();
				break;
			case 2:
				deck.show();
				break;
			case 3:
				deck.shuffle();
				std::cout << "Deck shuffled." << std::endl;
				break;
			case 4:
				std::cout << "Playing Fibonacci Solitare!!!" << std::endl << std::endl;
				run = true;
				break;
			case 5: 
				run = true;
				win = true;
				break;
			case 6:
				std::cout << "Quiting..." << std::endl;
				quit = true;
				break;
		}
		
		int piles = 1;
		int fiboSum = 0;
		bool winner = false;
		while (run)
		{
			Card dealtCard = deck.deal();
			fiboSum += dealtCard.getValue();
			dealtCard.show();
			std::cout << ", ";

			bool isFibo = false;
			for (int i = 0; i < fiboNumbers.size(); i++)
			{
				if (fiboSum == fiboNumbers[i])
				{
					isFibo = true;
					i = fiboNumbers.size();
			
				}
			}
			
			if (isFibo)
			{
				std::cout << "Fibo: " << fiboSum << std::endl;
				fiboSum = 0;
				piles++;
			}

			if (deck.isEmpty() && !isFibo)
			{
				gamesPlayed++;
				std::cout << std::endl << "Last pile NOT FIBO: " << fiboSum << std::endl;
				std::cout << std::endl << "Loser in " << piles << " piles!" << std::endl;
				std::cout << "Games Played: " << gamesPlayed << std::endl;
				deck.newDeck();
				deck.shuffle();
				fiboSum = 0;
				piles = 1;
				if(!win)
					run = false;

				//Uncomment this part for better chances at winning
				/*if(gamesPlayed > 200)
				{
					gamesPlayed = 0;
					std::cout << "Too many games played. Start over." << std::endl;
					run = false;
				}*/
			}
			else if (deck.isEmpty() && isFibo)
			{
				gamesPlayed++;
				std::cout << std::endl << "Winner in " << piles << " piles!" << std::endl;
				std::cout << "Games Played: " << gamesPlayed << std::endl;
				deck.newDeck();
				deck.shuffle();
				run = false;
			}
		}
	}	

	return 0;
}
