
from multiprocessing.sharedctypes import Value


def main():
    h = getHeight()
    for i in range(h):
        print("#")

def getHeight():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("That's not an integer.")

main()