#include <iostream>
#include "Card.h"
#include "Deck.h"
#include <algorithm>

using namespace std;
    
    
    /* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades.
    */
Deck::Deck() {
    Card cardInDeck;
    char suitChar = 's';
    
    for (int i = 13; i > 0; i--) {
        cardInDeck = Card(suitChar, i);
        theDeck.push_back(cardInDeck);
        // cout << cardInDeck << endl;
    }
    suitChar = 'h';
    for (int i = 13; i > 0; i--) {
        cardInDeck = Card(suitChar, i);
        theDeck.push_back(cardInDeck);
        // cout << cardInDeck << endl;
    }
    suitChar = 'd';
    for (int i = 13; i > 0; i--) {
        cardInDeck = Card(suitChar, i);
        theDeck.push_back(cardInDeck);
        // cout << cardInDeck << endl;
    }
    suitChar = 'c';
    for (int i = 13; i > 0; i--) {
        cardInDeck = Card(suitChar, i);
        theDeck.push_back(cardInDeck);
        // cout << cardInDeck << endl;
    }
}

    /* Deals (returns) the top card on the deck. 
       Removes this card from theDeck and places it in the dealtCards.
    */
Card Deck::dealCard(){
    dealtCards.push_back(theDeck.back());
    theDeck.pop_back();
    return dealtCards.back();
}


    /* Places all cards back into theDeck and shuffles them into random order.
       Uses random_shuffle function from algorithm standard library.
    */
void Deck::shuffleDeck() {
    // Card cardFromDealt;
    // // if (dealtCards.size() > 0) {
    // //     for (unsigned i = dealtCards.size() - 1; dealtCards.size() > 0; i--) {
    // //         cardFromDealt = Card(dealtCards.at(i).getRank(), dealtCards.at(i).getSuit());
    // //         theDeck.push_back(cardFromDealt);
    // //         dealtCards.pop_back();
    // //     }
    // // }
    
    // while (dealtCards.size() > 0) {
    //     theDeck.push_back(dealtCards.back());
    //     dealtCards.pop_back();
    // }
    
    for (unsigned i = 0; i < dealtCards.size(); i++) {
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards.clear();
    
    random_shuffle(theDeck.begin(), theDeck.end());
}


    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
unsigned Deck::deckSize() const {
    return theDeck.size();
}