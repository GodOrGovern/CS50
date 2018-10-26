from cs50 import get_char

char = get_char("Answer: ")

if char == "Y" or char == "y":
    print("Yes")
elif char == "N" or char == "n":
    print("No")
else:
    print("Invalid input")