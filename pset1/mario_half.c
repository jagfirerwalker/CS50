#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    char hash = '#';
    char space = ' ';
    do 
    {
        printf("Height: ");
        n = get_int();
    }
    while (n < 0 || n > 23);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
          printf("%c", space);  
        }
        for (int k = 0; k < n-(n-2)+i; k++)
        {
            printf("%c", hash);
        }
        printf("\n");
    }
}

