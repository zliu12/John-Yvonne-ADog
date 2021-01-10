
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
 * STRINGS
 *______________________________________________________________________________
 * This program has two exercises which are word separator and replace of the
 * function substring. The user first chooses which exercise to run and type in
 * strings as the prompt. Word separator converts a sentence that all of the
 * words are run together to a string in which the words are separated by spaces
 * and only the first word starts with an uppercase letter. Function substring
 * replacement accepts three strings. When the second string is found in the
 * first string, it will be replaced by the third string
 *______________________________________________________________________________
 *
 * INPUT:
 *  ex      : the choice of exercise input from the user
 *  sentence: the user input sentence in which all words are run together
 *  str1    : the first user input string in exercise 2
 *  str2    : the second user input string in exercise 2
 *  str3    : the third user input string in exercise 2
 *
 * OUTPUT:
 *  sentence: the program output sentence with normal writing form
 *  new_str : the program output str1 that`s has been modified
 *
 ******************************************************************************/


/*******************************************************************************
 * replaceSubstring
 *  This function accepts three string parameters s1, s2, s3, and returns the
 *  new s1 that the s2 in s1 is replaced by s3
 *  - returns s1
 ******************************************************************************/
string replaceSubstring(string s1,      // IN - the first user input string
                        string s2,      // IN - the second user input string
                        string s3);     // IN - the third user input string


int main()
{
    // Declare variable
    int ex;                             // IN - the user input exercise choice


    // Input: prompt the user to enter their choice of exercise
    cout << "Which exercise?" << endl;
    cin >> ex;
    cout << endl;


    // Branch: if the user chooses the exercise 1
    if (ex == 1)
    {
        // Declare variable
        string sentence;                // IN - the user input sentence


        // Input: prompt the user to enter an appropriate sentence
        cout << "Enter a sentence (no spaces, 1st letter of each word is "
                "uppercase): " << endl;
        cin >> sentence;
        cout << endl;


        // Proc: loop begins at the second character of the user input sentence,
        // and loop over the rest of characters
        for (int i = 1; i < int(sentence.length()); i++)
        {
            // Branch: when other capital characters are found
            if(isupper(sentence.at(i)))
            {
                // Proc: insert an whitespace before each capital character, and
                // then change it to lowercase
                sentence.insert(i, " ");
                sentence.at(i + 1) = tolower(sentence.at(i + 1));
            }
        }


        // Output: output the user input sentence in normal writing form
        cout << sentence << endl << endl;
    }


    // Branch: if the user chooses the exercise 2
    if (ex == 2)
    {
        // Declare variable
        string str1;                    // IN - the first user input string
        string str2;                    // IN - the second user input string
        string str3;                    // IN - the third user input string
        string new_str;                 // Out- the updated first string


        // Input: prompt the user to enter the first string
        cout << "Enter the main string: " << endl;
        cin.ignore();
        getline(cin, str1);


        // Input: prompt the user to enter the second string
        cout << "Enter the string to replace: " << endl;
        getline(cin, str2);


        // Input: prompt the user to enter the third string
        cout << "Enter the replacement string: " << endl;
        getline(cin, str3);


        // Invocation: call function replaceSubstring and assign the function
        // returned value to the new_str
        new_str = replaceSubstring(str1, str2,str3);


        // Output: output the new_str
        cout << new_str << endl << endl;
    }
    return 0;
}


/*******************************************************************************
 *
 * FUNCTION replaceSubstring
 * _____________________________________________________________________________
 *  This function accepts three string parameters s1, s2, s3, and returns the
 *  new s1 that the s2 in s1 is replaced by s3
 *  - returns s1
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      s1: the first user input string
 *      s2: the second user input string
 *      s3: the third user input string
 *
 * POST - CONDITIONS
 *  This function will return the modified s1
 *      s1: the s2 in s1 has been replaced by s3
 ******************************************************************************/
string replaceSubstring(string s1,      // IN - the first user input string
                        string s2,      // IN - the second user input string
                        string s3)      // IN - the third user input string
{
    // Declare local variables
    int pos;                            // The index of a string


    // Proc: use built-in find function to find the s2 index in s1 and passes it
    //  to pos
    pos = s1.find(s2, 0);


    // Proc: when the string can be found by looking at the pos
    while (pos != int(s1.npos))
    {
        // Proc: remove the s2 at the pos position out of s1
        s1.erase(pos, s2.length());


        // Proc: insert the s3 at the pos position into s1
        s1.insert(pos, s3);


        // Proc: use built-in find function to find the s2 index in s1 and
        // passes it to pos
        pos = s1.find(s2, pos);
    }


    // Return: return the value of s1
    return s1;
}


