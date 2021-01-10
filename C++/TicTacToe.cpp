
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<string>
#include<cctype>
#include<vector>
#include<ctime>
#include<vector>
#include<cmath>
using namespace std;
/*******************************************************************************
 *
 * TIC TAC TOE
 *______________________________________________________________________________
 * This program is a console version of the game Tic-Tac-Toe. For two players,
 * player 1 denoted by x and player 2 denoted by o, who take turns occupying the
 * spaces (9 in total) in a 3x3 grid. The player who first occupies three spaces
 * while the occupied spaces turn to a row, a column, or a diagonal is the
 * winner. Player 1 goes first. There is no winner if all spaces are occupies
 * but neither player gets the winning conditin
 *______________________________________________________________________________
 *
 * INPUT:
 *  play    : the players decision of where to assign their mark
 *
 * OUTPUT:
 *  curPlay : stores the converted index on vector of spaces chosen by players
 *  position: stores the vector index of the chosen space
 *  board   : the changing board before there`s a winner or board`s full
 *  v       : the vector contains characters
 *  index   : the converted postion indicates the chosen space
 ******************************************************************************/


/*******************************************************************************
 * clearScreen
 *  This function takes in no parameters, utilizes an escape character sequence
 *  to clear the screen
 *  - returns nothing
 ******************************************************************************/
void clearScreen();


/*******************************************************************************
 * drawBoard
 *  This function takes in a vector parameter board, returns and outputs the
 *  3x3 grid of game board to the screen
 *  - returns and outputs the 3x3 game board
 ******************************************************************************/
void drawBoard(const vector <char> &board); // Out - the game board grid


/*******************************************************************************
 * initVector
 *  This function takes in a vector parameter v, fills the vector with character
 *  starting at lower case a, then returns and outputs the vector
 *  - returns and outputs the vector filled with characters
 ******************************************************************************/
void initVector(vector <char> &v);  // Out - the vector filled with characters



/*******************************************************************************
 * convertPosition
 *  This function takes in a char paramenter position, it converts a character
 *  representing a cell to a associated vector index and returns the integer
 *  index in the vector
 *  - returns the vector index
 ******************************************************************************/
int convertPosition(char position); // Out - the index of a character in vector


/*******************************************************************************
 * validPlacement
 *  This function takes in two paramenters board and position, it checks if a
 *  space status in current board, and returns true if it`s available
 *  - returns true or false with respect to the space status
 ******************************************************************************/
bool validPlacement(const vector <char> &board, // The current board vector
                    int position);              // The character index in vector


/*******************************************************************************
 * getPlay
 *  This function takes in a parameter board, it receives grid choice input from
 *  each player, makes the change to the game board, and then returns an integer
 *  index in board vector of a chose available board spot
 *  - returns vector index of a chosen space
 ******************************************************************************/
int getPlay(const vector <char> &board);        // The current board vector


/*******************************************************************************
 * gameWon
 *  This function takes in a parameter board, it decides if there`s a winner by
 *  checking the winning pattern on the game board and returns true or false
 *  - return true if there`s a winner
 ******************************************************************************/
bool gameWon(const vector <char> &board);       // The current board vector


/*******************************************************************************
 * boardFull
 *  This function takes in a parameter board, determines if the board is full,
 *  and returns true if all spaces have been taken
 *  - returns true or false depends on the board spaces status
 ******************************************************************************/
bool boardFull(const vector <char> &board);     // The current board vector


// Declare const variables
const int PLAYER1 = 0;              // Set PLAYER 1 to 0
const int PLAYER2 = 1;              // Set PLAYER 2 to 1
const bool CLEAR_SCREEN = true;     // Set CLEAR_SCREEN to true


int main()
{
    // Declare variables
    vector <char> board(9);         // Out - The 3x3 grid vector of the game
                                    //       board
    int curPlay;                    // Out - The converted index of the space
                                    //       chosen by each player
    int turn;                       // The round of each player


    // Initialization
    turn = PLAYER1;                 // Player 1 always goes first and is 'x'


    // Invocation: call function initVector to set up the game board grid
    initVector(board);


    // Inovcation: call function drawBoard to display lower case character in
    // each grid of game board grid
    drawBoard(board);


    // Proc: loop while neither player has been decided to win and there` re
    // available spaces in the game board grid
    while (gameWon(board) == false && boardFull(board) == false)
    {
        // Invocation: call function getPlay and store the converted position in
        // curPlay
        curPlay = getPlay(board);


        // Branch: when its player 1` s turn
        if (turn == PLAYER1)
        {
            // Proc: mark the space of index curPlay with 'x'
            board.at(curPlay) = 'x';


            // Invocation: call function drawboard to display the current board
            drawBoard(board);


            // Proc: switch to the player 2
            turn = PLAYER2;
        }


        // Branch: when its player 2` s turn
        else if (turn == PLAYER2)
        {
            // Proc: mark the space of index curPlay with 'o'
            board.at(curPlay) = 'o';


            // Invocation: call function drawboard to display the current board
            drawBoard(board);


            // Proc: switch to the player 1
            turn = PLAYER1;
        }
    }


    // Branch: when there`s a winner before all spaces are occupied
    if (gameWon(board) == true)
    {
        // Branch: the turn is passed to player 1 when there comes a winner
        if (turn == PLAYER1)
        {
            // Out: output the player 2 winning message to the screen
            cout << "Player 2 wins!!" << endl;
        }


        // Branch: the turn is passed to player 2 when there comes a winner
        else if (turn == PLAYER2)
        {
            // Out: output the player 1 winning message to the screen
            cout << "Player 1 wins!!" << endl;
        }
    }


    // Branch: when there`s no winner but no available space on game board grid
    else if (boardFull(board) == true && gameWon(board) == false)
    {
        // Out: output the no winner game message to the screen
        cout << "No one wins." << endl;
    }

    return 0;
}



/*******************************************************************************
 *
 * FUNCTION clearScreen
 * _____________________________________________________________________________
 *  This function takes in no parameters, utilizes an escape character sequence
 *  to clear the screen
 *  - returns nothing
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *
 * POST - CONDITIONS
 *  This function will return nothing but clear the screen
 ******************************************************************************/
void clearScreen()
{
    cout << endl;


    // Proc: when CLEAR_SCREEN
    if (CLEAR_SCREEN)
    {
        // Proc: clear the screen
        cout << "\033c";
    }

    cout << endl;
}


/*******************************************************************************
 *
 * FUNCTION drawBoard
 * _____________________________________________________________________________
 *  This function takes in a vector parameter board, returns and outputs the
 *  3x3 grid of game board to the screen
 *  - returns and outputs the 3x3 game board
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      board: the game board grid
 *
 * POST - CONDITIONS
 *  This function will return and output the game board
 ******************************************************************************/
void drawBoard(const vector <char> &board)  // Out - the game board grid
{
    // Invocation: call function clearScreen()
    clearScreen();


    // Proc: loop to iterate to output the initial game board to the screen
    for (int i = 0; i < 9; i += 3)
    {
        // Out: output the game board
        cout << "  " << board.at(i) << "  |  " << board.at(i + 1) << "  |  "
            << board.at(i + 2) << "  " << endl;


        // Branch: output the frame when i is less than 6
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;
}


/*******************************************************************************
 *
 * FUNCTION initVector
 * _____________________________________________________________________________
 *  This function takes in a vector parameter v, fills the vector with character
 *  starting at lower case a, then returns and outputs the vector
 *  - returns and outputs the vector filled with characters
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      v: the vector contains characters that mark the game board spaces
 *
 * POST - CONDITIONS
 *  This function will return the vector of characters
 ******************************************************************************/
void initVector(vector <char> &v)       // Out - The vector with characters
{
    // Proc: loop to iterate through the vector
    for (unsigned i = 0; i < v.size(); i++)
    {
        // Proc: store characters into the vector
        v[i] = 'a' + i;
    }
}


/*******************************************************************************
 *
 * FUNCTION convertPosition
 * _____________________________________________________________________________
 *  This function takes in a char paramenter position, it converts a character
 *  representing a cell to a associated vector index and returns the integer
 *  index in the vector
 *  - returns the vector index
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      position: the position to be converted to a vector index
 *
 * POST - CONDITIONS
 *  This function will return the vector index
 ******************************************************************************/
int convertPosition(char position)      // The position to be converted
{
    // Declare variable
    int index;                          // The index in vector


    // Proc: subract 'a' from position to get the index
    index = position - 'a';
    return index;
}


/*******************************************************************************
 *
 * FUNCTION validPlacement
 * _____________________________________________________________________________
 *  This function takes in two paramenters board and position, it checks if a
 *  space status in current board, and returns true if it`s available
 *  - returns true or false with respect to the space status
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      board   : the current game board
 *      position: the vector index to check if available
 *
 * POST - CONDITIONS
 *  This function will return true and false
 ******************************************************************************/
bool validPlacement(const vector <char> &board,     // The current game board
                    int position)                   // The vector index
{
    // Branch: when both size of board and position are zero
    if (board.size() == 0 && position == 0)
    {
        // Proc: the space is available
        return true;
    }


    // Branch: when the index is out of the board size or negative
    else if (position >= static_cast<int> (board.size()) || position < 0)
    {
        // Proc: the space is unavailable
        return false;
    }


    // Branch: when the board space is marked with 'x' or 'o'
    else if (board.at(position) == 'x' || board.at(position) == 'o')
    {
        // Proc: the space is unavailable
        return false;
    }


    // Proc: the space is available
    return true;
}


/*******************************************************************************
 *
 * FUNCTION getPlay
 * _____________________________________________________________________________
 *  This function takes in a parameter board, it receives grid choice input from
 *  each player, makes the change to the game board, and then returns an integer
 *  index in board vector of a chose available board spot
 *  - returns vector index of a chose space
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      board: the current game board
 *
 * POST - CONDITIONS
 *  This function will return the vector index of the chosen space on board
 ******************************************************************************/
int getPlay(const vector <char> &board)     // The current game board
{
    // Declare variable
    char play;                              // In - player`s decision of which
                                            //      space to mark
    int position;                           // Out- the space the player chooses
                                            //      to mark

    // Proc: loop to iterate until the chosen space is available
    do
    {
        // Input: prompt the player to choose a space
        cout << "Please choose a position: ";
        cin >> play;
        cout << endl;


        // Proc: store the converted vector index to position
        position = convertPosition(play);
    }while (!validPlacement(board, position));


    return position;
}


/*******************************************************************************
 *
 * FUNCTION gameWon
 * _____________________________________________________________________________
 *  This function takes in a parameter board, it decides if there`s a winner by
 *  checking the winning pattern on the game board and returns true or false
 *  - return true if there`s a winner
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      board: the current game board
 *
 * POST - CONDITIONS
 *  This function will return true if there`s a winner, false otherwise
 ******************************************************************************/
bool gameWon(const vector <char> &board)        // Out - the current game board
{
    // All branches: each branch reprents a winning pattern, in which three
    // horizontal, or vertical, or diagnol spaces
    if (board.at(0) == board.at(1) && board.at(1) == board.at(2) )
    {
        return true;
    }
    else if (board.at(3) == board.at(4) && board.at(4) == board.at(5))
    {
        return  true;
    }
    else if (board.at(6) == board.at(7) && board.at(7) == board.at(8))
    {
        return  true;
    }
    else if (board.at(0) == board.at(3) && board.at(3) == board.at(6))
    {
        return  true;
    }
    else if (board.at(1) == board.at(4) && board.at(4) == board.at(7))
    {
        return  true;
    }
    else if (board.at(2) == board.at(5) && board.at(5) == board.at(8))
    {
        return  true;
    }
    else if (board.at(0) == board.at(4) && board.at(4) == board.at(8))
    {
        return  true;
    }
    else if (board.at(2) == board.at(4) && board.at(4) == board.at(6))
    {
        return  true;
    }


    // Branch: when the game has not been won
    return false;
}


/*******************************************************************************
 *
 * FUNCTION boardFull
 * _____________________________________________________________________________
 *  This function takes in a parameter board, determines if the board is full,
 *  and returns true if all spaces have been taken
 *  - returns true or false depends on the board spaces status
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      board: the current game board
 *
 * POST - CONDITIONS
 *  This function returns trur if there`s avalaible spaces, false otherwise
 ******************************************************************************/
bool boardFull(const vector <char> &board)      // Out - the current game board
{
    // Declare variables
    unsigned k;                         // Counter - number of occupied spaces


    // Initialization
    k = 0;                              // Set space counter to zero


    // Proc: loop to iterate to check if all spaces on game board has been taken
    for(unsigned i = 0; i < board.size(); i++)
    {
        // Proc: when an 'x' or an 'o' is detected
        if (board.at(i) == 'x' || board.at(i) == 'o')
        {
            // Proc: space counter increases 1
            k = k + 1;
        }
    }


    // Proc: when the space counter is equal to the board size, or all spaces
    // have been marked
    if (k == board.size())
    {
        return true;
    }
    return false;
}



