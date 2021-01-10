
# This Python program creates and stores a multiplication table in a 2D list called MT, and 
# then outputs elements. Print out the tile and the value of the first row and first column
print("Multiplication Table: ")
print("X", end="\t")

# Create an empty list called MT
MT = []

# Print out the first row
i = 1
while i < 11:
    print(i, end="\t")
    i = i + 1
print()

# Append nested empty list to the empty list MT
i = 1
while i < 11:
    MT.append([])

    # Calculate the product of i and j and store the result into MT[i - 1][j]
    j = 1
    while j < 11:
        MT[i - 1].append(i * j)
        j = j +1
    print(i, end="\t")

    # Display the elements
    j = 0
    while j < 10:
        print(MT[i - 1] [j], end="\t")
        j = j + 1
    print()
    i = i + 1
  

   

        
