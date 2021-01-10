
#include<iostream>
#include<ctime>
#include <cstdlib>
#include<string>
using namespace std;

/*******************************************************************************
 *
 * MORE LOOPS
 *______________________________________________________________________________
 *
 * This program provides three exercises that utilize different loop functions;
 * given three number ranges, the exercise 1 outputs three strings of numbers
 * corresponding to the given range; exercise 2 takes in grades and tracks how
 * many A's grades, B's grades, C's grades, D's grades and F's grades there are;
 * exercise 3 simulates the coin toss and output heads or tails
 *
 *______________________________________________________________________________
 *
 * INPUT:
 *  ex      : user choice of exercise
 *  beginNum: the minimum number in the range
 *  endNum  : the maximum number in the range
 *  grades  :
 *
 * OUTPUT:
 *  countA   : how many A`s grades
 *  countB   : how many B`s grades
 *  countC   : how many C`s grades
 *  countD   : how many D`s grades
 *  countF   : how many F`s grades
 *  randNum  : a random number obtained from rand function
 *  oddOreven: the remainder of a random number divided by 2, use to determines
 *             if a random number is even or odd
 ******************************************************************************/

int main()
{
    //Declare variables
    int ex;   // Input - user choice of which exercise to run


    //Input: user choice of exercise is being input
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;


    // All Exercise 1 code
    // Processing: exercise 1 is being processed
    if ( ex == 1 )
    {
        // Declare variabies
        int beginNum;  // Input - user inputs the beginning number of the range
        int endNum;    // Input - user inputs the ending number of the range
        int i;         // Counter - denotes the starting position
        int count;     // Counter - denotes the order position of each number,
                       //           starts from 0 and increments each time the
                       //           loop repeats


        // Input: the number range is being input
        cout << "Enter beginning and ending numbers, separated by space: ";
        cin >> beginNum;
        cin >> endNum;
        cout << endl;


        // Processing: i starts from the begin number and increments until it`s
        //             equal to the end number
        for (i = beginNum; i <= endNum; i++)
        {
            // Output: output the counter i each time the loop repeats
            cout << i;


            // Branch: accommodate format of the output
            if (i < endNum)
            {
                // Output: make the output format with proper use of commas
                cout << ", ";
            }
        }


        // Input: the number range is being input
        cout << "\nEnter beginning and ending numbers, separated by space: ";
        cin >> beginNum;
        cin >> endNum;
        cout << endl;


        // Processing: i starts from the begin number and increments by 2 until
        //             it`s equal to the end number
        for (int i = beginNum; i <= endNum; i += 2)
        {
            // Output: output the counter i each time the loop repeats
            cout << i;


            // Branch: accommodate format of the output
            if ((i+2) <= endNum)
            {
                // Output: make the output format with proper use of commas
                cout << ", ";
            }
        }


        // Input: the number range is being input
        cout << "\nEnter the beginning and largest positive numbers, separated"
                " by space: ";
        cin >> beginNum;
        cin >> endNum;
        cout << endl;


        // Processing: i start from the begin number, the absolute value of i
        //             multiplies by 2 until it`s equal to the end number; the
        //             counter starts from 0 and increments by 1 each time the
        //             loop repeats
        for (count = 0, i = beginNum; i <= endNum; count++, i *= 2)
        {
            // Branch: when the remainder of counter divided by 2 is 0
            if (count % 2 == 0)
            {
                // Output: output the positive i
                cout << i;
            }


            // Branch: when the remainder of counter divided by 2 is not 0
            else
            {
                // Output: output the negative i
                cout << (-1) * i;
            }


            // Branch: accommodate format of the output
            if (i < endNum)
            {
                // Output: make the output format with proper use of commas
                cout << ", ";
            }
        }
        cout << endl;
    }


    // All Exercise 2 code
    // Processing: exercise 2 is being processed
    if (ex == 2)
    {
        // Declare variables
        int grades;  // Input - stores grades which are input from the user
        int countA;  // Calculation & Output - denotes the quantity of grade A
        int countB;  // Calculation & Output - denotes the quantity of grade B
        int countC;  // Calculation & Output - denotes the quantity of grade C
        int countD;  // Calculation & Output - denotes the quantity of grade D
        int countF;  // Calculation & Output - denotes the quantity of grade E


        // Initialization: counter starts from 0, or quantity of each grade
        //                 level stars from 0
        countA = 0;
        countB = 0;
        countC = 0;
        countD = 0;
        countF = 0;


        // Processing: grades input from the user are being processed and the
        //             quantity of each grade level is stored in counters
        do
        {
            // Input: the grades are being input
            cout << "Enter one or more grades, or -1 to stop: ";
            cin >> grades;
            cout << endl;


            // Branch: find quantity of A grades
            if (90 <= grades && grades <= 100)
            {
                // Calculation & Output: quantity of A grades
                countA++;
            }


            // Branch: find quantity B grades
            else if (80 <= grades && grades <= 89)
            {
                // Calculation & Output: quantity of B grades
                countB++;
            }


            // Branch: find quantity C grades
            else if (70 <= grades && grades <= 79)
            {
                // Calculation & Output: quantity of C grades
                countC++;
            }


            // Branch: find quantity D grades
            else if (60 <= grades && grades <= 69)
            {
                // Calculation & Output: quantity of D grades
                countD++;
            }


            // Branch: find quantity F grades
            else if (0 <= grades && grades <= 59)
            {
                // Calculation & Output: quantity of F grades
                countF++;
            }
        }


        // Sentinel: stop collecting grades once the user enters -1
        while (grades != -1);


        // Output: output the quantity of each level of grades
        cout << "The grades breakdown is: " << endl;
        cout << "As: " << countA << endl;
        cout << "Bs: " << countB << endl;
        cout << "Cs: " << countC << endl;
        cout << "Ds: " << countD << endl;
        cout << "Fs: " << countF << endl;
    }


    // All Exercise 3 code
    // Processing: exercise 3 is being processed
    if (ex == 3)
    {
        // Declare variable
        string choice;  // Input - user choice to continue to toss the coin
        int randNum;    // Calculation & Output - a random number is found
        int oddOreven;  // Calculation & Output - find if a random number is odd
                        //                        or even


        // Initialization
        choice = "yes";
        // Processing: flip the coin if the user choice is yes
        while (choice == "yes")
        {
            // Input: user`s choice of flipping the coin
            cout << "Toss the coin? ";
            cin >> choice;
            cout << endl;


            // Branch: when user chooses to toss the coin
            if (choice =="yes")
            {
                // Processing: get a random number and find if that number is
                //             even or odd
                randNum = rand();


                // Calculation & Output: find the remainder of a random number
                oddOreven = randNum % 2;


                // Branch: when the remainder is 0, or the random number is even
                if (oddOreven == 0)
                {
                    // Output: output the toss result as "heads"
                    cout << "heads" << endl;
                }


                // Branch: when the remainder is not 0, or the random number is
                //         odd
                else
                {
                    // Output: output the toss result as "tails"
                    cout << "tails" << endl;
                }
            }
        }

    }


    return 0;
}
