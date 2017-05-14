#include <cs50.h>
#include <stdio.h>

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    float dollars;
    int change;
    int counter;
int main(void)
{
    do
    {
        printf("O hail! How much change is owed?\n");
        dollars = get_float(); 
    }
    while (change < 0.00);
    
    change = dollars * 100;
    
    while (change - quarter >= 0)
    {
        counter++;
        change = change - quarter;
        printf("Quarters change: %i\n",change);
    }
    while (change - dime >= 0)
    {
        counter++;
        change = change - dime;
        printf("Dime change: %i\n",change);
    }
    while (change - nickel >= 0)
    {
        counter++;
        change = change - nickel;
        printf("Nickel change: %i\n",change);
    }
        while (change - penny >= 0)
    {
        counter++;
        change = change - penny;
        printf("Penny change:%i\n",change);
    }
    

    printf("Rest: %i \n", change);
    printf("Coins change:%i \n", counter);
}