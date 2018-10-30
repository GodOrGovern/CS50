from cs50 import get_int


def main():
    credit = prompt()
    length = len(credit)
    checksum(credit)
    identify(credit, length)


def prompt():
    credit = get_int('Credit Card Number: ')
    while len(str(credit)) not in [13, 15, 16]:
        return card('INVALID')
    return str(credit)


def checksum(credit):
    check = 0
    doubled = [str(int(x) * 2) for x in credit[-2::-2]]
    joined = ''.join(doubled)
    for x in joined:
        check += int(x)
    for x in credit[-1::-2]:
        check += int(x)
    if check % 10 != 0:
        return card('INVALID')


def identify(credit, length):
    if length in [13, 16]:
        if credit[0] == '4':
            card('VISA')
    if length == 16:
        if credit[:2] in ['51', '52', '53', '54', '55']:
            card('MASTERCARD')
    if length == 15: 
        if credit[:2] in ['34', '37']:
            card('AMEX')
    card('INVALID')


def card(brand):
    print('%s' % brand)
    exit(0)


if __name__ == '__main__':
    main()