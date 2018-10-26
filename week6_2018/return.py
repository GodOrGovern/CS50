from cs50 import get_int

def main():
    x = get_int("x: ")
    print(f"{x} squared is {square(x)}")

def square(n):
    return n**2

if __name__ == "__main__":
    main()