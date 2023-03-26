from cs50 import get_string


def main():
    # prompt user for text
    text = get_string("text:")
    # count letters in text
    letters = count_letters(text)
    # count words in text
    words = count_words(text)
    # count sentences in text
    sentences = count_sentences(text)
    # determine avarage number of letters per 100 words
    L = (letters * 100) / words
    # determine avarage number of sentences per 100 words
    S = (sentences * 100) / words
    # determine readability
    index = readability(L, S)
    # print result
    if index >= 1 and index < 16:
        print(f"Grade {index}")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade 16+")


def count_letters(text):
    # set letters variable for counting number of letters
    letters = 0
    # creat for loop for checking character is alpha or not
    for letter in text:
        if letter.isalpha():
            letters += 1
    return letters


def count_words(text):
    # set words variable for counting words in text
    words = 0
    # creat for loop for checking is there any space in text if there is so increase the vale of words variable
    for space in text:
        if space.isspace():
            words += 1
    # always number  of words is greater one time than number of space
    words = words + 1
    return words


def count_sentences(text):
    # set punctuation variable for counting sentences in text
    sentences = 0
    # creat for loop for checking is there any punctuation which means exsisting of sentence
    for punctation in text:
        if punctation == "." or punctation == "?" or punctation == "!":
            sentences += 1
    return sentences


def readability(L, S):
    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index


main()