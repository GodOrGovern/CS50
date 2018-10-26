import sys
from cs50 import get_string

book = [
    "Chen",
    "Kernighan",
    "Leitner",
    "Lewis",
    "Malan",
    "Muller",
    "Seltzer",
    "Shieber",
    "Smith"
]

name = get_string("Name: ")
if name in book:
    print(f"Calling {name}")