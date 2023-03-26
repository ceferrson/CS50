from cs50 import get_int

numberOfDigits = 0


def main():
    # prompt user for card number
    cardNumber = int(input("Enter the card number:"))

    # calculate number of card number
    numberOfDigits = 0

    # copy card number to another integer
    number = cardNumber

    while number != 0:
        number = int(number / 10)
        numberOfDigits += 1

    # checking Luhn's algorithm
    checksum = check_sum(cardNumber)

    if checksum == False:
        print("INVALID")

    # checking card is visa or not
    visa = visa_card(cardNumber, numberOfDigits)

    if visa:
        print("VISA")

    # checking card is mastercard or not
    masterCard = master_card(cardNumber, numberOfDigits)

    if masterCard:
        print("MASTERCARD")

    # checking card is amex or not
    amex = american_express_card(cardNumber, numberOfDigits)

    if amex:
        print("AMEX")

    # checking general validity of card number

    if visa != True and masterCard != True and amex != True:
        print("INVALID")


def check_sum(cardNumber):

    # define variable for copying  card number
    number = cardNumber
    checksum = 0

    while number != 0:
        # take last digit for 1 stage
        LastDigit = number % 10
        # iterate card number
        number = int(number / 10)
        # sum of digits which are not multiplied
        checksum += LastDigit
        # take last digit for 2 stage
        LastDigit = number % 10
        # itarate card number
        number = int(number / 10)
        # multiply by 2
        LastDigit = LastDigit * 2
        # result of multiplication could be great than 9 so we take that value as digit(example 18 we take as 1 and 8)
        first = int(LastDigit / 10)
        second = LastDigit % 10
        # sum all values: multiplied and unmultiplied
        checksum += first + second

    if checksum % 10 == 0:
        return True
    else:
        return False


def visa_card(cardNumber, numberOfDigits):
    # for finding card number starts with which digit (if number of card number is 13)
    first_digit = int(cardNumber / 1000000000000)
    # for finding card number starts with which digit (if number of card_number is 16)
    first_digit1 = int(cardNumber / 1000000000000000)
    # for visa card with 13 digits
    if (numberOfDigits == 13 and first_digit == 4):
        return True
    # for visa card with 16 digits
    elif (numberOfDigits == 16 and first_digit1 == 4):
        return True
    else:
        return False


def master_card(cardNumber, numberOfDigits):

    # for finding card number starts which number(if number of card is 16 digit)
    master = int(cardNumber / 100000000000000)

    # if card number starts with from 51 till 55(m)
    if ((master >= 51) and (master < 56) and (numberOfDigits == 16)):

        return True

    # if card number doesn't fit with mastercard , then return false
    else:
        return False


def american_express_card(cardNumber, numberOfDigits):

    # for finding card number starts with which number(if number of card number is 15 digit)
    american = int(cardNumber / 10000000000000)

    # if card number starts with 34 or 37 and number of digits in card number is 15
    if (((american == 34) and (numberOfDigits == 15)) or ((american == 37) and (numberOfDigits == 15))):

        return True

    # if card number doesn't fit with amex card, then return false
    else:
        return False


if __name__ == "__main__":
    main()
