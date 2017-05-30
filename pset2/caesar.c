#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    if (argc == 2 && atoi(argv[1]) > 0)
    {
        int key = atoi(argv[1]);
        
        while (key > 26)
        {
            key -= 26;
        }
        
        printf("plaintext: ");
        string plainText = get_string();
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plainText); i < n; i++)
        {
            if (isalpha(plainText[i]) && isupper(plainText[i]))
            {
                if (plainText[i]+key > 'Z')
                {
                    printf("%c",plainText[i]+key-26);
                }
                else
                {
                     printf("%c", plainText[i]+key);
                }
               
            }
            else if (isalpha(plainText[i]) && islower(plainText[i]))
            {
                if (plainText[i]+key > 'z')
                {
                    printf("%c",plainText[i]+key-26);
                }
                else
                {
                     printf("%c", plainText[i]+key);
                }
               
            }
            else
            {
                printf("%c", plainText[i]);
            }
        }
        printf("\n");
    }
    else 
    {
        printf("wrong entry");
        return 1;
    }
}