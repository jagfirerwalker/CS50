import cs50
import sys
import string

#call the main function that shift the text, with the user input and the shift
def textShift(userInput, key):
    #turn the word into a list
    output = list(userInput)
    
    #interate over it and get the location and tha character
    for i, char in enumerate(output):
        # if character is a letter and is capatilized
        if char.isalpha() and char.isupper():
            # use the existing list, at the existing position and shift the origial letter
            # with the shifte letter that wraps around 
            output[i] = chr((ord(char) - ord('A') + key) % 26 + ord('A'))
        # do the same thing for the lower case letter
        elif char.isalpha() and char.islower():
            output[i] = chr((ord(char) - ord('a') + key) % 26 + ord('a'))
        else:
            # and if it is no letter just add the symbol
            output[i] = char
    # join all the list items into a string and return it
    code = ''.join(output)
    return code
    
# check if the user entered a second statement after the .py
if sys.argv[1] == False:
    print("command line: python caesar.py int > 0")
    sys.exit(1)

# call the main program and return the changed word in the next line
print(textShift(input("plainText: "), int(sys.argv[1])))

