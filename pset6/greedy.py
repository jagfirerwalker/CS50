import cs50

quarter = 25.00
dime = 10.00
nickel = 5.00
penny = 1.00
dollars = 0.00
change = 0.00
counter = 0

while True:
    print("O hail! How much change is owed? ", end="")
    dollars = cs50.get_float()
    if dollars > 0.00:
        break

change = dollars * 100.00

counter += change // quarter
change %= quarter
print("Quarters ($.25) change: ", round(change/100,2), "Coins change: ", round(counter))

if change != 0:
    counter += change // dime
    change %= dime
    print("Dime ($.10) change: ",  round(change/100,2), "Coins change: ", round(counter))
    
    if change != 0:
        counter += change // nickel
        change %= nickel
        print("Nickel ($.05) change: ", round(change/100,2), "Coins change: ", round(counter))
       
        if change != 0:
            counter += change // penny
            change %= penny
            print ("Penny ($.01) change: ", round(change/100,2), "Coins change: ", round(counter))

print()    
print("Rest: ", round(change,2))
print("Coins change: ", round(counter))

 
    
