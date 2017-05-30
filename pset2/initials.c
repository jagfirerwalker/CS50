#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // set up a counter that will track of how many spaces there are
    int spaceCounter = 0;
    
    // get user input
    string name = get_string();
    
    // setup a char that is at max as long as the maximum amount of letters in input
    char initials[strlen(name)];
    
    // check if the first space is empty of not. If not empty print out first initial in caps and set the counter to 1
    if (!isspace(name[0]))
    {
        initials[0] = toupper(name[0]);
        spaceCounter = 1;
        printf("%c", initials[0]);
    } 
    // loop through the length of the input
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        // if you found a space
        if (isspace(name[i]))
        {
            // and if the character after is not a space and it isn't the last space entered, print out the next caps initial
            if (!isspace(name[i+1]) && i+1 != n) 
             {
                spaceCounter++;
                initials[spaceCounter] = toupper(name[i+1]);
                printf("%c",initials[spaceCounter]);
              }
        }
    }
    printf("\n");
}
