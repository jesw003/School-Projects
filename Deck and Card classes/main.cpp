#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Card.h"
#include "Deck.h"

using namespace std;

/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/
bool hasPair(const vector<Card> &);


/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream &, const vector<Card> &);



int main () {
    srand(2222);
    string userResponce;
    int cardsPerHand = 0;
    int numDeals = 0;
    // double pairChance = 0.0;
    int numPairs = 0;
    string fileName;
    ofstream outFile;
    
    //TODO if else statement for y/n
    //TODO put into functions! :D
    do {
    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> userResponce;
    cout << endl;
    }while(userResponce != "Yes" && userResponce != "No");
    
    if(userResponce == "Yes") {
        
        
        cout << "Enter name of output file: ";
        cin >> fileName;
        cout << endl;
        
        outFile.open(fileName.c_str());
        if(!outFile.is_open()) {
            cout << "Could not open file " << fileName << endl;
            return 1;
        }
    
         
    }
    
    
    cout << "Enter number of cards per hand: ";
    cin >> cardsPerHand;
    cout << endl;
    
    cout << "Enter number of deals (simulations): ";
    cin >> numDeals;
    cout << endl;
    
    Deck d;
    vector<Card> userDeck;
    for (int i = 0; i < numDeals; i++) {
        
        
        d.shuffleDeck();
        for (int j = 0; j < cardsPerHand; j++){
            userDeck.push_back(d.dealCard());
            //outFile << userDeck.at(j) << ", ";
        }
        
        if (hasPair(userDeck)){
            outFile << "Found Pair!! ";
            numPairs += 1;
        }
        else {
            outFile << "             ";
        }
        for (unsigned k = 0; k < userDeck.size(); k++) {
            outFile << userDeck.at(k);
            if (k + 1 < userDeck.size()) {
                outFile << ", ";
            }
        }
        
        
        //for (unsigned k = 0; k < userDeck.size(); k++) {
            // cout << "rank: " << userDeck.at(k).getRank << endl;
            // cout << "suit: " << userDeck.at(k).getSuit << endl;
            //cout << userDeck.at(k) << endl;
        //}
        //cout <<"qpweripqewirqpweir****" << endl;
        // for (unsigned k = userDeck.size() - 1; k > 1; k--) {
        //     if (userDeck.at(k).getRank() == userDeck.at(k - 1).getRank()) {
        //         numPairs += 1;
        //         cout << "******" << i << "******" << endl;
        //         cout << "rank 1st: " << userDeck.at(k).getRank() << " | ";
        //         cout << "rand 2nd: " << userDeck.at(k - 1).getRank() << " | ";
        //         cout << "Num pairs now: " << numPairs << endl << endl;
                
        //     }
        // }
        userDeck.clear();
        outFile << endl;
    }
    
    
    
    cout << "Chances of receiving a pair in a hand of " << cardsPerHand
         << " cards is: "
         << static_cast<double>(numPairs) / numDeals * 100 << '%' << endl;
        
    
    
   
    outFile.close();
    
    return 0;
}

bool hasPair(const vector<Card> &v) {
    for (unsigned i = 0; i + 1 < v.size(); i++) {
        for(unsigned j = i + 1; j < v.size(); j++) {
            if(v.at(i).getRank() == v.at(j).getRank())  {
                return true;
            }
        }
    }
    return false;
}


ostream & operator<<(ostream & os, const Card &userCard) {
    string suitName, cardName;
    
    //tanslate suit char to propper suit name
    if (userCard.suit == 'c') {
        suitName = "Clubs";
    }
    else if (userCard.suit == 'd') {
        suitName = "Diamonds";
    }
    else if (userCard.suit == 'h') {
        suitName = "Hearts";
    }
    else {
        suitName = "Spades";
    }
    if (userCard.rank == 1 || userCard.rank == 11 || userCard.rank == 12 || userCard.rank == 13) {
    
    //tanslate face cards to propper name
        if (userCard.rank == 1) {
            cardName = "Ace";
        }
        else if (userCard.rank == 11) {
            cardName = "Jack";
        }
        else if (userCard.rank == 12) {
            cardName = "Queen";
        }
        else {
            cardName = "King";
        }
        
        os << cardName << " of " << suitName;
    }
    else {
        os << userCard.rank << " of " << suitName;
    }

    return os;
}

ostream & operator<<(ostream &os, const vector<Card> &v) {
    if (v.size() > 0) {
        for (unsigned i = 0; i + 1 < v.size(); i++) {
            os << v.at(i) << ", ";
        }
        os << v.at(v.size() - 1);
    }
    return os;
}