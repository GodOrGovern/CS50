import sys
import string
from cs50 import get_string


def main():
    check_args()
    key = [ord(x.upper()) - 65 for x in sys.argv[1]]
    plaintext = prompt()
    ciphertext = iterate(plaintext, key)
    print(f'ciphertext: {ciphertext}')


def check_args():
    if len(sys.argv) != 2:
        print('error: expected two command line arguments')
        exit(1)
    if not sys.argv[1].isalpha():
        print('key can only contain letters')
        exit(1)


def prompt():
    plaintext = get_string('plaintext: ')
    return plaintext


def iterate(plaintext, key):
    pos = 0
    ciphertext = ''
    for char in plaintext:
        if char.isalpha():
            ciphertext += shift(char, key[pos % len(key)])
            pos += 1
        else: 
            ciphertext += char
    return ciphertext


# source: https://stackoverflow.com/a/8895517/9352652


def shift(plaintext, key):
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