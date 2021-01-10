
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
/*******************************************************************************
 *
 * GAME OF PIG - MONTE CARLO METHOD
 * ______________________________________________________________________________
 * This program uses the Hold-At-N strategy. When simulating a given number of
 * Hold-At-N turns of the Pig game, it outputs the estimated probabilities of
 * the occurrence of each possible scores
 * _____________________________________________________________________________
 *
 * INPUT:
 *  holdScore      : the hold-at-value input from the user
 *  simulation     : the number of simulations input from the user
 *
 * OUTPUT:
 *  roll           : a random number output by rand function as the rolling
 *                   result
 *  countZeroScore : stores the how many times of getting 0 score
 *  countHoldScore : stores the how many times of getting the hold-at-value
 *  countHoldScore1: stores the how many times of getting the hold-at-value + 1
 *  countHoldScore2: stores the how many times of getting the hold-at-value + 2
 *  countHoldScore3: stores the how many times of getting the hold-at-value + 3
 *  countHoldScore4: stores the how many times of getting the hold-at-value + 4
 *  countHoldScore5: stores the how many times of getting the hold-at-value + 5
 *  PzeroScore     : probability that resulting the 0 score
 *  PholdScore     : probability that resulting the hold value
 *  PholdScore1    : probability that resulting the hold value + 1
 *  PholdScore2    : probability that resulting the hold value + 2
 *  PholdScore3    : probability that resulting the hold value + 3
 *  PholdScore4    : probability that resulting the hold value + 4
 *  PholdScore5    : probability that resulting the hold value + 5
 *
 ******************************************************************************/

int main()
{
    // Seed rand with 333
    srand(333);

    // Declare variables
    int holdScore;           // Input - the hold at value input from the user
    int roll;                // Cal & output - a random number between 1 to 6
                             //                each time roll the dice
    int score;               // Cal & Output - total scare for a single turn
    double simulation;       // Input - number of simulations input from the
                             //         user
    double countZeroScore;   // Counter - denotes the frequency of occurrence
                             //           when score is 0
    double countHoldScore;   // Counter - denotes the frequency of occurrence
                             //           when score is the hold at value
    double countHoldScore1;  // Counter - denotes the frequency of occurrence
                             //           when score is hold at value + 1
    double countHoldScore2;  // Counter - denotes the frequency of occurrence
                             //           when score is hold at value + 2
    double countHoldScore3;  // Counter - denotes the frequency of occurrence
                             //           when score is hold at value + 3
    double countHoldScore4;  // Counter - denotes the frequency of occurrence
                             //           when score is hold at value + 4
    double countHoldScore5;  // Counter - denotes the frequency of occurrence
                             //           when score is hold at value + 5
    double PzeroScore;       // Cal & Output - denotes the probability of 0
                             //                score
    double PholdScore;       // Cal & Output - denotes the probability of hold
                             //                value
    double PholdScore1;      // Cal & Output - denotes the probability of hold
                             //                value + 1
    double PholdScore2;      // Cal & Output - denotes the probability of hold
                             //                value + 2
    double PholdScore3;      // Cal & Output - denotes the probability of hold
                             //                value + 3
    double PholdScore4;      // Cal & Output - denotes the probability of hold
                             //                value + 4
    double PholdScore5;      // Cal & Output - denotes the probability of hold
                             //                value + 5


    // Initialize variables
    roll = 0;
    countZeroScore = 0;
    countHoldScore = 0;
    countHoldScore1 = 0;
    countHoldScore2 = 0;
    countHoldScore3 = 0;
    countHoldScore4 = 0;
    countHoldScore5 = 0;
    PzeroScore = 0;
    PholdScore = 0;
    PholdScore1 = 0;
    PholdScore2 = 0;
    PholdScore3 = 0;
    PholdScore4 = 0;
    PholdScore5 = 0;


    // Input: get hold at value from the user
    cout << "What value should we hold at? ";
    cin >> holdScore;
    cout << endl;


    // Input: get the number of simulations from the user
    cout << "Hold-at-N turn simulations? " ;
    cin >> simulation;
    cout << endl;


    // Processing: the external while loop is being processed, iteration goes
    //             until it reaches the number of simulations
    int i = 1;     // Intialization: i starts from 1
    while (i <= simulation)
    {
        // Processing: the internal while loop is being processed, iteration
        //             goes as long as the score is less than the hold at value
        score = 0;     // Initialization: scores starts from 0
        while (score < holdScore)
        {
            // Calculation & output: use remainder to get the result of rolling
            //                       a dice
            roll = rand() % 6 + 1;


            // Branch: processing when the rolling result is not equal to 1
            if (roll != 1)
            {
                // Calculation & output: total score
                score += roll;
            }


            // Branch: processing when the rolling result is equal to 1
            else
            {
                // Output: outputs the occurrence frequency of 0 score
                countZeroScore++;
                break;
            }
        }


        // Branch: processing when the score reaches the hold at value
        if (score == holdScore)
        {
            // Output: outputs the occurrence frequency of hold at value
            countHoldScore++;
        }


        // Branch: processing when the score is greater than hold at value by 1
        else if (score == holdScore + 1)
        {
            // Output: outputs the occurrence frequency of hold-at-value + 1
            countHoldScore1++;
        }


        // Branch: processing when the score is greater than hold at value by 2
        else if (score == holdScore + 2)
        {
            // Output: outputs the occurrence frequency of hold-at-value + 2
            countHoldScore2++;
        }


        // Branch: processing when the score is greater than hold at value by 3
        else if (score == holdScore + 3)
        {
            // Output: outputs the occurrence frequency of hold-at-value + 3
            countHoldScore3++;
        }


        // Branch: processing when the score is greater than hold at value by 4
        else if (score == holdScore + 4)
        {
            // Output: outputs the occurrence frequency of hold-at-value + 4
            countHoldScore4++;
        }


        // Branch: processing when the score is greater than hold at value by 5
        else if (score == holdScore + 5)
        {
            // Output: outputs the occurrence frequency of hold-at-value + 5
            countHoldScore5++;
        }


        // i increments by 1 each time the loop iterates
        i++;
    }


    // Calculation & output: the occurrence probability of scores is being
    //                       calculated
    PzeroScore = countZeroScore / simulation;
    PholdScore = countHoldScore / simulation;
    PholdScore1 = countHoldScore1 / simulation;
    PholdScore2 = countHoldScore2 / simulation;
    PholdScore3 = countHoldScore3 / simulation;
    PholdScore4 = countHoldScore4 / simulation;
    PholdScore5 = countHoldScore5 / simulation;


    // Output: output scores and their occurrence probabilities
    cout << setprecision(6) << fixed;
    cout << "Score\tEstimated Probability" << endl;
    cout << "0\t" << PzeroScore << endl;
    cout << holdScore << "\t" << PholdScore << endl;
    cout << holdScore + 1 << "\t" << PholdScore1 << endl;
    cout << holdScore + 2 << "\t" << PholdScore2 << endl;
    cout << holdScore + 3 << "\t" << PholdScore3 << endl;
    cout << holdScore + 4 << "\t" << PholdScore4 << endl;
    cout << holdScore + 5 << "\t" << PholdScore5 << endl;


    return 0;
}



