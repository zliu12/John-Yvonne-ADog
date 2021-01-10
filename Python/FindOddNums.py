
# Set valid responses
responses = ["Y", "y", "N", "n"]

# A: Prompt the user to input two positive integers, set as variable firstNum and variables secondNum
# Loop over when condition is true
while True:
    print("\nEnter two positive integer numbers.\nFirst number must be less than the second number you enter:")

    # Verify the content of inputs, convert to type int (input type is string by default) if it`s valid
    try:
        firstNum, secondNum = input("Enter numbers: ").split(" ")
        firstNum = int(firstNum)
        secondNum = int(secondNum)

    # Output error message if inputs are invalid
    except:
        print("\nIncorrect Input.\nPlease try again.")
        continue

    # When content of inputs are valid
    # Verify the first input is less than the second input, output error message if not
    if (firstNum > secondNum):
        print("\nFirst number must be less than the second number!\nPlease try again.")
    # Verify inputs are positive, output error message if not
    elif (firstNum < 0 or secondNum < 0):
        print("\nNo negative numbers!\nPlease try again.")
    # Verify inputs are non zero, output error message if not
    elif (firstNum == 0 or secondNum == 0):
        print("\nNo zero!\nPlease try again.")

    # when condition of inputs are invalid
    else:
        # B: output all odd numbers between firstNum and secondNum by using while loop
        # i starts from firstNum and increments by each time 1, until i gets to secondNum
        print("\nOdd integers between ", str(firstNum), " and ", str(secondNum), " are:")
        i = firstNum
        while (i <= secondNum):
            # Calculate: find odd i by if the remainder of 2 divides i is not equal to 0
            if (i % 2 != 0):
                # Output odd i
                print(i, end=" ")
            i = i + 1
        print("\n")

        # C: Output the sum of all even numbers between firstNum and secondNum by using while loop
        # evenSum denotes the sum of all even numbers between firstNum and secondNum, it starts from 0
        evenSum = 0
        # i starts from firstNum and increments by 1 each time, until i gets to secondNum
        i = firstNum
        while (i <= secondNum):
            # Calculate: find even i if the remainder of 2 divides i equal to 0, add even i to evenSum
            if (i % 2 == 0):
                evenSum = evenSum + i
            i = i + 1
        # Output: sum of even integers between firstNum and secondNum
        print("Sum of even integers between ", str(firstNum), " and ", str(secondNum), " = ", str(evenSum))

        # D: Output the sum of the square of the odd numbers between firstNum and secondNum by using while loop
        # sumSqtOdd denotes the sum of the square of the odd numbers between firstNum and secondNum
        sumSqrtOdd = 0
        # i starts from firstNum and increments by 1 each time, until i gets to secondNum
        i = firstNum
        while (i <= secondNum):
            # Calculate: find odd i if the remainder of 2 divides i is not equal to 0, add i squared to sumSqrtOdd
            if (i % 2 != 0):
                sumSqrtOdd = sumSqrtOdd + (i ** 2)
            i = i + 1
        # Output: sum of the square of the odd numbers between firstNum and secondNum
        print("\nSum of the squares of odd integers between ", str(firstNum), " and ", str(secondNum), " = ",
              sumSqrtOdd, "\n")

        # Prompt the message to ask if the user would like to try another example
        userChoice = input("\nDo you want to repeat this program?\ny/n\n> ")
        # When user choice does not match the responses
        while (userChoice not in responses):
            # Prompt the error message and ask the user to choose again
            print("Your response is invalid.\nPlease try again.")
            userChoice = input("\nDo you want to repeat this program?\ny/n\n> ")
        # When user choice matches the responses and users choose not to continue: output bye message and terminate
        # program. Otherwise, prompt the message to ask user to enter another example
        if (userChoice == "n" or userChoice == "N"):
            print("\nBye!")
            break
