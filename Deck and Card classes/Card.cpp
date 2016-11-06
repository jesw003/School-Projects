#include <iostream>
#include "Card.h"

using namespace std;


    /* Assigns a default value of 2 of Clubs
    */
Card::Card() {
    suit = 'c';
    rank = 2;
}


    /* Assigns the Card the suit and rank provided.
      suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
      If an invalid suit is provided, sets the suit to Clubs
      ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
      If an invalid rank is provided, sets the rank to 2
      Accepts lower or upper case characters for suit
    */  
Card::Card(char cardSuit, int cardRank) {
    suit = tolower(cardSuit);
    if (suit != 'c' && suit != 'd' && suit != 'h' && suit != 's') {
        suit = 'c';
    }
    rank = cardRank;
    if (rank < 1 || rank > 13) {
        rank = 2;
    }
}


    /* Returns the Card's suit
    */
char Card::getSuit() const{
    return suit;
}


    /* Returns the Card's rank as an integer
    */
int Card::getRank() const{
    return rank;
}


