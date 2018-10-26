from cs50 import get_string

str_one = get_string("String One: ")
str_two = get_string("String Two: ")

if str_one == str_two:
    print("Same")
else:
    print("Different")