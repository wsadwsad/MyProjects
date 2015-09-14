#include <iostream>
#include <string>

using namespace std;

#include "card.h"

const int num1 = 13;
const int num2 = 4;
string cardarray[num1] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
string suitarray[num2] = {"s","h","d","c"};

Card::Card()
{
	myRank = 1;
	mySuit = spades;
}

Card::Card(int rank, Suit s)
{
	myRank = rank;
	mySuit = s;
}

string Card::toString() const
{
	return cardarray[myRank - 1] + suitarray[mySuit];
}

bool Card::sameSuitAs(const Card& c) const
{
	if (c.mySuit == mySuit)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Card::getRank() const
{
	return myRank;
}

string Card::suitString(Suit s) const
{
	return suitarray[s];
}

string Card::rankString(int r) const
{	
	if (r > 13 || r < 1)
	{
		cout << "This card is invalid!" << endl;
	}
	else
	{
		return cardarray[r - 1];
	}
}

bool Card::operator ==(const Card& rhs) const
{
	return (rhs.myRank == myRank &&
	        rhs.mySuit == mySuit);
}

bool Card::operator !=(const Card& rhs) const
{
	return !(rhs.myRank == myRank &&
	         rhs.mySuit == mySuit);
}

ostream& operator << (ostream& out, const Card& c)
{
	out << c.toString();
	return out;
}
