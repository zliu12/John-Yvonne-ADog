
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
/*******************************************************************************
 *
 * CIPHER
 *______________________________________________________________________________
 * This program can both decrypt and encrypt a single word that is entered by
 * the user, and it`s the user`s choice to either encrypt or decrypt. The user
 * can also enter a user-defined value and use it to translate characters.
 *______________________________________________________________________________
 *
 * INPUT:
 *  method  : the user choice to choose encrypt or decrypt
 *  map     : a user-defined/ map when translating
 *  word    : a single word for encryption or decryption
 *
 * OUTPUT:
 *  num     : indication for the validation of input
 *  position: denotes the alphabetical position of each character in word input
 *  word    : output after encryption or decryption
 ******************************************************************************/

int main()
{
    // Declare variable
    string method;              // INPUT - the user input of method chocie
    string map;                 // INPUT - the user input of map choice
    string word;                // INPUT - the user input of a single word
    string defaultMap;          // A string variable denotes the default map
    int num;                    // An integer used for validating the input word
    int position;               // Cal & Output - denotes the alphabeticeal
                                // position of each character in word input


    // Initialiazion
    defaultMap = "zyxwvutsrqponmlkjihgfedcba";  // Assign the default mp value
                                                // to defaultMap
    num = 1;                                    // Assign value 1 to num


    // Input: ask the user to enter their choice of method
    cout << "What is the method (encryption or decryption)? ";
    cin >> method;
    cout << endl;


    // Branch: if the method choice is encryption
    if (method == "encryption")
    {
        // Input: ask the user to enter their choice of map
        cout << "What is the translation map (type 'default' to use default): ";
        cin >> map;
        cout << endl;


        // Branch: to encrypt with the default map
        if (map == "default")
        {
            // Input: ask the user to enter a single word
            cout << "What is the single word to translate: ";
            cin >> word;
            cout << endl;


            // A for loop to check if all characters in input word are lowercase
            for (unsigned i = 0; i < word.size(); i++)
            {
                // Branch: when all characters in input word are lowercase
                if (islower(word.at(i)))
                {
                }


                // Branch: when at leats one of the characters in input word is
                // not lowercase
                else
                {
                    // Ouput: num is changed to 6 since at least one charcater
                    // in input word is not lowercase
                    num = 6;
                    break;
                }
            }


            // Branch: if at least one of characters in input word is not
            // lowercase
            if (num == 6)
            {
                // Output: output a message to incidate error
                cout << "Error: encryption cannot be performed." << endl;
            }


            // Branch: if characters in input word are all lowercase
            else
            {
                // For loop: initializer a begins from 0 and increments until it
                // gets to the integer that`s 1 less than the number of
                // word`s characters
                for (int a = 0; a < int(word.length()); a++)
                {
                    // Calculation: for each character in the word input, find
                    // its ordinal number in alphabet by subtracting the ASCII
                    // Value of letter 'a' from the ASCII Value of characters
                    position = word.at(a) - 'a';
                    // Processing: find characters in default map that have the
                    // same ordinal number, and replace the original characters
                    // of the word input with them
                    word.at(a) = defaultMap.at(position);
                }
                // Output: output the word encrypted by the default map
                cout << "Encrypted word: " << word << endl;
            }
        }


        // Branch: to encrypt with a user-defined map
        else if (map != "default")
        {
            // Branch: if the size of user-defined map is 26
            if (map.size() == 26)
            {
                // Input: ask the user to enter a single word
                cout << "What is the single word to translate: ";
                cin >> word;
                cout << endl;


                // A for loop to check if all characters in input word are
                // lowercase
                for (int i = 0; i < int(word.size()); i++)
                {
                    // Branch: when all characters in input word are lowercase
                    if (islower(word.at(i)))
                    {
                    }


                    // Branch: when at leats one of the characters in input word
                    // is not lowercase
                    else
                    {
                        // Ouput: num is changed to 6 since at least one
                        // charcater in input word is not lowercase
                        num = 6;
                        break;
                    }
                }


                // Branch: if at least one of characters in input word is not
                // lowercase
                if (num == 6)
                {
                    // Output: output a message to incidate error
                    cout << "Error: encryption cannot be performed." << endl;
                }


                // Branch: if characters in input word are all lowercase
                else
                {
                    // For loop: initializer a begins from 0 and increments
                    // until it gets to the integer that`s 1 less than the
                    // number of word`s characters
                    for (int a = 0; a < int(word.length()); a++)
                    {
                        // Calculation: for each character in the word input,
                        // find its ordinal number in alphabet by subtracting
                        // the ASCII Value of letter 'a' from the ASCII Value
                        // of characters
                        position = word.at(a) - 'a';
                        // Processing: find characters in user-defined map that
                        // have the same ordinal number, and swap the original
                        // characters of the word input with them
                        word.at(a) = map.at(position);
                    }
                    // Output: output the word encrypted by the user-defined map
                    cout << "Encrypted word: " << word << endl;
                }
            }


            // Branch: if the size of user-defined map is not 26
            else
            {
                // Output: output an error message of the invalid map size
                cout << "Error: invalid translation map size." << endl;
            }
        }
    }


    // Branch: if the method choice is decryption
    else if (method == "decryption")
    {
        // Input: ask the user to enter their choice of map
        cout << "What is the translation map (type 'default' to use default): ";
        cin >> map;
        cout << endl;


        // Branch: to decrypt with the default map
        if (map == "default")
        {
            // Input: ask the user to enter a single word
            cout << "What is the single word to translate: ";
            cin >> word;
            cout << endl;

            // A for loop to check if all characters in input word are lowercase
            for (unsigned i = 0; i < word.size(); i++)
            {
                // Branch: when all characters in input word are lowercase
                if (islower(word.at(i)))
                {
                }


                // Branch: when at least one of the characters in input word is
                // not lowercase
                else
                {
                    // Ouput: num is changed to 6 since at least one charcater
                    // in input word is not lowercase
                    num = 6;
                    break;
                }
            }


            // Branch: if at least one of characters in input word is not
            // lowercase
            if (num == 6)
            {
                // Output: output a message to indicate error
                cout << "Error: decryption cannot be performed." << endl;
            }


            // Branch: if characters in input word are all lowercase
            else
            {
                // For loop: initializer a begins from 0 and increments until it
                // gets to the integer that`s 1 less than the number of word`s
                // characters
                for (int a = 0; a < int(word.size()); a++)
                {
                    // Calculation: for each character in word input, find its
                    // ordinal number in alphabet by subtracting the ASCII Value
                    // of letter 'a' from the ASCII value of these characters
                    position = word.at(a) - 'a';
                    // Processing: find characters in default map that have the
                    // same ordinal number, and swap the originl characters of
                    // the word input with them
                    word.at(a) = defaultMap.at(position);
                }


                // Output: output the word decrypted by the default map
                cout << "Decrypted word: " << word << endl;
            }
        }


        // Branch: to decrypt with a user-defined map
        else if (map != "default")
        {
            // Branch: if the size of user-defined map is 26
            if(map.size() == 26)
            {
                // Input: ask the user to enter a single word
                cout << "What is the single word to translate: ";
                cin >> word;
                cout << endl;


                // A for loop to check if all characters in input word are
                // lowercase
                for (unsigned i = 0; i < word.size(); i++)
                {
                    // Branch: when all characters in input word are lowercase
                    if (islower(word.at(i)))
                    {
                    }


                    // Branch: when at leats one of the characters in input word
                    //         is not lowercase
                    else
                    {
                        // Ouput: num is changed to 6 since at least one
                        //        charcater in input word is not lowercase
                        num = 6;
                        break;
                    }
                }


                // Branch: if at least one of characters in input word is not
                //         lowercase
                if (num == 6)
                {
                    // Output: output a message to indicate error
                    cout << "Error: decryption cannot be performed." << endl;
                }


                // Branch: if characters in input word are all lowercase
                else
                {
                    // For loop: initializer a begins from 0 and increments
                    // until it gets to the integer that`s 1 less than the
                    // number of word`s characters
                    for (int a = 0; a < int(word.size()); a++)
                    {
                        // Calculation: for each character in word input, find
                        // its ordinal number in alphabet by subtracting the
                        // ASCII Value of letter 'a' from the ASCII value of
                        // these characters
                        position = word.at(a) - 'a';
                        // Processing: find characters in user-defined map that
                        // have the same ordinal number, and swap the originl
                        // characters of the word input with them
                        word.at(a) = map.at(a);
                    }


                    // Output: output the word encrypted by the user-defined map
                    cout << "Decrypted word: " << word << endl;
                }
            }


            // Branch: if the size of user-defined map is not 26
            else
            {
                // Output: output an error message of the invalid map size
                cout << "Error: invalid translation map size." << endl;
            }
        }
    }


    // Branch: if the input of method doesn`t match encryption or decryption
    else
    {
        // Output: output an error message of the invalid method choice
        cout << "Error: invalid method choice." << endl;
    }


    return 0;
}
