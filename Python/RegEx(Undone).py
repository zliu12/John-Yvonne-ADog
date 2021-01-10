
# This program uses the Regular Expression "re" module to perform the following:
# Read the input file name "infile.txt" and get rid of duplicate characters
# where the duplicate character does not make it an English word. 

"""
# import the module to check if the string is a valid English word
import enchant
# import the module for regular expression
import re


# need a dictionary to check if a english word
d = enchant.Dict("en_US")

filename = 'infile.txt'

# Open the input file
text = open(filename, encoding="utf8")

#open the output file
with open("outfile.txt", "a") as f:

    # Loop through each line of the file
    for line in text:

        #split line into words
        words = line.split(" ")

        # just declearing a new list
        newline = []

        # loop to iterate words
        for word in words:

            if not word=='':

                if d.check(word): # if word is a valid english word do nothing
                    # append to newline words list
                    newline.append(word)
                else: # if word not a is a valid english word remove rpeated letters.
                    # the word after removing duplicate characters
                    new_word=re.compile(r'(.)\1{1,2}', re.IGNORECASE).sub(r'\1', word)

                    # append to newline words list
                    newline.append(new_word)
            else:
                newline.append(word)

        s=" ".join(newline)

        #The pattern for replacing with tabs
        repeat_pattern=re.compile(r'[ ]{2,5}')

        #Substutuing tabs
        s=repeat_pattern.sub('\t',s)

        # write to a file
        f.write(s)
        """
import enchant #this module will help in checking if the word is meaningful english word or not
import re #this is module for regular expression

d = enchant.Dict("en_US")

f = open("infile.txt","r") #opening the file
for x in f: #reading line by line
    if d.check(x):   #checking each string of line
        print(x)   #if meaningful printing it
    else:
        s=re.sub(r'([a-zA-Z])\1+', r'\1', x)   #if not removing duplicates
        p=re.sub(r' +' , ' ', s) #removing two or more white space with single space
             print(p) #printing final ouput.






