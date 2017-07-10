import cs50

value = 0

while True:
    cc = input("Please enter your credit card number: ")
    if cc.isdecimal() and int(cc) > 0:
        break

lenOfC = len(str(cc))-1

for i in range(lenOfC):
    if i % 2 == 0:
        value += int(cc[lenOfC-i])
    else:
        if int(cc[lenOfC-i]) * 2 > 10:
            value += (int(cc[lenOfC-i]) * 2) % 10 + 1
        else:
            value += int(cc[lenOfC-i]) * 2

value += int(cc[0])

if value % 10 != 0:
    print("Invalid")
else:
    print("Valid")
    
    if lenOfC == 14:
        if int(cc[0]) == 3:
            if int(cc[1]) == 4 or int(cc[1]) == 7:
                print("Amex")
    
    if lenOfC == 15:
        if int(cc[0]) == 5 and (int(cc[1]) == 1 or int(cc[1]) == 2 or int(cc[1]) == 3 or int(cc[1]) == 4 or int(cc[1]) == 5):
            print("MasterCard")
    
    if lenOfC == 12 or lenOfC == 15:
        if int(cc[0]) == 4:
            print("Visa")

            
        