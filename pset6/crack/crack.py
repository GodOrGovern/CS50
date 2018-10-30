import sys
import string
from crypt import crypt


def main():
    check_args()
    buffer = [''] * 5
    salt = ''.join(sys.argv[1][:2])
    alpha = string.ascii_lowercase + string.ascii_uppercase
    for pos in range(5):
        permute(salt, alpha, buffer, pos)
    print("Couldn't find password")
    exit(1)


def check_args():
    if len(sys.argv) != 2:
        print('error: expected two command line arguments')
        exit(1)


def permute(salt, alpha, buffer, pos):
    for letter in alpha:
        buffer[pos] = letter
        if (pos > 0):
            permute(salt, alpha, buffer, pos - 1)
        attempt = ''.join(buffer)
        if crypt(attempt, salt) == sys.argv[1]:
            print(attempt)
            exit(0)


if __name__ == '__main__':
    main()