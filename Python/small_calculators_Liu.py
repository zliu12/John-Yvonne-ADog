# import math module
import math


# Addition Function
def addition(x, y):
    sum = x + y
    print(x, " + ", y, " = ", sum)


# Subtraction Function
def subtract(x, y):
    difference = x - y
    print(x, " - ", y, " = ", difference)


# Multiplication Function
def multiply(x, y):
    product = x * y
    print(x, " * ", y, " = ", product)


# Division Function
def divide(x, y):
    # When a number is divided by 0
    if y == 0:
        print("Division error: cannot divide zero")
    # When a number is divided by a none zero number
    else:
        quotient = x / y
        print(x, " / ", y, " = ", quotient)

  
# Square Root Function
def sqrt(x):
    # When the input number is great than or equal to zero
    if x >= 0:
        root = math.sqrt(x)
        print("Square root of ", x, " is:", root)
    # When the input number is  not great than or equal to zero   
    else:
        print("Square root error: cannot take square root of a negative number")


# Verify if the inputs are numbers
while True:
    try:
        num1 = int(input("Enter the first number: "))
        num2 = int(input("Enter the second number: "))
    # When one or both inputs are invalid
    except ValueError:
        print("Not an integer!")
        continue
    # When both inputs are valid
    else:
        addition(num1, num2)
        subtract(num1, num2)
        multiply(num1, num2)
        divide(num1, num2)
        sqrt(x = num1)
        sqrt(x = num2)
    break
    

