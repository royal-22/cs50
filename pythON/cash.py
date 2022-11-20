<<<<<<< HEAD
money = float(input("Change owed: "))
res = 0
while money < 0:
    money = float(input("Change owed: "))
    
money = round(int(money * 100))

quarters = (money//25)
dimes = (money%25)//10
nickes = ((money%25)%10)//5
pennies = ((money%25)%10)%5 

res += quarters + dimes + nickes + pennies
=======
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

>>>>>>> c4c378e5ccdc660e7426ff845ee7b54664240f1d
print(res)