
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
 * Temperature Distribution
 *______________________________________________________________________________
 * This program describes the temperature distribution on a 6 * 8 plate grids.
 * The user first enters the input file name that contains the initial four
 * temperatures of the grids of the top, rightmost, bottom, and leftmost edges.
 * Other grids initial temperature are set to 0, and they change according to
 * the temperatures around them, in which can be computed as the average of the
 * four adjacent temperatures. Each time that the temperature of an central grid
 * changes, the temperatures of the grids adjacent to it change. These changes
 * continue until a thermal equilibrium is achieved and all temperatures become
 * constant. For this program, the tolerance for equilibrium is 0.5
 *______________________________________________________________________________
 *
 * INPUT:
 *  inFile      : the input stream from the input file
 *  infileName  : the name of the input file
 *  outfileName : the name of the output file
 *  top         : the temperature of the top edge
 *  bottom      : the temperature of the bottom edge
 *  right       : the temperature of the right edge
 *  left        : the temperature of the left edge
 *  tolerance   : the tolerance for equilibrium
 *
 * OUTPUT:
 *  outFile     : the output stream to the output file
 *  grid_diff   : the difference of each grid before and after updating
 *  diff_max    : the max difference of all grids before and after updating
 *  grid        : the current 6 * 8 grid
 *  grid_be4    : the previous plate_grid
 *
 ******************************************************************************/


// Declare global variable
const int ROW = 6;              // CONST - the number of rows
const int COL = 8;              // CONST - the number of columns

int main()
{
    // Declare variable
    ifstream inFile;            // IN - input stream from the input file
    ofstream outFile;           // OUT- output stream to the output file
    string infileName;          // IN - the name of input file
    string outfileName;         // IN - the name of output file
    double top;                 // IN - top edge temperature from input file
    double bottom;              // IN - bottom edge temperature from input file
    double right;               // IN - right edge temperature from input file
    double left;                // IN - left edge temperature from input file
    double tolerance;           // IN - tolerance for equilibrium
    double grid_diff;           // CAL- temperature difference during updating
    double diff_max;            // CAL- max difference during updating
    double grid[ROW][COL];      // OUT- the current grid
    double grid_be4[ROW][COL];  // OUT- the previous grid


    // Input: prompt the user to enter the name of input and output files
    cout << "Enter input file name: " << endl;
    cin >> infileName;
    cout << endl;
    cout << "Enter output file name: " << endl;
    cin >> outfileName;
    cout << endl;


    // Connect the input file stream
    inFile.open(infileName);


    // Input: read the intial temperature data and equilibrium from input file
    inFile >> top;
    inFile >> right;
    inFile >> bottom;
    inFile >> left;
    inFile >> tolerance;


    // Proc: row begins from 0 and increases 1 each time the loop iterates until
    // it gets to 1 less than ROW
    for (int row = 0; row < ROW; row++)
    {
        // Proc: col begins from 0 and increases by 1 each time the loop
        // interates until it gets to 1 less than COL
        for (int col = 0; col < COL; col++)
        {
            // Initialization: set the initial value of all grids to 0.0
            grid[row][col] = 0.0;
        }
    }


    // Proc: col begins from 0 and increases by 1 each time the loop
    // iterates until it gets to 1 less than COL
    for (int col = 0; col < COL; col++)
    {
        // Proc: assign temperature to grids in top row
        grid[0][col] = top;
    }


    // Proc: col begins from 0 and increases by 1 each time the loop
    // iterates until it gets to 1 less than COL
    for (int col = 0; col < COL; col++)
    {
        // Proc: assign temperature to grids in bottom row
        grid[5][col] = bottom;
    }


    // Proc: row begins from 0 and increases by 1 each time the loop iterates
    // until it gets to 1 less than ROW - 1
    for (int row = 1; row < (ROW - 1); row++)
    {
        // Proc: assign temperature to grids in rightmost column
        grid[row][7] = right;
    }


    // Proc: row begins from 0 and increases by 1 each time the loop iterates
    // until it gets to 1 less than ROW - 1
    for (int row = 1; row < (ROW - 1); row++)
    {
        // Proc: assign temperature to grids in leftmost column
        grid[row][0] = left;
    }


    // Proc: row begins from 0 and increases by 1 each time the loop iterates
    // until it gets to 1 less than ROW
    for (int row = 0; row < ROW; row++)
    {
        // Proc: col begins from 0 and increases by 1 each time the loop
        // iterates until it gets to 1 less than COL
        for (int col = 0; col < COL; col++)
        {
            // Initialization: set the initial value of all grids to 0.0
            grid_be4[row][col] = 0.0;
        }
    }


    // Proc: keep updating the temperature of each inner grid until the max
    // temperature difference of the same inner grid is less than the tolerance
    do
    {
        // Proc: row begins from 0 and increases by 1 each time the loop
        // iterates until it gets to 1 less than ROW
        for (int row = 0; row < ROW; row++)
        {
            // Proc: row begins from 0 and increases by 1 each time the loop
            // iterates until it gets to 1 less than COL
            for (int col = 0; col < COL; col++)
            {
                // Proc: assign the value of grid`s grids to grid_be4`s grids
                grid_be4[row][col] = grid[row][col];
            }
        }


        // Proc: row begins from 1 and increases by 1 each time the loop
        // iterates until it gets to 1 less than ROW - 1
        for (int row = 1; row < (ROW - 1); row++)
        {
            // Proc: col begins from 1 and increases by 1 each time the loop
            // iterates until it gets to 1 less than COL - 1
            for (int col = 1; col < (COL - 1); col++)
            {
                // Calc: update the temp of each inncer cell by averaging the
                // total temps of the 4 adjacent cells of that cell
                grid[row][col] = (grid[row - 1][col] +
                                  grid[row][col + 1] +
                                  grid[row + 1][col] +
                                  grid[row][col - 1]) / 4;
            }
        }


        // Initialization
        diff_max = 0;           // Set the initial value of diff_max to 0


        // Proc: row begins from 1 and increases by 1 each time the loop
        // iterates until it gets to 1 less than ROW - 1
        for (int row = 1; row < (ROW - 1); row++)
        {
            // Proc: col begins from 1 and increases by 1 each time the loop
            // iterates until it gets to 1 less than COL - 1
            for (int col = 1; col < (COL - 1); col++)
            {
                // CAL: computing the temp difference before and after updating
                grid_diff = grid[row][col] - grid_be4[row][col];


                // Branch: if the new temp difference is greater than previous
                if (grid_diff > diff_max)
                {
                    // Proc: assign the new max temp difference
                    diff_max = grid_diff;
                }
            }
        }
    }while(diff_max > tolerance);


    // Conncect the output stream
    outFile.open(outfileName);


    // Proc: row begins from 1 and increases by 1 each time the loop iterates
    // until it gets to 1 less than ROW - 1
    for (int row = 1; row < (ROW - 1); row++)
    {
        // Proc: row begins from 1 and increases by 1 each time the loop
        // iterates until it gets to 1 less than COL - 1
        for (int col = 1; col < (COL - 1); col++)
        {
            // Output: write the temperature value to the output file
            outFile << grid[row][col] << " ";
        }
        outFile << endl;
    }


    // Proc: row begins from 1 and increases by 1 each time the loop iterates
    // until it gets to 1 less than ROW - 1
    for (int row = 1; row < (ROW - 1); row++)
    {
        // Proc: row begins from 1 and increases by 1 each time the loop
        // iterates until it gets to 1 less than COL - 1
        for (int col = 1; col < (COL - 1); col++)
        {
            // Output: output the temperature value to screen
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }


    // Disconnect variables inFile outFile
    inFile.close();
    outFile.close();


    return 0;
}





