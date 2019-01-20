from cs50 import get_float


def main():
    change = prompt()
    amount = find_min(round(change * 100))
    print(amount)


def prompt():
    change = get_float('Change owed: ')
    if change < 0:
        return prompt()
    return change


def find_min(cents):
    coins = [25, 10, 5]
    minimum = 0
    for x in range(3):
        minimum += int(cents / coins[x])
        cents %= coins[x]
    return minimum + cents


if __name__ == '__main__':
    main()