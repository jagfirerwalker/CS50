#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do {
    printf("Minutes: ");
    n = get_int();
    }
    while (n < 0);
    
    // 1 minute = 12 bottles
    printf("Bottles: %i\n", n * 12);
}
