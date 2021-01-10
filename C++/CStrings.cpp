
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;
/*******************************************************************************
 *
 * C STRINGS
 *______________________________________________________________________________
 * This program receives sentence from the user, and then display a menu of
 * string operations. Based on the user choice of the string operation, the
 * program will modify the input sentence and output different messages.
 *______________________________________________________________________________
 *
 * INPUT:
 *  string_input   : the char type string that the user first time types in
 *  new_string_input   : the char type string that the user second time types in
 *  menu_choice     : the menu choice that the user selects
 *
 * OUTPUT:
 *  count_V         : the number of vowel in the current string
 *  count_C         : the number of consonants in the current string
 *
 ******************************************************************************/


// Declare global constants
const int MAX_CHAR = 100;       // Const - max number of characters for a string


/*******************************************************************************
 * numOfV
 *  This function takes in one cstring parameter named input[], then returns the
 *  number of vowels in the input string
 *  - returns the number of vowels
 ******************************************************************************/
int numOfV(char input[]);       // In - the string input by the user


/*******************************************************************************
 * numOfC
 *  This function takes in one cstring parameter named input[], then returns the
 *  number of consonants in the input string
 *  - returns the number of consonants
 ******************************************************************************/
int numOfC(char input[]);       // In - the string input by the user


/*******************************************************************************
 * toLowercase
 *  This function takes in one cstring parameter named input[], then converts
 *  the string to lowercase, but returns or outputs nothing
 *  - returns or outputs nothing -> converts the string to lowercase
 ******************************************************************************/
void toLowercase(char input[]); // In - the string input by the user


/*******************************************************************************
 * toUppercase
 *  This function takes in one cstring parameter named input[], then converts
 *  the string to uppercase, but returns or outputs nothing
 *  - returns or outputs nothing -> converts the string to uppercase
 ******************************************************************************/
void toUppercase(char input[]); // In - the string input by the user


int main()
{
    // Declare variable
    char string_input[MAX_CHAR];        // In - the first string with the size
                                        //      of MAX_CHAR input by the user
    char new_string_input[MAX_CHAR];    // In - the second string with the size
                                        //      of MAX_CHAR input by the user
    char menu_choice;                   // In - the menu choice input by the
                                        //      user


    // Input: prompt the user to enter a string and let them type in
    cout << "Input a line of text, up to 100 characters: \n";
    cin.getline(string_input, 100);


    // Output: output the menu list
    cout <<"A)  Count the number of vowels in the string" << endl;
    cout <<"B)  Count the number of consonants in the string" << endl;
    cout <<"C)  Convert the string to uppercase" << endl;
    cout <<"D)  Convert the string to lowercase" << endl;
    cout <<"E)  Display the current string" << endl;
    cout <<"F)  Enter another string\n" << endl;
    cout <<"M)  Display this menu" << endl;
    cout <<"X)  Exit the program" << endl;
    cout << endl;


    // Proc: the loop allows the user to type in a menu choice. The loop breaks
    // when the user enters the command to exit
    while (true)
    {
        // Input: prompt the user to enter the menu choice
        cout << "Enter your menu selection: ";
        cin >> menu_choice;
        cout << endl;


        // Branch: when the A command is entered
        if (toupper(menu_choice) == 'A')
        {
            // Invocation & Output: call function numOfV and output the returned
            // value of the function
            cout << "Number of vowels: " << numOfV(string_input) << endl;
            cout << endl;
        }


        // Branch: when the B command is entered
        else if (toupper(menu_choice) == 'B')
        {
            // Invocation & Output: call function numOfC and output the returned
            // value of the function
            cout << "Number of consonants: " << numOfC(string_input) << endl;
            cout << endl;       
        }


        // Branch: when the C command is entered
        else if (toupper(menu_choice) == 'C')
        {
            // Proc: convert the string to uppercase
            toUppercase(string_input);
        }

        // Branch: when the D command is entered
        else if (toupper(menu_choice) == 'D')
        {
            // Proc: convert the string to lowercase
            toLowercase(string_input);
        }


        // Branch: when the E command is entered
        else if (toupper(menu_choice) == 'E')
        {
            // Output: output the current string
            cout << string_input << endl;
            cout << endl;
        }


        // Branch: when the F command is entered
        else if (toupper(menu_choice) == 'F')
        {
            // Input: prompt the user to enter a new string
            cout << "Input a new line of text, up to 100 characters: \n";
            cin.getline(new_string_input, MAX_CHAR);
            cin.getline(new_string_input, MAX_CHAR);


            // Proc: copy up to 100 characters into string_input, leaving one
            // space for '\0'
            strncpy(string_input, new_string_input, MAX_CHAR);
        }


        // Branch: when the M command is entered
        else if (toupper(menu_choice) == 'M')
        {
            // Output: output the menu again
            cout <<"A)  Count the number of vowels in the string" << endl;
            cout <<"B)  Count the number of consonants in the string" << endl;
            cout <<"C)  Convert the string to uppercase" << endl;
            cout <<"D)  Convert the string to lowercase" << endl;
            cout <<"E)  Display the current string" << endl;
            cout <<"F)  Enter another string" << endl << endl;
            cout <<"M)  Display this menu" << endl;
            cout <<"X)  Exit the program" << endl;
            cout << endl;
        }


        // Branch: when the X command is entered, X is the exit command
        else if (toupper(menu_choice) == 'X')
        {
            // Proc: exit the loop
            break;
        }
    }
    return 0;
}


/*******************************************************************************
 *
 * FUNCTION numOfV
 * _____________________________________________________________________________
 *  This function takes in one cstring parameter named input[], then returns the
 *  number of vowels in the input string
 *  - returns the number of vowels
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      intput: the string input by the user
 *
 * POST - CONDITIONS
 *  This function will return the number of vowels in the string
 ******************************************************************************/
int numOfV(char input[])            // In - the string input by the user
{
    // Declare variable
    int count_V;                    // Counter - stores the number of vowels


    // Initialization
    count_V = 0;                    // Set the value of count_V to 0


    // Proc: i begins from 0, increases by 1 each time the loop goes through a
    // string character until the null character is met
    for (int i = 0; input[i] != '\0'; i++)
    {
        // Proc: when the character is one of the vowels 'a', 'e', 'i', 'o', 'u'
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' ||
            input[i] == 'o' || input[i] == 'u' || input[i] == 'A' ||
            input[i] == 'E' || input[i] == 'I' || input[i] == 'O' ||
            input[i] == 'U')
        {
            // Calc: count_V increases by 1 each time a vowel is found
            count_V++;
        }
    }
    return count_V;
}


/*******************************************************************************
 *
 * FUNCTION numOfC
 * _____________________________________________________________________________
 *  This function takes in one cstring parameter named input[], then returns the
 *  number of vowels in the input string
 *  - returns the number of consonants
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      intput: the string input by the user
 *
 * POST - CONDITIONS
 *  This function will return the number of consonants in the string
 ******************************************************************************/
int numOfC(char input[])            // In - the string input by the user
{
    // Declare variable
    int count_C;                    // Counter - stores the number of vowels


    // Initialization
    count_C = 0;                    // Set the value of count_C to 0


    // Proc: i begins from 0, increases by 1 each time the loop goes through a
    // string character until the null character is met
    for (int i = 0; input[i] != '\0'; i++)
    {
        // Proc: when there is none of the 5 vowels 'a', 'e', 'i', 'o', 'u'
        if (!(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' ||
              input[i] == 'o' || input[i] == 'u' || input[i] == 'A' ||
              input[i] == 'E' || input[i] == 'I' || input[i] == 'O' ||
              input[i] == 'U') && isalpha(input[i]))
        {
            // Calc: count_C increases by 1 each time a consonant is found
            count_C++;
        }
    }
    return count_C;
}


/*******************************************************************************
 *
 * FUNCTION toLowercase
 * _____________________________________________________________________________
 *  This function takes in one cstring parameter named input[], then converts
 *  the string to lowercase, but returns or outputs nothing
 *  - returns or outputs nothing -> converts the string to lowercase
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      intput: the string input by the user
 *
 * POST - CONDITIONS
 *  This function returns or outputs nothing but does conversion
 ******************************************************************************/
void toLowercase(char input[])      // In - the string input by the user
{
    // Proc: i begins from 0, increases by 1 each time the loop goes through a
    // string character until the null character is met
    for (int i = 0; input[i] != '\0'; i++)
    {
        // Proc: convert the string to lowercase
        input[i] = tolower(input[i]);
    }
}


/*******************************************************************************
 *
 * FUNCTION toUppercase
 * _____________________________________________________________________________
 *  This function takes in one cstring parameter named input[], then converts
 *  the string to lowercase, but returns or outputs nothing
 *  - returns or outputs nothing -> converts the string to uppercase
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      intput: the string input by the user
 *
 * POST - CONDITIONS
 *  This function returns or outputs nothing but does conversion
 ******************************************************************************/
void toUppercase(char input[])
{
    // Proc: i begins from 0, increases by 1 each time the loop goes through a
    // string character until the null character is met
    for (int i = 0; input[i] != '\0'; i++)
    {
        // Proc: convert the string to lowercase
        input[i] = toupper(input[i]);
    }
}
