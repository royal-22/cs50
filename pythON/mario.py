
def main():
    h = getHeight()
    for i in range(h):
        print("#")

def getHeight():
    while True:
        n = int(input("Height: "))
        if n > 0:
            return n

main()