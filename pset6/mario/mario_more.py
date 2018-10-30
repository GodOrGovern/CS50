from cs50 import get_int


def main():
    height = prompt()
    build(height)    


def prompt():
    height = get_int("Height: ")
    if height < 0 or height > 23:
        return prompt()
    return height


def build(height):
    for row in range(height):
        [print(' ', end='') for x in range(1, height - row)]
        [print('#', end='') for n in range(row + 1)]
        print('  ', end='')
        [print('#', end='') for n in range(row + 1)]
        print()


if __name__ == '__main__':
    main()