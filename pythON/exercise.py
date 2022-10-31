h = int(input("Height: "))

for i in range(h):
    for z in range(0, h - i - 1):
        print(" ", end="")
        
    for y in range(0, i+1): 
        print("#", end="")

    print(" ", end="")

    for x in range(0, i+1):
        print("#", end="")

    print()


    