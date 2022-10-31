def count(arr, length):
    count = 0
    for i in range(length - 1):
        if arr[i] > arr[i+1]:
            count += 1
    return count

def main():
    times = int(input())
    while times > 0:
        l = int(input())
        arr = [int(x) for x in input().split()]
        c = count(arr, l)
        print(c)
        times -= 1

main()
