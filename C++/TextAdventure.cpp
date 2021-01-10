
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<string>
#include<cctype>
#include<ctime>
#include<cmath>
using namespace std;
/*******************************************************************************
 *
 * TEXT ADVENTURE
 *______________________________________________________________________________
 * This program is a simple text adventure game. Within this game the player
 * will travel from room to room choosing which door to traverse through. Every
 * room in the game has 4 doors for the player to choose from, each associated
 * with an uppercase direction: N, E, S or W. Three of the doors open up to
 * another room, and the 4th door is an exit from the game. Of the three
 * non-exit doors, one will send the player to a room containing a monster.
 * Another will send the player to a room containing a genie. The third non-exit
 * door will send the player to a room that has a picture. The player starts
 * with 5 bananas and 3 oranges.
 *______________________________________________________________________________
 *
 * INPUT:
 *  playerName  : the name of the user who is playing the game
 *  monsterName : the name of a monster
 *  direction   : the direction of the room which the user picks
 *
 * OUTPUT:
 *  Different game messages will be output to the screen according to the user`s
 *  choice
 ******************************************************************************/


/*******************************************************************************
* monsterRoom
*  This function takes in two int reference parameters &bananas and &oranges,
*  and a string parameter monsterName, then outputs the scripted game incident
*  of monster room
*  - returns nothing -> Will output the game incident
*******************************************************************************/
void monsterRoom(int &bananas,          // REF - the current quantity of bananas
                 int &oranges,          // REF - the current quantity of oranges
                 string monsterName);   // IN  - the name of a monster input by
                                        //       the user


/*******************************************************************************
* genieRoom
*  This function takes in two int reference parameters &bananas and &oranges,
*  then outputs the scripted game incident of genie room.
*  - returns nothing -> Will output the game incident
*******************************************************************************/
void genieRoom(int &bananas,            // REF - stores the quantity of bananas
               int &oranges);           // REF - stores the quantity of oranges


/*******************************************************************************
* drawPicture
*  This function takes in no parameters, and then outputs a picture.
*  - returns nothing -> Will output a picture
*******************************************************************************/
void drawPicture();


/*******************************************************************************
* pictureRoom
*  This function takes in no parameters, and then outputs the scripted game
*  incident of picture room.
*  - returns nothing -> Will output the game incident
*******************************************************************************/
void pictureRoom();


/*******************************************************************************
* exitRoom
*  This function takes in two parameters named bananas and oranges, calculates
*  the total quantity of bananas and oranges, and then outputs the result along
*  with a scripted game incident of the ending.
*  - returns nothing -> Will output the game result along with a game ending
*  incident
*******************************************************************************/
void exitRoom(int bananas,              // Denotes the quantity of bananas when
                                        // game ends
              int oranges);             // Denotes the quantity of oranges
                                        // game ends


/*******************************************************************************
* randomRoom
*  This function takes in four char reference parameters &monster, &genie,
*  &picture, and &exit, then makes a choice of the room alignment based on a
*  random number.
*  - returns nothing -> Will determine the room alignment
*******************************************************************************/
void randomRoom(char &monster,          // REF - stores the direction choice
                char &genie,            // REF - stores the direction choice
                char &picture,          // REF - stores the direction choice
                char &exit);            // REF - stores the direction choice


/*******************************************************************************
* statusIndicator
*  This function takes in three parameters bananas, oranges, and playName, then
*  outputs the current game status of the player.
*  - returns nothing -> Will output the current game status
*******************************************************************************/
void statusIndicator(int bananas,       // Denotes the quantity of bananas
                     int oranges,       // Denotes the quantity of oranges
                     string playerName);// IN - the name of the player input by
                                        //      the user


int main()
{
    // Seed rand with 500
    srand(500);


    // Declare variables
    string playerName;                  // IN - the name of the player
    string monsterName;                 // IN - the name of a monster
    int bananas;                        // Denotes the quantity of bananas
    int oranges;                        // Denotes the quantity of oranges
    char direction;                     // IN - the user`s choice of the door
    char monster;                       // Denotes the monster room
    char genie;                         // Denotes the genie room
    char picture;                       // Denotes the picture room
    char exit;                          // Denotes the exit room


    // Initialization
    bananas = 5;                        // Set the quantity of bananas to 5
    oranges = 3;                        // Set the quantity of bananas to 3


    // Input: the users enters a name
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << endl;


    // Input: the user enters a monster name
    cout << "Name your scariest monster: ";
    cin >> monsterName;
    cout << endl;


    // Invocation: calling statusIndicator function. It will output the current
    // game status of the player
    statusIndicator(bananas, oranges, playerName);


    // Proc: the game loops over until the player hits the exit door
    while(true)
    {
        // Invocation: calling randomRoom function. It will determine which
        // room alignment to to be used
        randomRoom(monster, genie, picture, exit);


        // Input: the user enters a direction choice
        cout << "Pick a door to enter by typing the direction it is in "
            "(N/E/S/W): ";
        cin >> direction;
        cout << endl;


        // Proc: keep prompting the user to enter a direction as long as the
        // last input is invalid
        while (direction != 'N' && direction != 'E' && direction != 'S' &&
            direction != 'W')
        {
            // Input: the user enters a direction choice
            cout << "Pick a door to enter by typing the direction it is in "
                 << "(N/E/S/W): ";
            cin >> direction;
            cout << endl;
        }


        // Proc: when the direction input is valid
        if (direction == 'N' || direction == 'E' || direction == 'S' ||
                 direction == 'W')
        {
            // Proc: when the input direction is assigned to the monster room
            // by the alignment
            if (direction == monster)
            {
                // Invocation: calling monsterRoom function. It will output the
                // scripted game incident in monster room
                monsterRoom(bananas, oranges, monsterName);


                // Invocation: calling statusIndicator function. It will output
                // the current game status of the player
                statusIndicator(bananas, oranges, playerName);


                // Proc: jumps to the beginning of the loop for next iteration
                continue;
            }


            // Proc: when the input direction is assigned to the genie room
            // by the alignment
            else if (direction == genie)
            {
                // Invocation: calling genieRoom function. It will output the
                // scripted game incident in genie room
                genieRoom(bananas, oranges);


                // Invocation: calling statusIndicator function. It will output
                // the current game status of the player
                statusIndicator(bananas, oranges, playerName);


                // Proc: jumps to the beginning of the loop for next iteration
                continue;
            }


            // Proc: when the input direction is assigned to the picture room
            // by the alignment
            else if (direction == picture)
            {
                // Invocation: calling pictureRoom function. It will output the
                // scripted game incident in picture room
                pictureRoom();


                // Invocation: calling statusIndicator function. It will output
                // the current game status of the player
                statusIndicator(bananas, oranges, playerName);


                // Proc: jumps to the beginning of the loop for next iteration
                continue;
            }


            // Proc: when the input direction is assigned to the exit room
            // by the alignment
            else if (direction == exit)
            {
                // Proc: when the input direction is assigned to the exit room
                // by the alignment
                exitRoom(bananas, oranges);


                // Proc: terminate the loop, game over
                break;
            }
        }
    }


    return 0;
}


/*******************************************************************************
*
* FUNCTION monsterRoom
* ______________________________________________________________________________
*  This function takes in two int reference parameters &bananas and &oranges,
*  and a string parameter monsterName, then outputs the scripted game incident
*  of monster room
*  - returns nothing -> Will output the game incident
* ______________________________________________________________________________
* PRE - CONDITIONS
*  The following need previously defined values:
*       &bananas    : the current quantity of bananas
*       &oranges    : the current quantity of oranges
*       monsterName : the monster name entered by the user
*
* POST - CONDITIONS
*  This function will output the scripted game incident of monster room
*******************************************************************************/
void monsterRoom(int &bananas,          // REF - the current quantity of bananas
                 int &oranges,          // REF - the current quantity of oranges
                 string monsterName)    // the name of a monster input by
                                        //       the user
{
    // Initialization
    bananas = 0;                        // Set quantity of bananas to 0
    oranges = 0;                        // Set quantity of oranges to 0


    // Output: output the scripted game incident
    cout << endl;
    cout << "WATCH OUT!!!" << endl;
    cout << monsterName << " attacks you and steals all of your bananas and "
         << "oranges." << endl;
}


/*******************************************************************************
*
* FUNCTION genieRoom
* ______________________________________________________________________________
*  This function takes in two int reference parameters &bananas and &oranges,
*  then outputs the scripted game incident of genie room.
*  - returns nothing -> Will output the game incident
* ______________________________________________________________________________
* PRE - CONDITIONS
*  The following need previously defined values:
*       &bananas: the current quantity of bananas
*       &oranges: the current quantity of oranges
*
* POST - CONDITIONS
*  This function will output the scripted game incident of genie room
*******************************************************************************/
void genieRoom(int &bananas,            // REF - the current quantity of bananas
               int &oranges)            // REF - the current quantity of oranges
{
    // Output: output the scripted game incident
    cout << endl;
    cout << "!!Poof!! ";
    cout << "A Genie pops out and grants you 2 bananas and 1 orange." << endl;


    // Calc: quantity of bananas increases 2
    bananas = bananas + 2;


    // Calc: quantity of oranges increases 1
    oranges = oranges + 1;
}


/*******************************************************************************
*
* FUNCTION drawPicture
* ______________________________________________________________________________
*  This function takes in no parameters, and then outputs a picture.
*  - returns nothing -> Will output a picture
* ______________________________________________________________________________
* PRE - CONDITIONS
*  The following need previously defined values:
*
* POST - CONDITIONS
*  This function will output a picture
*******************************************************************************/
void drawPicture()
{
    // Output: output a picture
    cout << "        _--~~--_" << endl;
    cout << "      /~/_|  |_\\~\\" << endl;
    cout << "     |____________|" << endl;
    cout << "     |[][][][][][]|" << endl;
    cout << "   __| __         |__" << endl;
    cout << "  |  ||. |   ==   |  |" << endl;
    cout << " (|  ||__|   ==   |  |)" << endl;
    cout << "  |  |[] []  ==   |  |" << endl;
    cout << "  |  |____________|  |" << endl;
    cout << "  /__\\            /__\\" << endl;
    cout << "   ~~              ~~ " << endl;
}


/*******************************************************************************
*
* FUNCTION pictureRoom
* ______________________________________________________________________________
*  This function takes in no parameters, and then outputs the scripted game
*  incident of picture room.
*  - returns nothing -> Will output the game incident
* ______________________________________________________________________________
* PRE - CONDITIONS
*  The following need previously defined values:
*
* POST - CONDITIONS
*  This function will output the scripted game incident of picture room
*******************************************************************************/
void pictureRoom()
{
    // Output: output the scripted game incident
    cout << endl;
    cout << "You found a picture!" << endl;


    // Invocation: calling drawPicture function. It will output a picture
    drawPicture();
    cout << endl;
}


/*******************************************************************************
*
* FUNCTION exitRoom
* ______________________________________________________________________________
*  This function takes in two parameters named bananas and oranges, calculates
*  the total quantity of bananas and oranges, and then outputs the result along
*  with a scripted game incident of the ending.
*  - returns nothing -> Will output the game result along with the game ending
*  incident
* ______________________________________________________________________________
* PRE - CONDITIONS
*  The following need previously defined values:
*       bananas: the quantity of bananas
*       oranges: the quantity of oranges
*
* POST - CONDITIONS
*  This function will output the game result and a scripted game incident
*******************************************************************************/
void exitRoom(int bananas,              // Denotes the quantity of bananas when
                                        // game ends
              int oranges)              // Denotes the quantity of oranges when
                                        // game ends
{
    // Calc & Output: output the game result and a scripted game incident
    cout << endl;
    cout << "You found the exit!" << endl;
    cout << "Your score is " << bananas + oranges << "(" << bananas
         << " bananas and " << oranges << " oranges)." << endl;
    cout << "Bye bye!!!" << endl;
}


/*******************************************************************************
*
* FUNCTION randomRoom
* ______________________________________________________________________________
*  This function takes in four char reference parameters &monster, &genie,
*  &picture, and &exit, then makes a choice of the room alignment based on a
*  random number.
*  - returns nothing -> Will determine the room alignment
* ______________________________________________________________________________
* PRE - CONDITIONS
*  The following need previously defined values:
*       &monster    : stores the direction choice
*       &genie      : stores the direction choice
*       &picture    : stores the direction choice
*       &exit       : stores the direction choice
*
* POST - CONDITIONS
*  This function will determine which alignment is going to be used
*******************************************************************************/
void randomRoom(char &monster,          // REF - stores the direction choice
                char &genie,            // REF - stores the direction choice
                char &picture,          // REF - stores the direction choice
                char &end)              // REF - stores the direction choice
{
    // Proc: assign the alignment when the random number generated is even
    if ((rand() % 2) == 0)
    {
        // Proc: assign input direction to each reference parameter
        monster = 'N';
        genie = 'S';
        picture = 'E';
        end = 'W';
    }


    // Proc: assign the alignment when the random number generated is not even
    else
    {
        // Proc: assign input direction to each reference parameter
        end = 'N';
        monster = 'S';
        genie = 'E';
        picture = 'W';
    }
}


/*******************************************************************************
*
* FUNCTION statusIndicator
* ______________________________________________________________________________
*  This function takes in three parameters bananas, oranges, and playName, then
*  outputs the current game status of the player.
*  - returns nothing -> Will c
* ______________________________________________________________________________
* PRE - CONDITIONS
*  The following need previously defined values:
*       bananas : the quantity of bananas
*       oranges : the quantity of oranges
*       playName: the name of the player input by the user
*
* POST - CONDITIONS
*  This function will output the current player status
*******************************************************************************/
void statusIndicator(int bananas,       // Denotes the quantity of bananas
                     int oranges,       // Denotes the quantity of oranges
                     string playerName) // IN - the name of the player input by
                                        //      the user
{
    // Output: output the status of the player
    cout << playerName << ", you are in a room with 4 doors." << endl << endl;
    cout << "You are carrying " << bananas << " bananas and " << oranges
         << " oranges." << endl;
}
