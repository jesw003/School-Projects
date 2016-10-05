#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int PLAYER1 = 0;
const int PLAYER2 = 1;
const int WINNING_SCORE = 100;

void printIntro();
int humanTurn(string,int);


//FIXME (1): Implement the printIntro function
void printIntro() {
    cout<< "Welcome to the dice game Pig!"<<endl;
    cout<<"The objective is to be first to score 100 points."<<endl<<endl;
}

//FIXME (4, 5, 6): Implement the humanTurn function
int humanTurn (string playerName, int playerScore)
{
    int totalscore=0;
    cout<<endl<<playerName;
    int num =rand()% 6 + 1;
    
    if (num ==1)
    {
        cout<<endl<<"You rolled a 1 (PIG!)"<<endl;
        cout<<"Your turn is over";
        if (num !=1)
            
            cout<<endl<<"Your score: "<<playerScore<<endl;
    
        
    }
    else
    {
        cout<<endl<<"You rolled a "<<num;
        playerScore+=num;
        cout<<endl<<"Your score: "<<playerScore<<endl;
    }
    
    return playerScore;
}

int main()
{
    srand(4444);
    
    // setup and initialize variables
    int turn = PLAYER1;
    int player1score = 0;
    int player2score = 0;
    string player1name;
    string player2name;
    char newTurn;
    
    printIntro();
    
    // FIXME (2): get names of players
    cout<<"Player 1 - Enter your name: ";
    cin>>player1name;
    cout<<endl;
    cout<<"Player 2 - Enter your name: ";
    cin >>player2name;
    
    
    
    
    //play game
   while (player1score < WINNING_SCORE && player2score < WINNING_SCORE) {
        
        //player 1's turn or player 2's turn
        if (turn == PLAYER1) {
            player1score = humanTurn(player1name, player1score);
        }
        else {
            player2score = humanTurn(player2name, player2score);
        }
        
        //FIXME (3): switch whose turn it is
       if (turn == PLAYER1)
       {
           if (prevRoll==1)
           {
               turn = PLAYER2;
               prevRoll = 0;
           }
           else if (player1score < WINNING_SCORE)
           {
               cout<<"Do you want to roll again? (y/n): ";
               cin>>newTurn;
            if (newTurn == 'y')
                turn = PLAYER1;
            else
              {
                turn = PLAYER2;
                prevRoll = 0;
              }
           
            }
       
    }
       else if (turn ==PLAYER2)
       {
           if (prevRoll ==1)
           {
               turn =PLAYER1;
               prevRoll = 0;
           }
           else if (player2score < WINNING_SCORE)
           {
               cout<<"Do you want to roll again? (y/n): ";
               cin >>newTurn;
               if (newTurn =='y')
                   turn = PLAYER2;
               else
               {
                   turn =PLAYER1;
                   prevRoll =0;
               }
            }
        }
    }
    
    // FIXME (7): Output who won the game.
    if (player1score >=WINNING_SCORE)
        cout <<player1name<<"wins!"<<endl;
    else if (player2score >=WINNING_SCORE)
        cout <<player2name<<"wins!"<<endl;
    
    return 0;
}