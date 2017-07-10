import cs50
import string
import sys

if len(sys.argv) == 2:
    for i in sys.argv[1]:
        if i.isalpha() == False:
            print("Wrong Entry")
            sys.exit(1)
    
    codeLetter = 0
    plainText = list(input("plainText: "))
    print("ciphertext: ", end ="")
    
    for i, char in enumerate(plainText):
        if char.isalpha():
            nofc = ord(char)
            
            if codeLetter >= len(sys.argv[1]):
                codeLetter = 0

                
            nofargv = ord(str.upper(sys.argv[1][codeLetter]))
            nofa = ord('A')
                
            if (char.isupper() and ((nofc + nofargv) - 65) > ord('Z')) or (char.islower() and ((nofc + nofargv) - 65) > ord('z')):
                print(chr((nofc + nofargv) - 65 - 26), end="") 
                #print(ord(sys.argv[1][codeLetter]), sys.argv[1][codeLetter])
                #print(ord(char), char)
            else:
                print(chr((nofc + nofargv) - 65), end="")  
                #print(sys.argv[1][codeLetter])
            codeLetter += 1
        else:
            print(char, end="")
else:
    print("wrong entry")
print()