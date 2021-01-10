
# Description given
# inStock - 2D list (row size:10, column size:4)
# alpha - 1D list with 20 elements.
# beta - 1D list with 20 elements.
# gamma = [11, 13, 15, 17]
# delta = [3, 5, 2, 6, 10, 9, 7, 11, 1, 8]

# a. Write the definition of the function setZero that initializes any one-dimensional list to 0 (alpha and beta).
def setZero(size):
    a = [0] * size
    return a

# b. Write the definition of the function inputArray that prompts the user to input 20 numbers and stores the numbers into alpha.
def inputArray(alpha):
    print("Enter 20 integers: ")
    for i in range(20):
        alpha[i] = int(input())
    print()

# c. Write the definition of the function doubleArray that initializes the elements of beta to two times the corresponding
# elements in alpha.  
def doubleArray(beta, alpha):
    for i in range(20):
        beta[i] = alpha[i] * 2

# d. Write the definition of the function copyGamma that sets the elements of the first row of inStock from gamma and the remaining
# rows of inStock to three times the previous row of inStock
def copyGamma(gamma, inStock):
    for i in range(10):
        inStock. append([])
        for j in range(4):
            if i == 0:
                inStock[i]. append(gamma[j])
            else:
                inStock[i]. append(inStock[i - 1][j] * 3)

# e. Write the definition of the function copyAlphaBeta that stores alpha into the first five rows of inStock and beta into the last five
# rows of inStock.
def copyAlphaBeta(alpha, beta, inStock):
    m = 0
    n = 0
    for i in range(10):
        for j in range(4):
            if i < 5:
                inStock[i][j] = alpha[m]
                m = m + 1
            else:
                inStock[i][j] = beta[n]
                n = n + 1

# f. Write the definition of the function printArray that prints any one-dimensional list.  The function must contain only one loop to
# print any one-dimensional list.  
def printArray(array):
    print(*array[:10], sep="\t")
    print(*array[10:], sep="\t")

# g. Write the definition of the function setInStock that prompts the user to input the elements for the first column of inStock.
# The function should then set the elements in the remaining columns to two times the corresponding element in the previous
# column, minus the corresponding element in delta.
def setInStock(inStock, delta):
    print("Enter 10 integers: ")
    for i in range(10):
        inStock[i][0] = int(input())
    for i in range (1, 4):
        for j in range(10):
            inStock[j][i] = (inStock[j][i - 1] * 2) - delta[j]
    print()

def printInStock(inStock):
    for i in range(10):
        print(*inStock[i],sep="\t")

# Main code, initialization, and call functions
# Initialize alpha, beta, inStock, gamma, delta
alpha = []
beta = []
inStock = []
gamma = [11, 13, 15, 17]
delta = [3, 5, 2, 6, 10, 9, 7, 11, 1, 8]

# Calling functions
alpha = setZero(20)
print("Alpha after initialization: ")
printArray(alpha)
print()

beta = setZero(20)

inputArray(alpha)
print("Alpha after reading 20 numbers: :")
printArray(alpha)
print()

doubleArray(beta, alpha)
print("Beta after a call to doubleArray: ")
printArray(beta)
print()

copyGamma(gamma, inStock)
print("inStock after a call to copyGamma: ")
printInStock(inStock)
print()

copyAlphaBeta(alpha, beta, inStock)
print("inStock after a call to copyAlphaBeta: ")
printInStock(inStock)
print()

setInStock(inStock, delta)
print("inStock after a call to setInStock: ")

printInStock(inStock)








    
    
