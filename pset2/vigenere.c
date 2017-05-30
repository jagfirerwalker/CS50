#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char* argv[])
{
    if (argc == 2) //check if the run command has a second statement e.g. = ./vigenere HALLO 
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++) // check if the second statement all alphabetical
        {
            if (!isalpha(argv[1][i])) // if non alphabetical character found, throw error message
            {
                printf("wrong entry\n");
                return 1;
            }
        }
        int codeLetter = 0;
        printf("plaintext: ");
        string plainText = get_string();
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plainText); i < n; i++) //go through the length of the entered word
        {
            if (isalpha(plainText[i])) // is entry alphabetical 
            {
                if (codeLetter >= strlen(argv[1])) // check if you reached the end of the code word and start from the beginning
                {
                    
                    codeLetter = 0;
                }
                if ( ( isupper(plainText[i]) && (plainText[i] + toupper(argv[1][codeLetter]) - 65) > 'Z') || ( islower(plainText[i]) && (plainText[i] + toupper(argv[1][codeLetter]) - 65) > 'z')) // see if the entered letter is capitalized or not. Check if the changed letter is bigger than z/Z
                {
                    printf("%c", (plainText[i] + toupper(argv[1][codeLetter]) - 65 - 26)); // if ciphered letter is bigger than Z/z wrap around and start from a/A
                }
                else
                {
                    printf("%c", plainText[i]+(toupper(argv[1][codeLetter])- 65)); // else print out the ciphered lettr
                }
                codeLetter++; // go to the next position in the code word
                
            } else 
            {
                printf("%c", plainText[i]); // print out non alphabetical characters
            }
        }
        printf("\n");
    }
    else 
    {
        printf("wrong entry\n");
        return 1;
    }
}