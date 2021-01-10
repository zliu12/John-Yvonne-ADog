#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<string>
#include<cctype>
#include<vector>
#include<ctime>
#include<vector>
#include<cmath>
using namespace std;
/*******************************************************************************
 *
 * Battleship
 *______________________________________________________________________________
 * This program is a game on command-line interpreter. The games offers two game
 * modes are player 1 versus player 2 and player 1 versus computer. The game
 * displays two boards for each player, and it updates the boards and displays
 * the game message depends on the command received. Each player has 5
 * battleships to place on their board. Each battleship has a number of size,
 * and its size loses 1 everytime the ship is hit. The ship is destroyed once
 * it has been hit the number of its size times and sunk. The first player who
 * sinks all the enemy`s ships wins the game.
 *______________________________________________________________________________
 * INPUT:
 *  enemy           : the option of playing with computer or human
 *  coord_r         : the row of input coordinates
 *  coord_c         : the col of input coordinates
 *  orient_input    : the orientation input
 *  inputRow        : the row of the input shot coordinates
 *  inputCol        : the col of the input shot coordinates
 *
 * OUTPUT:
 *  board_left      : the left game board
 *  board_right     : the right game board
 *  shipBeenHit     : the index of the ship that is hit
 *  p1              : the game board of player 1
 *  p2              : the game board of player 2
 *  turn            : the player round
 *  row             : the number converted from the input of the coordinate row
 *  col             : the number converted from the input of the coordiante col
 *  orient          : the uppercase of the input orientation
 *  comRow          : the row index computed by the computer
 *  comCol          : the col index computed by the computer
 *  num             : the number computed by teh computer
 *  atkRow          : the row of converted coordinates
 *  atkCol          : the col of converted coordinates
 *  total_hit_count : the total of hit count
 *  comTargetRow    : the row of the computer target
 *  comTargetCol    : the col of the computer target
 ******************************************************************************/


// Declare const variables
const int CARRIER_SIZE = 5;
const int BATTLESHIP_SIZE = 4;
const int CRUISER_SIZE = 3;
const int SUBMARINE_SIZE = 3;
const int DESTROYER_SIZE = 2;
const int FLEET_SIZE = 5;


// Declare structures
struct Point
{
    // Declare struct variables
    int point_row;               // The row indices of cells the ship occupies
    int point_col;               // The col indices of cells the ship occupies
};


// Declare structures
struct Ship
{
    // Declare struct variables
    string name;                // The name of the ship
    int size;                   // The size of the ship
    int hitCount;               // The times the ship has been hit
    vector<Point> shipPt;       // The row and col indices of the ship
};


// Declare structures
struct Playerboard
{
    // Declare struct variables
    char board[10][10];         // The board displayed for the player
    Ship fleet[FLEET_SIZE];     // The array of Ship struct with FLEET_SIZE
};


/*******************************************************************************
 * displayBoards
 *  This function gets two char array. It returns nothing but display the game
 *  board of each player
 *  - returns nothing, displays the boards
 ******************************************************************************/
void displayBoards(char board_left[][10],   // Out: the left game board
                   char board_right[][10]); // Out: the right game board


/*******************************************************************************
 * initFleet
 *  This function gets a reference parameter &pb, it returns nothing but
 *  initializes all the ships with the proper information
 *  - returns nothing, initializes the ship information
 ******************************************************************************/
void initFleet(Playerboard &pb);            // Playerboard type variable stores
                                            // information of ships


/*******************************************************************************
 * placeShip
 *  This function gets a reference parameter and an int parameter, it returns
 *  nothing but allows players to set up the ships on game boards
 *  - returns nothing, allows players to set up ships
 ******************************************************************************/
void placeShip(Playerboard &pb,             // The game board of each player
               int shipInd);                // The index of each battleship


/*******************************************************************************
 * getValidShipInfo
 *  This function gets 5 parameters. It returns nothing but validate the
 *  coordinates and orienatation inputs during the battle time
 *  - returns nothing but validates the coordinates input
 ******************************************************************************/
void getValidShipInfo(int &row,             // The row index of the coordinates
                      int &col,             // The col index of the coordinates
                      char &orient,         // The orientation of ships
                      Playerboard &pb,      // The game board of each player
                      int shipInd);         // The index of each battleship


/*******************************************************************************
 * spaceOccupied
 *  This function gets 5 parameters. It checks the status of game board spaces
 *  and returns true if the space is unused, false otherwise
 *  - return true or false base on the board space status
 ******************************************************************************/
bool spaceOccupied(Playerboard pb,          // The game board of each player
                   int row,                 // The row index of the coordinates
                   int col,                 // The col index of the coordinates
                   char orient,             // The orientation of ships
                   int size);               // The size of ships


/*******************************************************************************
 * boardSetup
 *  This function gets 2 reference parameter. It returns nothing but calls the
 *  placeShip function and displays the game board after two player finish
 *  preparing
 *  - returns nothing but displays the updated game boards
 ******************************************************************************/
void boardSetup(Playerboard &pb1,           // The game board of player 1
                Playerboard &pb2);          // The game board of player 2


/*******************************************************************************
 * setBoards
 *  This function gets 1 char array parameter. It initializes the board grids to
 *  space
 *  - returns nothing but initialize the game board grids
 ******************************************************************************/
void setBoards(char b_var[][10]);           // The arry of game board


/*******************************************************************************
 * gameProc
 *  This function gets 3 parameters. It returns nothing but proceeds the whole
 *  game stages when the battle begins
 *  - returns nothing but proceeds the game processes
 ******************************************************************************/
void gameProc(Playerboard &yb,              // The game board of player 1
              Playerboard &eb,              // The game board of player 2
              int round);                   // The turn of each player


/*******************************************************************************
 * shipHit
 *  This function gets 3 parameters. It returns the index of the ship that is
 *  hit
 *  - returns the index of ship which gets hit
 ******************************************************************************/
int shipHit(Playerboard &pb,                // The game board of players
            int row,                        // The row index of the hit space
            int col);                       // The col index of the hit space


/*******************************************************************************
 * sunk
 *  This function gets 5 parameters. It returns nothing but checks if a ship
 *  is completely destroyed
 *  - returns nothing but checks if a ship is sunk
 ******************************************************************************/
void sunk(Playerboard &pb,                  // The game board of players
          int row,                          // The row index of the coordinates
          int col,                          // The col index of the coordinates
          bool human);                      // The indicator of player type


/*******************************************************************************
 * winner
 *  This function gets 1 reference parameter. It returns nothing but checks if
 *  there has been a winner or not
 *  - returns nothing but checks if there is a winner
 ******************************************************************************/
int winner(Playerboard &pb);                // The game board of players


/*******************************************************************************
 * ComBoardSetup
 *  This function gets 2 reference parameters. It returns nothing but sets the
 *  game board of the computer
 *  - returns nothing but sets the computer game board
 ******************************************************************************/
void ComBoardSetup(Playerboard &pb1,        // The game board of players
                   Playerboard &pb2);       // The game board of players


/*******************************************************************************
 * ComPlaceShip
 *  This function gets 2 parameters. It returns nothing but makes the computer
 *  to settle the ships on the game board
 *  - returns nothing but makes the computer to places ships
 ******************************************************************************/
void ComPlaceShip(Playerboard &pb,          // The game board of players
                  int shipInd);             // The index number of the ship


/*******************************************************************************
 * ComValidInfo
 *  This function gets 3 parameters. It returns nothing but checks if the
 *  computer places the ship validly
 *  - returns nothing but validate the computer`s choice of coordinates
 ******************************************************************************/
bool ComValidInfo(Point pt,                 // The Point type struct contains
                                            // the row and col indices
                  char cpOrientation,       // The ship orientation the computer
                                            // chooses
                  int size);                // The size of the ship


/*******************************************************************************
 * ComProc
 *  This function gets 2 reference parameters. It returns nothing but proceeds
 *  the computer moves during the game
 *  - returns nothing but processes the computer moves
 ******************************************************************************/
void ComProc(Playerboard &yb,               // The game board of player 1
             Playerboard &eb);              // The game board of player 2


/*******************************************************************************
 * ComHunt
 *  This function gets 4 parameters. It returns nothing but helps the computer
 *  to make smark move when firing a shot
 *  - returns nothings but renders the computer makes smart shots
 ******************************************************************************/
void ComHunt(Playerboard &pb,               // The game board of players
             vector<Point> huntTarget,      // The vector contains the indice
                                            // of spaces with higher "Hit"
                                            // chance
             int hitRow,                    // The row index of a "Hit" space
             int hitCol);                   // The col index of a "Hit" space


/*******************************************************************************
 * validHunt
 *  This function gets 2 parameters. It returns ture or false by checking if the
 *  high-hit-chance space is on the board or not
 *  - returns nothing buts checks the validity of a space
 ******************************************************************************/
bool validHunt(Playerboard &pb,             // The game board of players
               Point p);                    // The row and col indices of the
                                            // "high-hit-chance" spaces


int main()
{
    // Set the random seed
    srand(time(NULL));


    // Delcare variables
    struct Playerboard p1;                  // Out: the game board of player 1
    struct Playerboard p2;                  // Out: the game board of player 2
    int turn;                               // Out: The player round
    int enemy;                              // In: the option of playing with
                                            //     computer or human


    // In: prompt the user to choose play with player2 or computer and validate
    // the input
    do
    {
        // Input: prompt the user to choose to play with the computer or human
        cout << "1. VS PLAYER 2" << endl;
        cout << "2. VS COMPUTER" << endl;
        cout << "PLEASE ENTER 1 OR 2 TO SELECT YOUR ENEMY: ";
        cin >> enemy;
        cout << endl;
    }while (enemy != 1 && enemy != 2);


    // Invocation: call function setBoards to set up the boards for each player
    setBoards(p1.board);
    setBoards(p2.board);


    // Invocation: call function initFleet to store information to ships
    initFleet(p1);
    initFleet(p2);


    // Branch: when player vs player
    if (enemy == 1)
    {
        // Initialization: player 1 gose first
        turn = 1;


        // Invocation: call function boardSetup to let two players to prepare
        // the battleships
        boardSetup(p1, p2);


        // Proc: when neither of players has won
        while (winner(p2) != 1 && winner(p1) != 1)
        {
            // Branch: player 1 make moves
            if (turn == 1)
            {
                // Invocation: call function gameProc to let player 1 fires a
                // shot on player 2's board, then update the game boards and
                // display the result
                gameProc(p1, p2, turn);
                displayBoards(p1.board, p2.board);
                cout << endl << endl;


                // Turn goes to player 2
                turn = 2;
            }


            // Branch: player 2 make moves
            else if (turn == 2)
            {
                // Invocation: call function gameProc to let player 2 fires a
                // shot on player 1's board, then update the game boards and
                // display the result
                gameProc(p2, p1, turn);
                displayBoards(p2.board, p1.board);
                cout << endl << endl;


                // Turn goes to player 1
                turn = 1;
            }
        }


        // Out: output the message when game is over
        cout << "GOOD GAME." << endl;
    }


    // Branch: when player vs computer
    else if (enemy == 2)
    {
        // Initialization: player 1 gose first
        turn = 1;


        // Invocation: call function ComBoardSetup to let the computer preprare
        // the battleships
        ComBoardSetup(p1, p2);


        // Proc: when neither of players has won
        while (winner(p2) != 1 && winner(p1) != 1)
        {
            // Branch: player 1 make moves
            if (turn == 1)
            {
                // Invocation: call function gameProc to let player 1 fires a
                // shot on computer's board, then update the game boards and
                // display the result
                gameProc(p1,p2,turn);
                displayBoards(p1.board, p2.board);
                cout << endl << endl;


                // Turn goes to computer
                turn = 2;
            }


            // Branch: computer make moves
            else if (turn == 2)
            {
                // Invocation: call function gameProc to let computer fires a
                // shot on player 1's board, then update the game boards and
                // display the result
                ComProc(p1, p2);
                displayBoards(p1.board, p2.board);
                cout << endl << endl;


                // Turn goes to player 1
                turn = 1;
            }
        }


        // Out: output the message when game is over
        cout << "GOOD GAME." << endl;
    }
    return 0;
}


/*******************************************************************************
 *
 * FUNCTION displayBoards
 * _____________________________________________________________________________
 *  This function gets two char array. It returns nothing but display the game
 *  board of each player
 *  - returns nothing, displays the boards
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      board_left : the left game board
 *      board_right: the right game board
 *
 * POST - CONDITIONS
 *  This function displays the boards
 ******************************************************************************/
void displayBoards(char board_left[][10],   // Out: the left game board
                   char board_right[][10])  // Out: the right game board
{
    // Declare variables
    char letter;                // The leftmost column of the board
    string dash_left;           // Dash line to separate the rows in left board
    string dash_right;          // Dash line to separate the rows in right board
    int row;                    // Row of the board


    // Initialize: set the value of variables
    letter = 'A';
    dash_left = "  -----------------------------------------";
    dash_right = "            -----------------------------------------\n";
    row = 0;


    // Out: output the boards name and the first line of numbers
    cout << setw(28) << "Your Board" << setw(53) << "Enemy Board" <<endl;
    cout << " " << "    1   2   3   4   5   6   7   8   9  10"
         << "                1   2   3   4   5   6   7   8   9  10" << endl;


    // Proc: use loop to change the letter in alphabetical order until 'K'
    while (letter < 'K')
    {
        // Out: output the dash lines
        cout << " " << dash_left << dash_right << " " << letter << " ";


        // Proc: use loop to display the content of the left board array
        for (int j = 0; j < 11; j++)
        {
            cout << "|";


            // Branch: before the last element of the board array
            if (j < 10)
            {
                // Proc: use loop to display the content of grids
                for (int k = 0; k < 3; k++)
                {
                    if (k == 1)
                    {
                        cout << board_left[row][j];
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
        }


        // Out: output the leftmost letter column of the right board
        cout << "          " << letter << " ";


        // Proc: use loop to display the content of the right board array
        for (int j = 0; j < 11; j++)
        {
            cout << "|";

            // Branch: before the last element of the board array
            if (j < 10)
            {
                // Proc: use loop to display the content of grids
                for (int k = 0; k < 3; k++)
                {
                    if (k == 1 && board_right[row][j] != 's')
                    {
                        cout << board_right[row][j];
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;


        // Proc: letter and row increases 1 every time the loop iterates
        letter++;
        row++;
    }


    // Out: output the last lines
    cout << " " << dash_left << dash_right << endl;
}



/*******************************************************************************
 *
 * FUNCTION boardSetup
 * _____________________________________________________________________________
 *  This function gets 2 reference parameter. It returns nothing but calls the
 *  placeShip function and displays the game board after two player finish
 *  preparing
 *  - returns nothing but displays the updated game boards
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pb1: the game board of player 1
 *      pb2: the game board of player 2
 *
 * POST - CONDITIONS
 *  This function displays the updated game boards
 ******************************************************************************/
void boardSetup(Playerboard &pb1,           // The game board of player 1
                Playerboard &pb2)           // The game board of player 2
{
    // Out: output the board setup message
    cout << "Player 1 set your board." << endl << endl;


    // Invocation: call function displayBoards to display empty boards
    displayBoards(pb1.board, pb2.board);


    // Proc: use loop to let player 1 prepare the board and display it
    for (int i = 0; i < FLEET_SIZE; i++)
    {
        // Invocation: call function placeShip to let player 1 places the ships
        // on the game board, and then call function displayBoards
        placeShip(pb1, i);
        displayBoards(pb1.board, pb2.board);
    }


    // Out: output the message to indicate player 1 is done
    cout << "Player 1 finished setting the board." << endl << endl << endl;


    // Out: output the board setup message
    cout << "Player 2 set your board." << endl << endl;


    // Invocation: call function displayBoards to display empty boards
    displayBoards(pb2.board, pb1.board);


    // Proc: use loop to let player 2 prepare the board and display it
    for (int i = 0; i < FLEET_SIZE; i++)
    {
        // Invocation: call function placeShip to let player 2 places the ships
        // on the game board, and then call function displayBoards
        placeShip(pb2, i);
        displayBoards(pb2.board, pb1.board);
    }


    // Out: output the message to indicate player 1 is done
    cout << "Player 2 finished setting the board." << endl << endl << endl;
}



/*******************************************************************************
 *
 * FUNCTION initFleet
 * _____________________________________________________________________________
 *  This function gets a reference parameter &pb, it returns nothing but
 *  initializes all the ships with the proper information
 *  - returns nothing, initializes the ship information
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pb: playerboard type variable stores the information of ships
 *
 * POST - CONDITIONS
 *  This function initializes the ship information
 ******************************************************************************/
void initFleet(Playerboard &pb)         // Playerboard type variable stores
                                        // information of ships
{
    // Proc: loop to initialize all the fleet in the fleet with the appropriate
    // information, including the name, size, hit counts, and the indices of
    // each of the cells in the grid the ship occupies
    for (int i = 0; i < FLEET_SIZE; i++)
    {
        // Branch: initialize the first ship
        if (i == 0)
        {
            // Proc: store the name, size, and hit count in the first ship
            pb.fleet[i].name = "Carrier";
            pb.fleet[i].size = CARRIER_SIZE;
            pb.fleet[i].hitCount = 0;
        }


        // Branch: initialize the second ship
        else if (i == 1)
        {
            // Proc: store the name, size, and hit count to the second ship
            pb.fleet[i].name = "Battleship";
            pb.fleet[i].size = BATTLESHIP_SIZE;
            pb.fleet[i].hitCount = 0;
        }


        // Branch: initialize the third ship
        else if (i == 2)
        {
            // Proc: store the name, size, and hit count to the third ship
            pb.fleet[i].name = "Cruiser";
            pb.fleet[i].size = CRUISER_SIZE;
            pb.fleet[i].hitCount = 0;
        }


        // Branch: initialize the fourth ship
        else if (i == 3)
        {
            // Proc: store the name, size, and hit count to the fourth ship
            pb.fleet[i].name = "Submarine";
            pb.fleet[i].size = SUBMARINE_SIZE;
            pb.fleet[i].hitCount = 0;
        }


        // Branch: initialize the fifth ship
        else if (i == 4)
        {
            // Proc: store the name, size, and hit count to the fifth ship
            pb.fleet[i].name = "Destroyer";
            pb.fleet[i].size = DESTROYER_SIZE;
            pb.fleet[i].hitCount = 0;
        }


        // Proc: store the indices of each of the cells in the grid the ship
        // occupies
        for (int j = 0; j < pb.fleet[i].size; j++)
        {
            // Proc: push back the row and col of all spaces a ship occupies
            // into that ship`s Point vector, and intialize the value stored in
            // struct
            pb.fleet[i].shipPt.push_back(Point());
            pb.fleet[i].shipPt[j].point_row = -1;
            pb.fleet[i].shipPt[j].point_col = -2;
        }
    }
}


/*******************************************************************************
 *
 * FUNCTION placeShip
 * _____________________________________________________________________________
 *  This function gets a reference parameter and an int parameter, it returns
 *  nothing but allows players to set up the ships on game boards
 *  - returns nothing, allows players to set up ships
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pb     : the game board of each player
 *      shipInd: the index of each battleship
 *
 * POST - CONDITIONS
 *  This function let players to settle ships on their board
 ******************************************************************************/
void placeShip(Playerboard &pb,             // The game board of each player
               int shipInd)                 // The index of each battleship
{
    // Declare variables
    char orient;                // Orientation of the ship being placed
    int row;                    // Rows a vertically placed ship occupies
    int col;                    // Cols a horizontally placed ship occupies


    // Initialization
    orient = 'k';               // Set orient to 'k'
    row = -1;                   // Set row to -1
    col = -1;                   // Set col to -1


    // Proc: keep looping until a break statement happens
    while (true)
    {
        // Invocation: call function getValidShipInfo to valid the row and col
        getValidShipInfo(row, col, orient, pb, shipInd);


        // Store the Point type struct into the shipPt
        pb.fleet[shipInd].shipPt = vector<Point> ();


        // Branch: the vertical orientation
        if (orient == 'v')
        {
            // Branch: when not enough row to place the ship vertically
            if (row + pb.fleet[shipInd].size > 10)
            {
                // Out: output the out of board error message
                cout << "Error: Ship placement is outside the board."
                     << endl << endl;


                // Proc: force to the next iteration
                continue;
            }


            // Branch: when there`re enough rows to place the ship vertically
            else
            {
                // Proc: loop through the rows the ship occupies
                for (int i = row; i < (row + pb.fleet[shipInd].size); i++)
                {
                    // Proc: mark the occupied grids with 's', then push back
                    // the row and col indices to the vector of ship
                    pb.board[i][col] = 's';
                    pb.fleet[shipInd].shipPt.push_back({i, col});
                }


                // Proc: exit the loop
                break;
            }
        }


        // Branch: the horizontal orientation
        else if (orient == 'h')
        {
            // Branch: when not enough row to place the ship vertically
            if (col + pb.fleet[shipInd].size > 10)
            {
                // Out: output the invalid orientation message and force the
                // next iteration
                cout << "Error: Ship placement is outside the board."
                     << endl << endl;
                continue;
            }


            // Branch: when there`re enough rows to place the ship vertically
            else
            {
                // Proc: loop through the cols the ship occupies
                for (int i = col; i < (col + pb.fleet[shipInd].size); i++)
                {
                    // Proc: mark the occupied grids with 's', then push back
                    // the row and col indices to the vector of ship
                    pb.board[row][i] = 's';
                    pb.fleet[shipInd].shipPt.push_back({row, i});
                }
            }


            // Proc: exit the loop
            break;
        }
    }
}


/*******************************************************************************
 *
 * FUNCTION getValidShipInfo
 * _____________________________________________________________________________
 *  This function gets 5 parameters. It returns nothing but validate the
 *  coordinates and orienatation inputs during the battle time
 *  - returns nothing but validates the coordinates input
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      row    : the row index of the coordinates
 *      col    : the col index of the coordinates
 *      orient : the orientation of ships
 *      pb     : the game board of each player
 *      shipInd: the index of each battleship
 *
 * POST - CONDITIONS
 *  This function checks if the coordinates input is valid
 ******************************************************************************/
void getValidShipInfo(int &row,             // The row index of the coordinates
                      int &col,             // The col index of the coordinates
                      char &orient,         // The orientation of ships
                      Playerboard &pb,      // The game board of each player
                      int shipInd)          // The index of each battleship
{
    // Declare variables
    int coord_c;                            // IN: the col of input coordinates
    char coord_r;                           // IN: the row of input coordinates
    char orient_input;                      // IN: the orientation input
    bool occupied;                          // Check if the space is in use


    // Initializaton: set occupied to true
    occupied = true;


    // Proc: use loop to prompt the player to enter the starting coordinates
    // of their ships
    while (true)
    {
        // In: prompt the player to enter the starting coordinates of each ship
        cout << "Enter the starting coordinates of your "
             << pb.fleet[shipInd].name << ": ";
        cin >> coord_r >> coord_c;
        cout << endl;


        // Proc: validate the input of the starting coordinates
        while (toupper(coord_r) < 'A' || toupper(coord_r) > 'J' ||
               coord_c < 0 || coord_c > 10)
        {
            // Out: output the invalid input message
            cout << "Error: The starting coordinates are outside the board."
                 << endl << endl;


            // In: prompt the player to enter the coordinates again
            cout << "Enter the starting coordinates of your "
                 << pb.fleet[shipInd].name << ": ";
            cin >> coord_r >> coord_c;
            cout << endl;
        }


        // In: prompt the player to enter the orienatation of a ship
        cout << "Enter the orientation of your " << pb.fleet[shipInd].name
             << " (horizontal(h) or vertical(v)): ";
        cin >> orient_input;
        cout << endl;


        // Proc: validate the input of the orientation
        while (tolower(orient_input) != 'v' && tolower(orient_input) != 'h')
        {
            // Out: output the invalid input message
            cout << "Error: Invalid orientation, please enter again."
                 << endl << endl;


            // In: prompt the player to enter the orientation again
            cout << "Enter the orientation of your "
                 << pb.fleet[shipInd].name
                 << " (horizontal(h) or vertical(v)): ";
            cin >> orient_input;
            cout << endl;
        }


        // CAL & OUT: convert the input row and col of the starting coorndinates
        // to regular numbers, and turn the orientation input to uppercase
        row = toupper(coord_r) - 'A';
        col = coord_c - 1;
        orient = tolower(orient_input);


        // Invocation: call function spaceOccupied and stores its returned value
        // into the boolean variable oaccupied
        occupied = spaceOccupied(pb, row, col, orient, pb.fleet[shipInd].size);


        // Branch: if occupied is true
        if (occupied == true)
        {
            // Out: output the invalid input message and force the next
            // iteration
            cout << "Error: Space already occupied" << endl << endl;
            continue;
        }


        // Branch: if occupied is false
        else
        {
            // Proc: exit the loop
            break;
        }
    }
}


/*******************************************************************************
 *
 * FUNCTION spaceOccupied
 * _____________________________________________________________________________
 *  This function gets 5 parameters. It checks the status of game board spaces
 *  and returns true if the space is unused, false otherwise
 *  - return true or false base on the board space status
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pb      : the game board of each player
 *      row     : the row index of the coordinates
 *      col     : the col index of the coordinates
 *      orient  : the orientation of ships
 *      size    : the size of shps
 *
 * POST - CONDITIONS
 *  This function checks if the space is occupied
 ******************************************************************************/
bool spaceOccupied(Playerboard pb,          // The game board of each player
                   int row,                 // The row index of the coordinates
                   int col,                 // The col index of the coordinates
                   char orient,             // The orientation of ships
                   int size)                // The size of ships
{
    // Branch: when the ship is placed vertically
    if (orient == 'v')
    {
        // Proc： use loop to check if the space is marked
        for (int i = row; i < size + row; i++)
        {
            // Branch: when the space is marked, return true
            if (pb.board[i][col] == 's')
            {
                return true;
            }
        }
    }


    // Branch: when the ship is placed horizontally
    else if (orient == 'h')
    {
        // Proc： use loop to check if the space is marked
        for (int i = col; i < size + col; i++)
        {
            // Branch: when the space is marked, return true
            if (pb.board[row][i] == 's')
            {
                return true;
            }
        }
    }

    return false;
}


/*******************************************************************************
 *
 * FUNCTION setBoards
 * _____________________________________________________________________________
 *  This function gets 1 char array parameter. It initializes the board grids to
 *  space
 *  - returns nothing but initialize the game board grids
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      b_var: the board array
 *
 * POST - CONDITIONS
 *  This function initializes the game board grids
 ******************************************************************************/
void setBoards(char b_var[][10])            // The arry of game board
{
    // Proc: loop through each row
    for (int row = 0; row < 10; row++)
    {
        // Proc: loop through each column
        for (int col = 0; col < 10; col++)
        {
            // Proc: assign space in each grid
            b_var[row][col] = ' ';
        }
    }
}


/*******************************************************************************
 *
 * FUNCTION ComPlaceShip
 * _____________________________________________________________________________
 *  This function gets 2 parameters. It returns nothing but makes the computer
 *  to settle the ships on the game board
 *  - returns nothing but makes the computer to places ships
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pb      : the game board of players
 *      shipInd : the index number of ship
 *
 * POST - CONDITIONS
 *  This function proceeds the computer's moves
 ******************************************************************************/
void ComPlaceShip(Playerboard &pb,      // The game board of players
                  int shipInd)          // The index number of the ship
{
    // Declare variables
    Point comPt;                        // The computer point
    int comRow;                         // The row index the computer picks
    int comCol;                         // The col index the computer picks
    char ComOrient;                     // The orientation the computer picks
    int num;                            // A number either even or odd


    // Proc: loop to let computer choose the starting coordinates and
    // orientation of each ship
    while (true)
    {
        // CAL & OUT: use mod 10 to compute the row and col indices and store
        // them as a pair into the computer point
        comRow = rand() % 10;
        comCol = rand() % 10;
        comPt = {comRow, comCol};
        num = rand() % 2;


        // Proc: go to different case depends on the num's value
        switch (num)
        {
            // Proc: if num is even, then place ship vertically
            case 0:
                ComOrient = 'v';
                break;


            // Proc: if num is odd, then place ship horizontally
            case 1:
                ComOrient = 'h';
                break;
        }


        // Branch: if the ship is outside the board
        if (!ComValidInfo(comPt, ComOrient, pb.fleet[shipInd].size) ||
            spaceOccupied(pb, comPt.point_row, comPt.point_col, ComOrient,
                          pb.fleet[shipInd].size))
        {
            // Proc: force the next iteration
            continue;
        }


        // Branch: if the ship is not outside the board
        else
        {
            // Proc: exit the loop
            break;
        }
    }


    // Store the point into the shipPT
    pb.fleet[shipInd].shipPt = vector<Point> ();


    // Initialization: initialize the hit count of computer's ships to 0
    pb.fleet[shipInd].hitCount = 0;


    // Proc: go to different case depends on the ComOrient's value
    switch (ComOrient)
    {
        // Branch: if ComOrient is 'v'
        case 'v':

            // Proc: loop to mark the space
            for (int j = comPt.point_row;
                 j < pb.fleet[shipInd].size + comPt.point_row;
                 j++)
            {
                // Proc: mark the spaces with 's' and store them into the shipPt
                pb.board[j][comPt.point_col] = 's';
                pb.fleet[shipInd].shipPt.push_back({j, comPt.point_col});
            }
            break;


        // Branch: if ComOrient is 'h'
        case 'h':

            // Proc: loop to mark the space
            for (int j = comPt.point_col;
                j < pb.fleet[shipInd].size + comPt.point_col;
                j++)
            {
                // Proc: mark the spaces with 's' and store them into the shipPt
                pb.board[comPt.point_row][j] = 's';
                pb.fleet[shipInd].shipPt.push_back({comPt.point_col, j});
            }
            break;
    }
}


/*******************************************************************************
 *
 * FUNCTION ComValidInfo
 * _____________________________________________________________________________
 *  This function gets 3 parameters. It returns nothing but checks if the
 *  computer places the ship validly
 *  - returns nothing but validate the computer`s choice of coordinates
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pt              : the Point type struct stores the row and col indices
 *      cpOrientation   : the ship orientation the computer chooses
 *      size            : the size of the ship
 *
 * POST - CONDITIONS
 *  This function checks if the computer coordinates input is valid
 ******************************************************************************/
bool ComValidInfo (Point pt,            // The Point type struct contains
                                        // the row and col indices
                   char ComOrientation, // The ship orientation the computer
                                        // chooses
                   int size)            // The size of the ship
{
    // Branch: ship outside the board when placed horizontally
    if (ComOrientation == 'h' && pt.point_col + size > 9)
    {
        return false;
    }


    // Branch: ship outside the board when placed vertically
    if (ComOrientation == 'v' && pt.point_row + size > 9)
    {
        return false;
    }
    return true;
}


/*******************************************************************************
 *
 * FUNCTION gameProc
 * _____________________________________________________________________________
 *  This function gets 3 parameters. It returns nothing but proceeds the whole
 *  game stages when the battle begins
 *  - returns nothing but proceeds the game processes
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      yb      : the player 1 game board
 *      eb      : the player 2 game board
 *      round   : the player turn
 *
 * POST - CONDITIONS
 *  This function proceeds the game processes
 ******************************************************************************/
void gameProc(Playerboard &yb,      // The game board of players
              Playerboard &eb,      // The row index of the hit space
              int round)            // The col index of the hit space
{
    // Declare variables
    char inputRow;                  // IN: the row of the input shot coordinates
    int inputCol;                   // IN: the col of the input shot coordinates
    int atkRow;                     // OUT: the row of converted coordinates
    int atkCol;                     // OUT: the col of converted coordinates
    bool guy;                       // Check if the player is human or computer


    // Initialization: set guy to true
    guy = true;


    // Branch: player 1' s turn
    if (round == 1)
    {
        // Out: output the message to indicate player 1's turn and display
        // the board
        cout << "Player 1's turn:" << endl;
        displayBoards(yb.board, eb.board);


        // Proc: loop to take the input
        do
        {
            // In: prompt the player to input the shooting coordinates
            cout << "Player 1:" << endl;
            cout << "Fire a shot: ";
            cin >> inputRow >> inputCol;


            // CAL & OUT: converted the input shooting coordinates into normal
            // numbers
            atkRow = toupper(inputRow) - 'A';
            atkCol = inputCol - 1;


            // Branch: when the converted row and col is invalid
            if (atkRow < 0 || atkRow > 10 || atkCol < 0 || atkCol > 10 ||
                eb.board[atkRow][atkCol] == 'H' ||
                eb.board[atkRow][atkCol] == 'M')
            {
                // Out: output the invalid coordiantes message and force to
                // the next iteration
                cout << "Error: Invalid shot coorditnates."
                     << endl << endl;
                continue;
            }


            // Branch: when the converted row and col is valid
            else
            {
                // Proc: exit the loop
                break;
            }
        }while (true);


        // Branch: when the shooting coordinates on the board is empty
        if (eb.board[atkRow][atkCol] == ' ')
        {
            // Proc: mark the space with 'M' and output the message
            eb.board[atkRow][atkCol] = 'M';
            cout << "You Missed." << endl;
        }


        // Branch: when the shooting coordinates on the board is marked
        else if (eb.board[atkRow][atkCol] == 's')
        {
            // Proc: mark the space with 'H' and output the message
            eb.board[atkRow][atkCol] = 'H';
            cout << "Hit!!!" << endl;


            // Invocation: call function sunk to check if the ship is sunk
            sunk(eb, atkRow, atkCol, guy);


            // Invocation: call function winner to check if there's a winner
            winner(eb);
        }
    }


    // Branch: player 2' s turn
    else if (round == 2)
    {
        // Out: output the message to indicate player 1's turn and display
        // the board
        cout << "Player 2's turn:" << endl;
        displayBoards(yb.board, eb.board);


        // Proc: loop to take the input
        do
        {
            // In: prompt the player to input the shooting coordinates
            cout << "Player 2:" << endl;
            cout << "Fire a shot: ";
            cin >> inputRow >> inputCol;


            // CAL & OUT: converted the input shooting coordinates into normal
            // numbers
            atkRow = toupper(inputRow) - 'A';
            atkCol = inputCol - 1;


            // Branch: when the converted row and col is invalid
            if (atkRow < 0 || atkRow > 10 || atkCol < 0 || atkCol > 10 ||
                eb.board[atkRow][atkCol] == 'H' ||
                eb.board[atkRow][atkCol] == 'M')
            {
                // Out: output the invalid coordiantes message and force to
                // the next iteration
                cout << "Error: Invalid shot coorditnates."
                     << endl << endl;
                continue;
            }


            // Branch: when the converted row and col is valid
            else
            {
                // Proc: exit the loop
                break;
            }
        }while (true);


        // Branch: when the shooting coordinates on the board is empty
        if (eb.board[atkRow][atkCol] == ' ')
        {
            // Proc: mark the space with 'M' and output the message
            eb.board[atkRow][atkCol] = 'M';
            cout << "You Missed." << endl;
        }


        // Branch: when the shooting coordinates on the board is marked
        else if (eb.board[atkRow][atkCol] == 's')
        {
            // Proc: mark the space with 'H' and output the message
            eb.board[atkRow][atkCol] = 'H';
            cout << "Hit!!!" << endl;


            // Invocation: call function sunk to check if the ship is sunk
            sunk(eb, atkRow, atkCol, guy);


            // Invocation: call function winner to check if there's a winner
            winner(eb);
        }
    }
}


/*******************************************************************************
 *
 * FUNCTION shipHit
 * _____________________________________________________________________________
 *  This function gets 3 parameters. It returns the index of the ship that is
 *  hit
 *  - returns the index of ship which gets hit
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pb  : the game board of players
 *      row : the row index of the hit space
 *      col : the col index of the hit space
 *
 * POST - CONDITIONS
 *  This function returns which ship gets hit
 ******************************************************************************/
int shipHit(Playerboard &pb,            // The game board of players
            int row,                    // The row index of the hit space
            int col)                    // The col index of the hit space
{
    // Declare variable
    int shipBeenHit;                    // The index of ship has been hit


    // Proc: use loop to compare the 'H' space with ship index
    for (int i = 0; i < FLEET_SIZE; i++)
    {
        for (int j = 0; j < pb.fleet[i].size; j++)
        {
            // Branch: when the 'H' and the ship index are the same
            if (row == pb.fleet[i].shipPt[j].point_row &&
                col == pb.fleet[i].shipPt[j].point_col)
            {
                // Proc: assign i to shipBeenHit
                shipBeenHit = i;
            }
        }
    }
    return shipBeenHit;
}


/*******************************************************************************
 *
 * FUNCTION sunk
 * _____________________________________________________________________________
 *  This function gets 5 parameters. It returns nothing but checks if a ship
 *  is completely destroyed
 *  - returns nothing but checks if a ship is sunk
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pb      : The game board of players
 *      row     : The row index of the coordinates
 *      col     : The col index of the coordinates
 *      human   : The indicator of player type
 *
 * POST - CONDITIONS
 *  This function checks if the ship is sunk
 ******************************************************************************/
void sunk(Playerboard &pb,              // The game board of players
          int row,                      // The row index of the coordinates
          int col,                      // The col index of the coordinates
          bool human)                   // The indicator of player type
{
    // Declare variable
    int shipHitInd;                     // The index of ship has been hit


    // Proc: call function shipHit and store its returned value into shipHitInd
    shipHitInd = shipHit(pb, row, col);


    // Increase the hit count of ship by 1
    pb.fleet[shipHitInd].hitCount++;


    // Branch: when the hit count is equal to the ship size and it`s player vs
    // player
    if (pb.fleet[shipHitInd].hitCount == pb.fleet[shipHitInd].size && human)
    {
        // Out: output the ship sunk message
        cout << "You sunk the " << pb.fleet[shipHitInd].name << "!!!" << endl;
    }


    // Branch: when the hit count is equal to the ship size and it`s player vs
    // computer
    else if (pb.fleet[shipHitInd].hitCount == pb.fleet[shipHitInd].size &&
             !human)
    {
        // Out: output the ship sunk message
        cout << "Computer sunk the " << pb.fleet[shipHitInd].name << "!!!"
             << endl;
    }
}


/*******************************************************************************
 *
 * FUNCTION winner
 * _____________________________________________________________________________
 *  This function gets 1 reference parameter. It returns nothing but checks if
 *  there has been a winner or not
 *  - returns nothing but checks if there is a winner
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pb: The game board of players
 *
 * POST - CONDITIONS
 *  This function checks if there is a winner
 ******************************************************************************/
int winner(Playerboard &pb)         // The game board of players
{
    // Declare variable
    int total_hit_count;            // CAL & OUT: the total of hit count


    // Initialization: set the total of hit count to zero
    total_hit_count = 0;


    // Proc: use loop to add up the hit count times
    for (int i = 0; i < FLEET_SIZE; i++)
    {
        // CAL & OUT: compute the total hit count
        total_hit_count = total_hit_count + pb.fleet[i].hitCount;
    }


    // Branch: when the hit count is equal to 17, which the total size of ships
    if (total_hit_count == 17)
    {
        // Out: output the sunk message and return 1
        cout << "You sunk the fleet!!! You win!!!" << endl << endl;
        return 1;
    }

    return 0;
}


/*******************************************************************************
 *
 * FUNCTION ComBoardSetup
 * _____________________________________________________________________________
 *  This function gets 5 parameters. It returns nothing but validate the
 *  coordinates and orienatation inputs during the battle time
 *  - returns nothing but validates the coordinates input
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pb1: The game board of players
 *      pb2: The game board of players
 *
 * POST - CONDITIONS
 *  This function validates the coordinates input
 ******************************************************************************/
void ComBoardSetup(Playerboard &pb1,        // The game board of players
                   Playerboard &pb2)        // The game board of players
{
    // Out: output the board setup message
    cout << "Player 1 set your board." << endl << endl;


    // Invocation: call function displayBoards to display empty boards
    displayBoards(pb1.board, pb2.board);


    // Proc: use loop to let player 1 prepare the board and display it
    for (int i = 0; i < FLEET_SIZE; i++)
    {
        // Invocation: call function placeShip to let the player place the ships
        // on the board, the call function displayBoards to display
        placeShip(pb1, i);
        displayBoards(pb1.board, pb2.board);
    }


    // Out: output the message indication
    cout << "Player 1 finished setting the board." << endl << endl << endl;
    cout << "Computer sets the board." << endl << endl;


    // Proc: loop to let computer place the ships
    for (int i = 0; i < FLEET_SIZE; i++)
    {
        // Invocation: call function ComPlaceShip to let computer prepare ships
        ComPlaceShip(pb2, i);
    }


    // Invocation: call function displayBoards to display the updated boards
    displayBoards(pb1.board, pb2.board);
    cout << "Computer finished setting the board." << endl << endl << endl;

}


/*******************************************************************************
 *
 * FUNCTION ComProc
 * _____________________________________________________________________________
 *  This function gets 2 reference parameters. It returns nothing but proceeds
 *  the computer moves during the game
 *  - returns nothing but processes the computer moves
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      yb: The game board of player 1
 *      eb: The game board of player 2
 *
 * POST - CONDITIONS
 *  This function proceeds the computer moves
 ******************************************************************************/
void ComProc(Playerboard &yb,           // The game board of player 1
             Playerboard &eb)           // The game board of player 2
{
    // Declare variable
    vector<Point> search;               // Point type vector search
    Point comTarget;                    // Point type comTarget contains the row
                                        // and col indices
    int comTargetRow;                   // The row of the computer target
    int comTargetCol;                   // The col of the computer target
    char rowLetter;                     // The letter converted from the row
    bool guy;                           // Indicate if it`s human or computer


    // Initialization: set guy to false
    guy = false;


    // Out & Invocation: output the message and call function displayboards to
    // display the current board
    cout << "Computer's turn: " << endl;
    displayBoards(yb.board, eb.board);


    // Proc:use loop to let the computer choose a target grid
    do
    {
        // Branch: when vector search is empty
        if (search.empty())
        {
            // Cal & Out: find the last digit of a random number and stores into
            // comTargetRow and comTargetCol
            comTargetRow = rand() % 10;
            comTargetCol = rand() % 10;
            rowLetter = char ('A' + comTargetRow);


            // Out: output the computer fire message
            cout << "Computer: " << endl;
            cout << "Fire a shot: " << rowLetter << " " << comTargetCol + 1
                 << endl;


            // Branch: if the target space is already shot
            if (yb.board[comTargetRow][comTargetCol] == 'H' ||
                yb.board[comTargetRow][comTargetCol] == 'M')
            {
                // Proc: force to the next iteration
                continue;
            }


            // Branch: if the target space has not been shot
            else
            {
                // Proc: exit the loop
                break;
            }
        }


        // Branch: when vector search is not empty
        else
        {
            // Proc: set comTarget to the last element of vector search, then
            // remove that element
            comTarget = search.back();
            search.pop_back();


            // Out: output the game message
            cout << "Computer: " << endl;
            cout << "Fire a shot: " << (char)('A' + comTarget.point_row)
                 << " " << comTarget.point_col << endl;


            // Branch: if the target space is already shot
            if (yb.board[comTarget.point_row][comTarget.point_col] == 'H' ||
                yb.board[comTarget.point_row][comTarget.point_col] == 'M')
            {
                // Proc: force to the next iteration
                continue;
            }


            // Branch: if the target space has not been shot
            else
            {
                // Proc: exit the loop
                break;
            }
        }
    }while(true);


    // Branch: if the target space is empty
    if (yb.board[comTargetRow][comTargetCol] == ' ')
    {
        // Proc: mark the space with 'M' and output the game message
        yb.board[comTargetRow][comTargetCol] = 'M';
        cout << "Computer Missed." << endl;
    }


    // Branch: if the target space is marked with 's'
    else if (yb.board[comTargetRow][comTargetCol] == 's')
    {
        // Proc: mark the space with the 'H' and output the game message
        yb.board[comTargetRow][comTargetCol] = 'H';
        cout << "Computer Hit!!!" << endl;


        // Invocation: call function ComHunt to find the next shooting target
        ComHunt(yb, search, comTargetRow, comTargetCol);


        // Invocation: call funtion sunk to check if the ship is sunk
        sunk(yb, comTargetRow, comTargetCol, guy);


        // Invocation: call function winner to check if there`s a winner
        winner(yb);
    }
}


/*******************************************************************************
 *
 * FUNCTION ComHunt
 * _____________________________________________________________________________
 *  This function gets 4 parameters. It returns nothing but helps the computer
 *  to make smark move when firing a shot
 *  - returns nothings but renders the computer makes smart shots
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pb          : The game board of players
 *      huntTarget  : The vector contains the indice of spaces with higher "Hit"
 *                    chance
 *      hitRow      : The row index of a "Hit" space
 *      hitCol      : The col index of a "Hit" space
 *
 * POST - CONDITIONS
 *  This function helps the computer with smart shot
 ******************************************************************************/
void ComHunt(Playerboard &pb,           // The game board of players
             vector<Point> huntTarget,  // The vector contains the indice
                                        // of spaces with higher "Hit"
                                        // chance
             int hitRow,                // The row index of a "Hit" space
             int hitCol)                // The col index of a "Hit" space
{
    // Declare variable
    Point upGrid;                       // The space on top of 'H' spaces
    Point rtGrid;                       // The space on the right of 'H' spaces
    Point dnGrid;                       // The space on the bottom of 'H' spaces
    Point ltGrid;                       // The space on the left of 'H' spaces


    // Proc: store the row and col indices into surrounding spaces
    upGrid = {hitRow - 1, hitCol};
    dnGrid = {hitRow + 1, hitCol};
    ltGrid = {hitRow, hitCol - 1};
    rtGrid = {hitRow, hitCol + 1};


    // Proc: stores the Point struct into the vector huntTarget
    huntTarget.push_back(Point());


    // Branch: when the row and col indices of upGrid are valid
    if (validHunt(pb, upGrid))
    {
        // Proc: push back the upGrid into vector huntTarget
        huntTarget.push_back(upGrid);
    }


    // Branch: when the row and col indices of dnGrid are valid
    else if (validHunt(pb, dnGrid))
    {
        // Proc: push back the dnGrid into vector huntTarget
        huntTarget.push_back(dnGrid);
    }


    // Branch: when the row and col indices of ltGrid are valid
    else if (validHunt(pb, ltGrid))
    {
        // Proc: push back the ltGrid into vector huntTarget
        huntTarget.push_back(ltGrid);
    }


    // Branch: when the row and col indices of rtGrid are valid
    else if (validHunt(pb, rtGrid))
    {
        // Proc: push back the rtGrid into vector huntTarget
        huntTarget.push_back(rtGrid);
    }
}


/*******************************************************************************
 *
 * FUNCTION validHunt
 * _____________________________________________________________________________
 *  This function gets 2 parameters. It returns ture or false by checking if the
 *  high-hit-chance space is on the board or not
 *  - returns nothing buts checks the validity of a space
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      pb: The game board of players
 *      p : The row and col indices of the "high-hit-chance" spaces
 *
 * POST - CONDITIONS
 *  This function checks the validity of a space
 ******************************************************************************/
bool validHunt(Playerboard &pb,         // The game board of players
               Point p)                 // The row and col indices of the
                                        // "high-hit-chance" spaces
{
    // Branch: if the "high-hit-chance" spaces are out of the board
    if (p.point_row < 0 || p.point_row > 10 ||
        p.point_col < 0 || p.point_col > 10)
    {
        return false;
    }


    // Branch: if the "high-hit-chance" spaces are not out of the board
    else
    {
        // Branch: if the "high-hit-chance" spaces have received shot
        if (pb.board[p.point_row][p.point_col] == 'H'||
            pb.board[p.point_row][p.point_col] == 'M')
        {
            return false;
        }
    }
    return true;
}





























