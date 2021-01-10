

#include<iostream>

using namespace std;

/*******************************************************************************
 *
 * Arithmetic Operations and Data Types
 *______________________________________________________________________________
 *
 * The program contains two execises that the first execise calculates the
 * checksum of the ISBN input by users; the second execise finds the position
 * of the lowercase letter that users input
 *______________________________________________________________________________
 *
 * INPUT:
 *  ex      : Users enter the execises number as the input
 *  isbn    : A first nine digits of ISBN, input by users
 *  letter  : A single lowercase input from users
 *
 * OUTPUT:
 *  Checksum: The corresponding sum which is calculated based on the isbn
 *            input received from users.
 *  position: The alphabet position of the single lowercase letter input by
 *            users, starting with "a" at position 1.
 *
 ******************************************************************************/

int main()
{
    //Declare variables with data table
    int ex;                  // User input to choose which execise to run


    //Input - User choice of execise
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;


   if ( ex == 1 )
   {
        // All Exercise 1 code
        // Declare Variabies with data table
        int isbn;         // User input of the first nine digits of the ISBN
        int weighted_sum; // Calculated based on the user input of isbn
        int check_sum;    // Calculated by take the remainder after the
                          // weighted sum is divided by eleven


        // Input: users input the first nine digits of an ISBN
        cout << "Please enter the first 9 digits of the ISBN: " << endl;
        cin >> isbn;


        // Processing: calculate the weighted sum of the first nine digits of
        //             an ISBN that is input by users, in which sum the results
        //             of one times the first digit, two times the second
        //             digit, and three times the third digits, etc. Divide
        //             the weighted sum by eleven, and the remainder will be
        //             the checksum
        weighted_sum = 1 * (isbn / 100000000 % 10) +
                       2 * (isbn / 10000000 % 10) +
                       3 * (isbn / 1000000 % 10) +
                       4 * (isbn / 100000 % 10) +
                       5 * (isbn / 10000 % 10) +
                       6 * (isbn / 1000 % 10) +
                       7 * (isbn / 100 % 10) +
                       8 * (isbn / 10 % 10) +
                       9 * (isbn%10);
        check_sum = weighted_sum % 11;


        //Output: the checksum of the first nine digits isbn of an ISBN input by
        //         users
        cout << "Checksum: " << check_sum << endl;
    }


   else if ( ex == 2 )
   {
        // All Exercise 2 code
        // Declare variables with data table
        char letter;  // User input of letter for find position
        int position; // The position of the letter input by users


        // Input: get a lowercase letter from users as the input
        cout << "Enter a character: ";
        cin >> letter;
        cout << "\n";


        // Processing: subtract 'a' from the input letter to find their
        //             difference on position, then plus 1 since the position
        //             takes a in the first position
        position = static_cast<int>(letter) - 'a' + 1;


        // Output: display the position of the letter that is input by users
        cout << letter << " is letter " << position << endl;

   };

   return 0;
}
