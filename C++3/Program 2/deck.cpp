#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

#include "deck.h"
#include "card.h"

Deck::Deck()
{	
	int cardnumber = 0;
	for (int i = 0; i < 4; i++)	
	{
		for (int j = 1; j <= 13; j++)
		{
			Card c(j, (Card::Suit) i);
			myCards[cardnumber] = c;
			cardnumber++;	
		}
	}
	myIndex = 0;
}

void Deck::shuffle()
{
	Card temp;
	myIndex = 0;
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		int n = rand() % 52;
		temp = myCards[i];
		myCards[i] = myCards[n];
		myCards[n] = temp;			
	}
}

Card Deck::dealCard()
{	
	int n = myIndex;	
    myIndex++;
	return myCards[n];
}

int Deck::size() const
{
	return 52 - myIndex;
}
