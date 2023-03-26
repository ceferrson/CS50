from cs50 import  get_float


def main():
    # Ask how many dollars the customer is owed
    dollars = get_dollars()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(dollars)
    dollars = dollars - quarters * 25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(dollars)
    dollars = dollars - dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(dollars)
    dollars = dollars - nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(dollars)
    dollars = dollars - pennies * 1

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    print(f"{coins}")


def get_dollars():
    # prompt an integer form user
    while True:
        dollars = get_float("Change owed:")
        if dollars > 0:
            break

    return dollars*100


def calculate_quarters(dollars):
    quarters = int(dollars / 25)

    return quarters


def calculate_dimes(dollars):
    dimes = int(dollars / 10)

    return dimes


def calculate_nickels(dollars):
    nickels = int(dollars / 5)

    return nickels


def calculate_pennies(dollars):
    pennies = int(dollars / 1)

    return pennies


if __name__ == "__main__":
    main()
