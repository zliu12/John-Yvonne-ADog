# The input script is:
# string1 = “I love to play Football which is called Soccer in the U.S.A and score many GOALS, then say, GOOOOAAAAL,
# or GOLASO!”
# The output of the print(string1) should be as shown below:
# I love to play Football which is called Soccer in the U.S.A and score many GOALS, then say, GOAL, or GOLASO!

# import regular expression module
import re
# input string1
string1 = "I love to play Football which is called Soccer in the U.S.A and score many GOALS, then say, GOOOOAAAAL," \
          " or GOLASO!"
# Using two regular expression to find the duplicated characters
pattern1 = r"O{2,4}"
pattern2 = r"A+"
# Using regular expression method to replace the duplicated characters
string1 = re.sub(pattern1, "O", string1)
string1 = re.sub(pattern2, "A", string1)
# Print out the new string1
print(string1)


