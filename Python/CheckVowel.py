
# The program takes in the letter character as the input from uses, then it returns the value True if the input
# character is a vowel. Otherwise, it returns False. Letter case is not sensitive.


# Declare variables
prompt = " Enter a character between a and z (or A and Z): "
char_input = input(prompt)


# Processing: the input character is being checked by the function, a True will be returned if it`s a vowel, otherwise
# a False will be returned
def isVowel():

    if char_input == 'a' or char_input == 'e' or char_input == 'i' or char_input == 'o' or char_input == 'u':
        return True
    elif char_input == 'A' or char_input == 'E' or char_input == 'I' or char_input == 'O' or char_input == 'U':
        return True
    else:
        return False


# Output: output the result message about  whether the input character is a vowel
#print('\n', char_input, 'is a vowel:', isVowel())
print(isVowel())