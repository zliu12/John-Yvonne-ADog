
 #include <iostream>
 #include <iomanip>
 #include <string>
 #include <cctype>
 using namespace std;
/*******************************************************************************
 *
 * HANGMAN
 *______________________________________________________________________________
 * The hangman is a spelling game. The program takes in a phrase from users,
 * replaces all alphabetic characters in the phrase to dashes, and displays it.
 * When guessing each alphabetic character, if the guessed letter is in the
 * phrase, the program then writes it in all its correct positions; if not, then
 * the program reduces the chance of guessing by 1. With 7 chances, users win if
 * all alphabetic characters of the phrase are guessed; otherwise users lose.
 *______________________________________________________________________________
 *
 * INPUT:
 *  phrase      : the particular phrase to be guessed, input from users
 *  guess       : the letter that users suggest to be in the phrase
 *
 * OUTPUT:
 *  phrase      : the phrase with all alphabetic characters converted to dashes
 *  unsolved    : the phrase with dashes for all unsolved characters
 *  chance      : the number of times that users can guess before losing
 *
 ******************************************************************************/


/*******************************************************************************
 * setupUnsolved
 *  This function takes in one parameter named phrase, then converts all
 *  alphabetic characters in the phrase to dashes
 *  - returns the phrase with dashes
 ******************************************************************************/
string setupUnsolved(string phrase);    // IN - the phrase to be guessed



/*******************************************************************************
 * updateUnsolved
 *  This function takes in three parameters named phrase, unsolved, and guess,
 *  then returns the new unsolved string with dashes replaced by new guess
 *  - returns the new unsolved string
 ******************************************************************************/
string updateUnsolved(string phrase,    // IN - the phrase to be guessed
                      string unsolved,  // OUT- the phrase with dashes for
                                        //      unsolved characters
                      char guess);      // IN - the char containing the current
                                        //      guessed character


/*******************************************************************************
 * getGuess
 *  This function takes in one parameter named prevGuesses, and returns a valid
 *  guess and only a valid guess as a character
 *  - returns a valid character guess
 ******************************************************************************/
char getGuess(string prevGuesses);      // IN - the string containing all
                                        //      characters guessed so far


/*******************************************************************************
 * findGuess
 *  This function takes in two parameters named guess and phrase, and returns
 *  true if the guess occurs in phrase and returns fales ohterwise
 *  - returns true or false
 ******************************************************************************/
bool findGuess(char guess,              // IN - the character users suggest to
                                        //      be in phrase
               string phrase);          // IN - the phrase to be solved


/*******************************************************************************
 *
 * FUNCTION setupUnsolved
 * _____________________________________________________________________________
 *  This function takes in one parameter named phrase, then converts all
 *  alphabetic characters in the phrase to dashes
 *  - returns the phrase with dashes
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      phrase: the phrase to be solved, received from users
 *
 * POST - CONDITIONS
 *  This function will replace alphabetic characters in phrase to dashes
 *      phrase: the phrase with alphabetic characters switched to dashes
 ******************************************************************************/
string setupUnsolved(string phrase)     // IN - the phrase needs to be solved

{
    // Proc: replace alphabetic characters in phrase with dashes;
    // i starts from 0 and increments by 1 each time until it`s equal to the
    // length of the phrase input
    for (unsigned i = 0; i < phrase.length(); i++)
    {
        // Proc: check if a character is alphabet
        if (isalpha(phrase.at(i)))
        {
            // Proc: replace alphabetic characters with dashes
            phrase.at(i) = '-';
        }
    }


    // Return: phrase with alphabetic characters switched to dashes
    return phrase;
}


/*******************************************************************************
*
* FUNCTION updateUnsolved
* ______________________________________________________________________________
*  This function takes in three parameters named phrase, unsolved, and guess,
*  then returns the new unsolved string with dashes replaced by new guess
*  - returns the new unsolved string
* ______________________________________________________________________________
* PRE - CONDITIONS
*  The following need previously defined values:
*       phrase  : the phrase to be solved, received from users
*       unsolved: the phrase with dashes for all unsolved characters
*       char    : the char containing the current guessed character
*
* POST - CONDITIONS
*  This function will replace alphabetic characters in phrase to dashes
*       unsolved: the new unsolved string with dashes replaced by new guess
*******************************************************************************/
string updateUnsolved(string phrase,    // IN - the phrase to be solved
                      string unsolved,  // OUT- the phrase with dashes for
                                        //       unsolved characters
                      char guess)       // IN - the char containing the current
                                        //      guessed character
{
    // Proc: replace dashes in phrase with alphabetic characters;
    // i starts from 0 and increments by 1 each time until it`s equal to the
    // length of the phrase input
    for (unsigned i = 0; i < phrase.length(); i++)
    {
        // Proc: check if the guess letter occurs in the phrase
        if (tolower(phrase.at(i)) == guess)
        {
            // Proc: replace dashes with alphabetic characters
            unsolved.at(i) = phrase.at(i);
        }
    }


    // Return: the new unsolved string with dashes replaced by new guess
    return unsolved;
}


/*******************************************************************************
*
* FUNCTION getGuess
* ______________________________________________________________________________
*  This function takes in one parameter named prevGuesses, and prompt users to
*  enter the letter they suggest to be in the phrase, then returns a valid guess
*  and only a valid guess as a character
*  - returns a valid guessed character
* ______________________________________________________________________________
* PRE - CONDITIONS
*  The following need previously defined values:
*       prevGuesses: the string containing all characters guessed so far
*
*
* POST - CONDITIONS
*  This function will return a valid guess and only a valid guess as a character
*       guess: a valid guess and only a valid guess as a character
*******************************************************************************/
char getGuess(string prevGuesses)       // IN - the string containing all
                                        //      characters guessed so far
{
    // Declare variable
    char guess;                         // IN - the alphabetic charater that
                                        //      users suggest to be in phrase


    // Input: prompt users to guess a character and enter
    cout << "Enter a guess: ";
    cin >> guess;
    cout << endl;


    // Proc: check if the guessed character is valid, loop over until a guessed
    // character passes all three conditions
    while(true)
    {
        // Proc: check if the guessed character has been guessed
        if (prevGuesses.find(guess) != string::npos)
        {
            // Out & In: output invalid guess message if the character has been
            // guessed and prompt users to enter again
            cout << "Invalid guess! Please re-enter a guess: ";
            cin >> guess;
            cout << endl;
        }


        // Proc: check if the guessed character is alphabetic
        else if (!isalpha(guess))
        {
            // Out & In: output invalid guess message if the character is not
            // alphabetic and prompt users to enter again
            cout << "Invalid guess! Please re-enter a guess: ";
            cin >> guess;
            cout << endl;
        }


        // Proc: check if the guessed character is lowercase
        else if (tolower(guess) != guess)
        {
            // Out & In: output invalid guess message if the character is not
            // lowercase and prompt users to enter again
            cout << "Invalid guess! Please re-enter a guess: ";
            cin >> guess;
            cout << endl;
        }


        // Proc: loop terminates when a guessed character passes all three
        // conditions
        else
        {
            break;
        }
    }


    // Return: a valid guess and only a valid guess as a character
    return guess;
}


/*******************************************************************************
*
* FUNCTION findGuess
* ______________________________________________________________________________
*  This function takes in two parameters named guess and phrase, and then
*  returns true if the guessed character is valid and in the phrase, otherwise
*  returns false
*  - returns true or false
* ______________________________________________________________________________
* PRE - CONDITIONS
*  The following need previously defined values:
*       guess   : a valid character that users guess
*       phrase  : a phrase containing characters to be guessed
*
* POST - CONDITIONS
*  This function will return ture if the guessed character is valid and in the
*  phrase or return false otherwise
*******************************************************************************/
bool findGuess(char guess,              // IN - the char containing the current
                                        //      guessed character
               string phrase)           // IN - the phrase to be solved
{
    // Proc: loop over the phrase to check if a guessed character occurs in
    // phrase;
    // i starts from 0 and increments by 1 each time until it`s equal to the
    // length of the phrase
    for (unsigned i = 0; i < phrase.length(); i++)
    {
        // Proc: if the lowercase version of characters in phrase matches the
        // guessed character
        if (tolower(phrase.at(i)) == guess)
        {
            // Return: true if matching
            return true;
        }
    }


    // Return: false if not matching
    return false;
}


// Main Function
int main()
{
    // Declare variable
    string phrase;              // IN - the phrase to be solved
    string unsolvedPhrase;      // OUT- the state of unsolved phrase
    string prevGuesses;         // OUT- the phrase has been guessed so far
    char guess;                 // IN - the character guessed in the phrase
    int chance;                 // COUNTER- remaining times of guess chance


    // Initialization
    chance = 7;                 // Max times of guessing
    unsolvedPhrase = " ";       // Initial state of unsolved phrase
    prevGuesses = " ";          // Initial state of previous guessed phrase


    // Input: prompt users to enter a phrase
    cout << "Enter phrase: ";
    getline(cin, phrase);
    cout << endl;


    // Proc: call setupUnsolved function and set unsolvedPhrase equal to the
    // function return value
    unsolvedPhrase = setupUnsolved(phrase);


    // Output: output the initial state of the unsolved phrase
    cout << "Phrase: " << unsolvedPhrase << endl;


    // Proc: loop over when the guess chance is not zero, update the state of
    // unsolved phrase and tally the remaining times of guess chance
    while (chance != 0)
    {
        // Proc: call getGuess function and set guess equal to the funcion
        // function return value
        guess = getGuess(prevGuesses);


        // Proc: update the state of phrase guessed so far
        prevGuesses = prevGuesses + guess;


        // Proc: call updateUnsolved and set the unsolvedPhrase equal to the
        // function return value of the function
        unsolvedPhrase = updateUnsolved(phrase, unsolvedPhrase, guess);


        // Output: output the state of phrase guessed so far
        cout << "Guessed so far:" << prevGuesses << endl;


        // Proc: check if the guessed character founded in phrase to be solved
        if (findGuess(guess, phrase) == false)
        {
            // Proc: chance decrements by 1 if the guessed character is not
            // found in phrase
            chance--;
        }


        // Output: output the remaining times of guess chance
        cout << "Wrong guesses left: " << chance << endl;


        // Output: output the current state of unsolved phrase
        cout << unsolvedPhrase << endl << endl;

        // Proc: check if the phrase is solved
        if (unsolvedPhrase == phrase)
        {
            // Output: output the game won message if the phrase is solved and
            // ends loop
            cout << "Congratulations!! You won!" << endl;
            break;
        }


        // Proc: check if the remaining times of guess chance is 0
        else if (chance == 0)
        {
            // Output: output the game lost message if no remaining times and
            // end loop
            cout << "You lost!" << endl;
            break;
        }
    }
    return 0;
}





























