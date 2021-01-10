

#include<iostream>
using namespace std;

/*******************************************************************************
 *
 * BRANCHING
 *______________________________________________________________________________
 *
 * Program let user choose between two exercises. The first exercise is the
 * calculator which takes a number of seconds as input and calculates the number
 * of seconds or minutes or hours or days in that many seconds; the second
 * program is branching which responses to user inputs.
 *______________________________________________________________________________
 *
 * INPUT:
 *  ex         : denotes the exercise choice made by users, input from users
 *  num_input  : a number of seconds input from users
 *  user_choice: denotes the option choice made by users, input from users
 *
 * OUTPUT:
 *  mins       : the number of minutes in seconds input by users
 *  hrs        : the number of hours in seconds input by users
 *  days       : the number of days in seconds input by users
 *
 ******************************************************************************/

int main()
{
    //All Exercise 1 code which is normally in main
    // Declare variables
    int ex;               // an integer type input stores the user`s choice


    // Input: users make a choice that which exerices they would like to take
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;


    // Exercise 1 runs if the exercise input of user is 1
    if (ex == 1)
    {
        // Declare variables
        int num_input;    // an integer type input stores the number of seconds
        int mins;         // an integer type input stores the number of minutes
        int hrs;          // an integer type input stores the number of hours
        int days;         // an integer type input stores the number of days


        // Input: the user types in a number of seconds
        cout << "Enter a number of seconds: " << endl;
        cin >> num_input;


        // Processing & Output: depends on the number of seconds entered by the
        // user, the program decides the range and calculates seconds, or
        // minutes, or hours, or days in that many seconds. Result is output to
        // the screen after calculation
        if (0 <= num_input && num_input <= 1)
        {   cout << "There is 1 second in " << num_input << " second." << endl;
        }

        else if (num_input < 60)
        {   cout << "There are " << num_input << " seconds in " << num_input
                 << " seconds." << endl;
        }

        else if (num_input < 120)
        {   cout << "There is 1 minute in " << num_input << " seconds." << endl;
        }

        else if (num_input < 3600)
        {   mins = num_input / 60;
            cout << "There are " << mins << " minutes in " << num_input
                 << " seconds." << endl;
        }

        else if (num_input < 7200)
        {   cout << "There is 1 hour in " << num_input << " seconds." << endl;
        }

        else if (num_input < 86400)
        {   hrs = num_input / 3600;
            cout << "There are " << hrs << " hours in " << num_input
                 << " seconds." << endl;
        }

        else if (num_input < 172800)
        { cout << "There is 1 day in " << num_input << " seconds." << endl;
        }

        else
        {   days = num_input / 86400;
            cout << "There are " << days << " days in " << num_input
                 << " seconds." << endl;
        }

    }


    // Exercise 2 runs if the exercise input of user is 2
    else if (ex == 2)
    {
        // All Exercise 2 code which is normally in main
        // Declare variable
        char user_choice;       // an character type stores the user choice


        // Input: the user enters the choice
        cout << "What do you want to do tonight?" << endl;
        cout << "a. Go to the movies" << endl;
        cout << "b. Eat out" << endl;
        cout << "c. Hang out at the Mall" << endl;
        cout << "d. Go watch the Dodgers" << endl;
        cin >> user_choice;


        // Processing & Output: program answers to the user choice and outputs
        // different responses to the screen.
        if ((user_choice == 'a') || (user_choice == 'A'))
        {   cout << "I know just the movie to see!" << endl;
        }

        else if ((user_choice == 'b') || (user_choice == 'B'))
        {   cout << "Great! I've been wanting to try that new Tuvaluan "
                 << "restaurant!" << endl;
        }

        else if ((user_choice == 'c') || (user_choice == 'C'))
        {   cout << "You bring the cash!" << endl;
        }

        else if ((user_choice == 'd') || (user_choice == 'D'))
        {   cout << "Take me out to the ball game ..." << endl;
        }

        else
        {   cout << "Nothing suits you, then? I guess we`ll just stay and "
                 << "program!" << endl;
        }

    }

    return 0;

}

