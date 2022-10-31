import sys

def main():
    while True:
        inp = input("Number: ")
        length = len(inp)
        if length > 0 and int(inp):
            break

    if length > 16 or length < 13:
        print("INVALID")
        sys.exit(0)

    copyCard = [int(n) for n in inp]
    res = 0

    oddNums = copyCard[-2::-2]
    evenNums = copyCard[-1::-2]
    res += sum(evenNums)

    for n in oddNums:
        l = n*2
        if l >= 10:
            res += (l%10)
            l //=10
        res += l

    if res%10 != 0:
        print("INVALID")
        sys.exit(2)
    
    f = copyCard[0]
    s = copyCard[1]
    
    if length == 15 and (f == 3 and (s == 4 or s == 7)):
        print("AMERICAN EXPRESS")
    elif length == 16 and (f == 5 and (1<=s<=5)):
        print("MASTERCARD")
    elif (length == 14 or length == 16) and f == 4: 
        print("VISA")



if __name__ == "__main__":
    main()