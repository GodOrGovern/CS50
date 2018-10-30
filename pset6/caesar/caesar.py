import sys
import string
from cs50 import get_string


def main():
    check_args()
    plaintext = prompt()
    ciphertext = shift(plaintext)
    print(f'ciphertext: {ciphertext}')


def check_args():
    if len(sys.argv) != 2:
        print('error: expected two command-line arguments')
        exit(1)


def prompt():
    plaintext = get_string('plaintext: ')
    return plaintext


# source: https://stackoverflow.com/a/8895517/9352652


def shift(plaintext):
    key = int(sys.argv[1]) % 26
    alpha_low = string.ascii_lowercase
    shift_low = alpha_low[key:] + alpha_low[:key]
    table_low = str.maketrans(alpha_low, shift_low)
    alpha_up = string.ascii_uppercase
    shift_up = alpha_up[key:] + alpha_up[:key]
    table_up = str.maketrans(alpha_up, shift_up)
    cipher_low = plaintext.translate(table_low)
    return cipher_low.translate(table_up)


if __name__ == '__main__':
    main()