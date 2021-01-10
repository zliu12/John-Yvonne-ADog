
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<string>
#include<cctype>
#include<vector>
#include<ctime>
#include<cmath>
using namespace std;
/*******************************************************************************
 *
 * VERCTORS
 *______________________________________________________________________________
 * This program allows the user to input a target string and a delimiter, then
 * returns a new string in target that are separated by the delimiter
 *______________________________________________________________________________
 *
 * INPUT:
 *  inputStr    : the target string
 *  delimiter   : the string of characters indicates the beginning or end
 *
 * OUTPUT:
 *  del_pos     : the position of the first character of the first match of
 *                delimiter
 *  del_len     : the length of delimiter
 *  vector1     : the string object with a substring of the string target
 ******************************************************************************/


/*******************************************************************************
 * split
 *  This function accepts two string parameters target and delimiter, then it
 *  returns the string vector1 with a substring of the string target
 *  - returns vector1
 ******************************************************************************/
vector<string> split(string target,     // IN - the string object input by users
                     string delimiter); // IN - the delimiter divides the string


int main()
{
    // Declare variable
    vector<string> splittedVector;      // Out - the string after splitting
    string inputStr;                    // IN - the target string input bu users
    string delimiter;                   // IN - the divider in the target string


    // Input: prompt users to enter a target string
    cout << "Enter the target string: " << endl;
    getline(cin, inputStr);


    // Input: prompt users to enter the delimiter
    cout << "Enter the delimiter: " << endl;
    getline(cin, delimiter);


    // Invocation: call functino split and assign the returned value to
    // splittedVector
    splittedVector = split(inputStr, delimiter);


    // Branch: when the delimiter is at the beginning of the input string
    if (splittedVector[0] == "")
    {
        //Proc: loop to iterate through the vector and display elements
        for (unsigned i = 0; i < splittedVector.size(); i++)
        {
            // Out: output elements of the vector splittedVector
            cout << splittedVector[i+1] << endl;
        }
    }


    // Branch: when the delimiter is not at the beginning of the input string
    else
    {
        //Proc: loop to iterate through the vector and display elements
        for (unsigned i = 0; i < splittedVector.size(); i++)
        {
            // Out: output elements of the vector splittedVector
            cout << splittedVector[i] << endl;
        }
        cout << endl;
    }


    return 0;
}


/*******************************************************************************
 *
 * FUNCTION split
 * _____________________________________________________________________________
 *  This function accepts two string parameters target and delimiter, then it
 *  returns the string vector1 with a substring of the string target
 *  - returns vector1
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      begin   : position of the first character in the string to be considered
 *                in the search
 *      del_pos : the position of the first character of the first match
 *      del_len : the length of the string
 *
 * POST - CONDITIONS
 *  This function will return the vector1
 *      vector1: the string vector with a substring of the string target
 ******************************************************************************/
vector<string> split(string target,     // IN - the string object input by users
                     string delimiter)  // IN - the delimiter divides the string
{
    // Declare variable
    size_t begin;                       // Starting position of string target
                                        // during searching
    size_t del_pos;                     // Position of the first character of
                                        // delimiter
    size_t del_len;                     // Length of delimiter
    vector<string> vector1;             // Out: the returned string vector


    // Initialization
    begin = 0;                          // Set begin to 0
    del_len = delimiter.length();       // Set del_len to the length of
                                        // delimiter


    // Proc: loop to iterate the string target to find the position of the first
    // character of delimiter at each of its occurrence
    while ((del_pos = target.find(delimiter, begin)) <= target.length())
    {
        // Proc: find the substring other than string delimiter in string target
        // and add it at the end of the vector1
        vector1.push_back(target.substr(begin, del_pos - begin));


        // Proc: update the begin by add the length of delimiter to the current
        // position
        begin = del_pos + del_len;
    }


    // Proc: add the substring of string target to vector1
    vector1.push_back(target.substr(begin));


    // Return: return vector1
    return vector1;
}
