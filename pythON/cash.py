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
print(res)