//go_fish.cpp
//  Jie Zhou

//Rule of the game!
//At the begining of a game, each player deals 7 cards to hands, then players call or deal cards. 
//If players have a pair of cards with same rank, book the cards.
//The player who has the most cards in book win,
//or draw if they both have same number of cards in book  

#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main( )
{
    int numCards = 7;
    cout << "Go Fish!\n" << endl;
    
    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards

    d.shuffle();
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
	
    bool go_on = true;
    
    bool checkpair1 = true;
   	bool checkpair2 = true;
   
    do
    { 	 	
    	do							//check if there are some pairs of cards with same rank in hand
		{
			checkpair1 = p1.checkPairFromHand(); //book cards if they are same rank
		}while(checkpair1);
    	
    	do							//check if there are some pairs of cards with same rank in hand
    	{
			checkpair2 = p2.checkPairFromHand(); //book cards if they are same rank
    	}while(checkpair2);
		
		if ((p1.getHandSize() == 0) && (d.size() == 0))
		{
			if (p1.getBookSize() > p2.getBookSize())
    		{
    			cout << p1.getName() << "  books: " << p1.getBookSize() / 2 << " pairs cards." << endl;
				cout << p2.getName() << " books: " << p2.getBookSize() / 2 << " pairs cards.\n" << endl;
    			cout << p1.getName() << " win!\n" << endl;
    		}
    		else if (p2.getBookSize() > p1.getBookSize())
    		{
    			cout << p2.getName() << " books: " << p2.getBookSize() / 2 << " pairs cards." << endl;
				cout << p1.getName() << "  books: " << p1.getBookSize() / 2 << " pairs cards.\n" << endl;
    			cout << p2.getName() << " win!\n" << endl;
    		}
    		else
    		{
    			cout << p1.getName() << "  books: " << p1.getBookSize() / 2 << " pairs cards." << endl;
				cout << p2.getName() << " books: " << p2.getBookSize() / 2 << " pairs cards.\n" << endl;
    			cout << "They book same number of cards! DRAW!\n" << endl;
    		}
    		go_on = false;
		}
		else 
		{
			if ((p1.getHandSize() == 0) && (d.size() != 0))
			{
				p1.addCard(d.dealCard());
			}
		
			Card c1 = p1.chooseCardFromHand(); //choose a card randomly for call

			cout << p1.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << " ?" << endl;
    	
			if (p2.rankInHand(c1)) 			//check if player has a card with same rank
    		{
   		 		cout << p2.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << " ." << endl;
    			p1.bookCards(p1.removeCardFromHand(c1), p2.removeCardFromHand(c1));		//book cards with same rank
    			
				cout << p1.getName() << " books the " << c1.rankString(c1.getRank()) << "\n" << endl; 
    		}
  
    		else
    		{
    			cout << p2.getName() << " says - Go fish" << endl;
    			
				if (d.size() != 0)
				{
					c1 = d.dealCard();			//deal a card			
					cout << p1.getName() << " draws " << c1.toString() << "\n" << endl;					

					if(p1.rankInHand(c1))		//check if player has a card has the same rank with the card just be dealed
    				{
    					p1.bookCards(c1, p1.removeCardFromHand(c1));

						if ((p1.getHandSize() == 0) && (d.size() != 0))
						{
							p1.addCard(d.dealCard());
						}		
    					
    				}
	    			else
    				{
    					p1.addCard(c1);			//add the card to hand
    				}
				}
				else
				{
					cout <<"\n";
				}
				
				bool p2go_on = true;
				
				do
    			{
    				do							//check if there are some pairs of cards with same rank in hand
					{
						checkpair1 = p1.checkPairFromHand(); //book cards if they are same rank
					}while(checkpair1);
    		
    				do							//check if there are some pairs of cards with same rank in hand
    				{
						checkpair2 = p2.checkPairFromHand(); //book cards if they are same rank
    				}while(checkpair2);
					
					if ((p2.getHandSize() == 0) && (d.size() == 0))
					{
						if (p1.getBookSize() > p2.getBookSize())
    					{
    						cout << p1.getName() << "  books: " << p1.getBookSize() / 2 << " pairs cards." << endl;
							cout << p2.getName() << " books: " << p2.getBookSize() / 2 << " pairs cards.\n" << endl;
    						cout << p1.getName() << " win!\n" << endl;
    					}
    					else if (p2.getBookSize() > p1.getBookSize())
    					{
    						cout << p2.getName() << " books: " << p2.getBookSize() / 2 << " pairs cards." << endl;
							cout << p1.getName() << "  books: " << p1.getBookSize() / 2 << " pairs cards.\n" << endl;
    						cout << p2.getName() << " win!\n" << endl;
    					}
    					else
    					{
    						cout << p1.getName() << "  books: " << p1.getBookSize() / 2 << " pairs cards." << endl;
							cout << p2.getName() << " books: " << p2.getBookSize() / 2 << " pairs cards.\n" << endl;
    						cout << "They book same number of cards! DRAW!\n" << endl;
    					}
   						p2go_on = false;
   						go_on = false;
					}
					else 
					{
						if ((p2.getHandSize() == 0) && (d.size() != 0))
						{
							p2.addCard(d.dealCard());
						}
		
						Card c2 = p2.chooseCardFromHand(); //choose a card randomly for call
 
 						cout << p2.getName() << " asks - Do you have a " << c2.rankString(c2.getRank()) << " ?" << endl;
   	
						if (p1.rankInHand(c2)) 			//check if player has a card with same rank
						{				
   						
   	 						cout << p1.getName() << " says - Yes. I have a " << c2.rankString(c2.getRank()) << " ." << endl;
   							p2.bookCards(p2.removeCardFromHand(c2), p1.removeCardFromHand(c2));		//book cards with same rank
   			
							cout << p2.getName() << " books the " << c2.rankString(c2.getRank()) << "\n" << endl; 
   						}
   						else
   						{  						
   							cout << p1.getName() << " says - Go fish" << endl;
   							p2go_on = false;

							if (d.size() != 0)
							{
								c2 = d.dealCard();			//deal a card			
								cout << p2.getName() << " draws " << c2.toString() << "\n" << endl;					
   		
								if(p2.rankInHand(c2))		//check if player has a card has the same rank with the card just be dealed
   								{
   									p2.bookCards(c2, p2.removeCardFromHand(c2));
								
									if ((p2.getHandSize() == 0) && (d.size() != 0))
									{
										p2.addCard(d.dealCard());
									}		
   								}
    							else
   								{
   									p2.addCard(c2);			//add the card to hand
   								}	
							}
							else
							{
								cout <<"\n";
							}
						}
					}
	   			}while(p2go_on);
    		}
		}
    }while(go_on);
    

    system("PAUSE");
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
   {
      p.addCard(d.dealCard());
   }
}
   



