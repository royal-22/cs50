res = 0
inp = 0
while inp <= 0:
    inp = float(input("Change owed: "))

inp = round(inp * 100)

quarters = inp / 25
dimes = (inp % 25)/10
nickle = ((inp % 25)%10)/5
pennies = ((inp % 25)%10)%5

res += quarters + dimes + nickle + pennies

print(res)