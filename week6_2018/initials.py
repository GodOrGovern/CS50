from cs50 import get_string

name = get_string("Name: ")
initials = ""

for char in name:
    if char.isupper():
        initials += char

print(initials)