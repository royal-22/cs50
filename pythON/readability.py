def countLetters(text, length):
    count = 0
    for i in range(length):
        if text[i].isalpha():
            count+=1
    return count

def countWords(text, length):
    count = 1
    for i in range(length):
        if ord(text[i]) == 32:
            count += 1
    return count

def countSentence(text, length):
    count = 0
    for i in range(length):
        l = ord(text[i])
        if l == 46 or l == 63 or l == 33:
            count += 1
    return count


def main():
    text = input("Text: ")
    length = len(text)

    letters = countLetters(text, length)
    words = countWords(text, length)
    sentence = countSentence(text, length)

    L = (float(letters) / float(words)) * 100
    S = (float(sentence) / float(words)) * 100

    index = 0.0588 * L - 0.296 * S - 15.8

    grade = round(index)


    if 1 <= grade < 16: 
        print(f"Grade {grade}")
    elif grade >= 16:
        print("Grade16+")
    else: 
        print("Before Grade 1")

if __name__ == "__main__":
    main() 