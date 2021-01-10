
#include<iostream>
#include<string>
using namespace std;
/*******************************************************************************
 *
 * LOOPS
 * ______________________________________________________________________________
 *
 * The program provides 3 exercies for users. The first exercise examines if the
 * input contains letter e or letter x or both; the second exercise changes the
 * occurrences of letter e to '3' or occurrences of letter x to '*' or letter i
 * to '*' if they are present; the third exercise determines the presence of
 * character '.' and string 'stop', and where they are located.
 *
 * _____________________________________________________________________________
 *
 * INPUT:
 *  ex       : The user`s choice of exercise, input from users
 *  word     : The test object which the user would like to test, input
 *             from users
 *
 * OUTPUT:
 *  Testing results based on the user`s choice of exercise and their input
 *
 ******************************************************************************/
int main()
{
    // Declare variables
    int ex;         // INPUT - the user`s choice of exercise
    string word;    // INPUT - the test object used for exercises


    // Input: the user`s choice of exercise is being input
    cout << "Which exercise: ";
    cin >> ex;


    // Processing: exercise 1 is processed
    if (ex == 1)
    {


        // Input: the test object that users would like to test
    cout << endl;
        cout << "Enter a word: ";
        cin >> word;
        cout << endl;


        // Declare variables
        bool eValid;  // a boolean variable used for testing the presence of
                      // 'e'
        bool xValid;  // a boolean variable used for testing the presence of
                      // 'x'


        // For loop: the loop to test whether the input object contains either
        //           an 'x' or an 'e' or both, and assign values to boolean
        //           boolean variables
        for (unsigned i = 0; i < word.size(); i++)
        {
            // Assign true value to boolean variables
            if (word.at(i) == 'e')
                eValid = true;
            else if (word.at(i) == 'x')
                xValid = true;
        }


        // Branch when only boolean variable eValid is true, or when the input
        // hsa letter 'e' only
        if (eValid == true && xValid == false)
        {
            // Output: output the result message to confirm the input has letter
            //         'e'
            cout << "Your word " << word << " contains the character 'e'\n";
        }


        // Branch when only boolean variable xValid is true, or when the input
        // has letter 'x' only
        else if (xValid == true && eValid == false)
        {
            // Output: output the result message to confirm the input has letter
            //         'x'
            cout << "Your word " << word << " contains the character 'x'\n";
        }


        // Branch when boolean variables eValid and xValid are both true, or
        // when the input has letter 'e' and letter 'x'
        else if (eValid == true && xValid == true)
        {
            // Output: output the result message to confirm the input has letter
            //         'e' and letter 'x'
            cout << "Your word " << word << " contains the character 'e'\n";
            cout << "Your word " << word << " contains the character 'x'\n";
        }
    }


    // Processing: exercise 2 is processed
    else if (ex == 2)
    {
        // Input: the test object that users would like to test
        cout << "Enter a word: ";
        cin >> word;
        cout << endl;


        // For loop: the loop to test whether the input contains letter 'e', or
        //           letter 'i', or letter 'x', and assgin new value to each of
        //           them
        for (unsigned i=0; i <word.size(); i++)
        {
            // Assign new values to three letters
            if (word.at(i) == 'e')
                word.at(i) = '3';
            else if (word.at(i) == 'i')
                word.at(i) = '1';
            else if (word.at(i) == 'x')
                word.at(i) = '*';
        }


        // Output: output the result message of the modified input with new
        //         values assgined to letter 'e', 'x', and 'i'
        cout << "Your word transformed is " << word << endl;
    }


    // Processing: exercise 3 is processed
    else if (ex == 3)
    {
        // Declare variables
        unsigned long foundPeriod; // an unsigned long variable denotes the
                                   // existence of character '.'
        unsigned long foundStop;   // an unsinged long variable denotes the
                                   // existence of string 'stop'


        // Input: a string of words with punctuation is being input
        cout << "Enter a sentence: ";
        cin >> word;


        // Assign values to two unsigned long variables
        foundPeriod = word.find('.');
        foundStop = word.find("stop");


        // Branch when character '.' is present
        if (foundPeriod != string::npos)
        {
            // Output: output the result message to confirm the presence and the
            //         location of character '.'
            cout << "\nThe character '.' is located at index " << foundPeriod;
            cout << endl;
        }


        // Branch when character '.' is not present
        else if (foundPeriod == string::npos)
        {
            // Output: output the result message to confirm the inexistence of
            //         character '.'
            cout << "\nYour sentence does not contain the character '.'"
                 << endl;
        }


        // Branch when string "stop" is present
        if (foundStop != string::npos )
        {
            // Output: output the result message to confirm the presence and the
            //         location of string "stop"
            cout << "The word \"stop\" is located at index " << foundStop
                 << endl;
        }


        // Branch when string "stop" is not present
        else if (foundStop == string::npos )
        {
            // Output: output the result message to confirm the inexistence of
            //         string "stop'
            cout << "Your sentence does not contain the word \"stop\"" << endl;
        }


    }
    return 0;

}
