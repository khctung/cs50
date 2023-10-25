import cs50

def main():
    text = input("Text: ")

    # calculating number of letters
    letters = get_letters(text)
    # calculating number of words
    words = get_words(text)
    #calculating number of sentences
    sentences = get_sentences(text)

    # computing grade level
    L = (letters / words) * 100
    S = (sentences / words) * 100
    grade_level = round(0.0588 * L - 0.296 * S - 15.8);

    # deciding what to print based on grade level
    if grade_level < 1:
        print("Before Grade 1")
    elif grade_level >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {int(grade_level)}")

# function for getting the # of letters
def get_letters(input):
    num_letters = 0
    for i in range(len(input)):
        if (input[i]isalpha()):
            num_letters += 1
    return num_letters

# function for getting the # of words
def get_words(input):
    num_words = 0
    for i in range(len(input)):
        if (input[i].isblank()):
            num_words += 1
    num_words += 1
    return num_words

# function for getting the # of sentences
def get_sentences(input):
    num_sentences = 0
    for i in range(len(input)):
        if (input[i] == '!' or input[i] == '.' or input[i] == '?'):
            num_sentences += 1;
    return num_sentences

main()
