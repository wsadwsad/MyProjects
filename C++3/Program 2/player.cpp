#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "player.h"
#include "card.h"

void Player::addCard(Card c)
{
	myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2)
{
	myBook.push_back(c1);
	myBook.push_back(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2)
{
	if (c1.getRank() == c2.getRank())
	{
		myBook.push_back(c1);
		myBook.push_back(c2);
		
		for (int i = 0; i < myHand.size(); i++)
		{
			if (myHand[i] == c1)
			{
				myHand.erase(myHand.begin() + i);
			}
			if (myHand[i] == c2)
			{
				myHand.erase(myHand.begin() + i);
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::rankInHand(Card c) const
{
	for (int i = 0; i < myHand.size(); i++)
	{
		Card ctemp = myHand[i];
		if ( ctemp.getRank() == c.getRank() )
		{
			return true;
		}
	}
	return false;
}

Card Player::chooseCardFromHand() const
{
	Card temp = myHand[rand() % myHand.size()];
	return temp;
}

bool Player::cardInHand(Card c) const
{
	for (int i = 0; i < myHand.size(); i++)
	{
		Card ctemp = myHand[i];
		if (ctemp == c)
		{
			return true;
		}
	}
	return false;
}

Card Player::removeCardFromHand(Card c)
{
	for (int i = 0; i < myHand.size(); i++)
	{
		Card ctemp = myHand[i];
		if ( ctemp.getRank() == c.getRank() )
		{
			myHand.erase(myHand.begin() + i);
			return ctemp;			
		}
	}
}

string Player::showHand() const
{
	string stemp;
	for (int i = 0; i < myHand.size(); i++)
	{
		Card ctemp = myHand[i];
		stemp.append(ctemp.toString());
		stemp.append(" ");
	}
	return stemp;
}

string Player::showBooks() const
{
	string stemp;
	for (int i = 0; i < myBook.size(); i++)
	{
		Card ctemp = myBook[i];
		stemp.append(ctemp.toString());
		stemp.append(" ");
	}
	return stemp;
}

int Player::getHandSize() const
{
	return myHand.size();
}

int Player::getBookSize() const
{
	return myBook.size();
}

bool Player::checkHandForPair(Card &c1, Card &c2)
{
	if (c1.getRank() == c2.getRank())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::sameRankInHand(Card c) const
{
	for (int i = 0; i < myHand.size(); i++)
	{
		Card ctemp = myHand[i];
		if ( ctemp.getRank() == c.getRank() )
		{
			return true;
		}
	}
	return false;
}

bool Player::checkPairFromHand()
{
	if (myHand.size() > 1)
	{
		for (int i = 0; i < myHand.size()-1; i++)
		{
			Card c1 = myHand[i];
		
			for (int j = i+1; j < myHand.size(); j++)
			{
				Card c2 = myHand[j];
			
				if (c1.getRank() == c2.getRank())
				{
					myBook.push_back(c1);
					myBook.push_back(c2);
		        
					myHand.erase(myHand.begin() + i);
					myHand.erase(myHand.begin() + (j - 1));
					return true;
				}
			}
		}
	}
	return false;
}
