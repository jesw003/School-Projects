#include <iostream>
#include <vector>
using namespace std;

const bool CLEAR_SCREEN = true;

void clearScreen()
{
    cout << endl;

    if (CLEAR_SCREEN)
    {
        cout << "\033c";
    }

    cout << endl;
}

void drawBoard(const vector <char> &gameboard)
{
    clearScreen();
    for (int i = 0; i < 9; i += 3)
    {
        cout << "  " << gameboard.at(i) << "  |  " << gameboard.at(i + 1) << "  |  "
            << gameboard.at(i + 2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
   
}

// lab grade
void initVector(vector<char>& v)
{
    for(unsigned int i = 0; i < v.size(); i++)
    {
        v.at(i) = 'a' + i;
    }
}

// converts a character representing a cell to associated vector index
int convertPosition(char position)
{
    int index;
    index = position - 'a';
    return index;
}

// predicate function to determine if a spot in board is available.
bool validPlacement(const vector <char> &gameboard, unsigned int position)
{
    if(gameboard.size() == 0 && position == 0)
    {
        return true;
    }
    if(position >= gameboard.size() || position < 0)
    {
        return false;
    }
    if(gameboard.at(position) == 'X' || gameboard.at(position) == 'O')
    {
        return false;
    }
    return true;
}


// acquires a play from the user as to where to put her mark
int getPlay(const vector <char> &gameboard)
{
    char play;
    int position;
    cout << "Please choose a position: ";
    cin >> play;
    cout << endl;
    
    position = convertPosition(play);
    
    while(!validPlacement(gameboard, position))
    {
        cout << "Please choose a position: ";
        cin>> play;
        cout << endl;
        position = convertPosition(play);
    }
    return position;
}


// predicate function to determine if the game has been won
bool gameWon(const vector <char> &gameboard)
{
    if(gameboard.at(0) == gameboard.at(1) && gameboard.at(1) == gameboard.at(2))
        return true;
    else if(gameboard.at(3) == gameboard.at(4) && gameboard.at(4) == gameboard.at(5))
        return true;
    else if(gameboard.at(6) == gameboard.at(7) && gameboard.at(7) == gameboard.at(8))
        return true;
    else if(gameboard.at(0) == gameboard.at(3) && gameboard.at(3) == gameboard.at(6))
        return true;
    else if(gameboard.at(1) == gameboard.at(4) && gameboard.at(4) == gameboard.at(7))
        return true;
    else if(gameboard.at(2) == gameboard.at(5) && gameboard.at(5) == gameboard.at(8))
        return true;
    else if(gameboard.at(0) == gameboard.at(4) && gameboard.at(4) == gameboard.at(8))
        return true;
    else if(gameboard.at(2) == gameboard.at(4) && gameboard.at(4) == gameboard.at(6))
        return true;
    else
        return false;
}


// predicate function to determine if the board is full
bool boardFull(const vector <char> &gameboard)
{
    unsigned int k = 0;
    for(unsigned int i = 0; i < gameboard.size(); i++)
    {
        if(gameboard.at(i) == 'X' || gameboard.at(i) == 'O')
        {
            k++;
        }
    }
    if( k == gameboard.size())
    {
        return true;
    }
    return false;
}

const int PLAYER1 = 0; // PLAYER1 is always first with 'x'
const int PLAYER2 = 1; // PLAYER2 is 'o'


int main()
{
    vector<char> gameboard(9);
    int curPlay;
    int turn = PLAYER1;
    
    initVector(gameboard);
    drawBoard(gameboard);
    cout << endl;
    
    
    while(!gameWon(gameboard) && !boardFull(gameboard))
    {
        curPlay = getPlay(gameboard);
        if(turn == PLAYER1)
        {
            gameboard.at(curPlay) = 'X';
            drawBoard(gameboard);
            cout << endl;
            turn = PLAYER2;
        }
        else if (turn == PLAYER2)
        {
            gameboard.at(curPlay) = 'O';
            drawBoard(gameboard);
            cout << endl;
            turn = PLAYER1;
        }
    }
    
    if(!gameWon(gameboard))
    {
        cout << "No one wins" << endl;
    }
    else // gameWon(board)
    {
        if(turn == PLAYER2)
        {
            cout << "PLAYER 1 WINS!" << endl;
        }
        else // turn == PLAYER1
        {
            cout << "PLAYER 2 WINS!" << endl;
        }
    }
    
    return 0;
}