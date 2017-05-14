#include <cs50.h>
#include <stdio.h>

long long creditcard = 378282246310005;
int creditCardLength(int credicard);
void checkCreditCardMaker(long long creditcard);

int main(void)
{
    //do
   // {
    //printf("Number: ");
    //creditcard = get_long_long;
   // }
   // wihle (creditcard < 0);
    
    checkCreditCardMaker(creditcard);

    
    printf("%lld",(creditcard%100000000-creditcard%10000000)/10000000);
}
   
   
void checkCreditCardMaker (long long n)
{
    if (n/10000000000000 == 34 || n/10000000000000 == 37 || creditCardLength(n) == 15)
    {
        printf("American Express\n");
    } else if ((n/10000000000000 >= 51 && n/10000000000000 <= 55)  || creditCardLength(n) == 16)
    {
        printf("MasterCard\n");
    } else if (n/10000000000000 == 4  || creditCardLength(n) == 13  || creditCardLength(n) == 16)
    {
        printf("Visa\n");
    } else
    {
        printf("Invalid\n");
    }
}
    
int creditCardLength(int n)
{
    // the "length" of 0 is 1:
    int len = 1;

    // and for numbers greater than 0:
    if (n > 0) 
    {
    // we count how many times it can be divided by 10:
    // (how many times we can cut off the last digit until we end up with 0)
        for (len = 0; n > 0; len++) 
        {
            n = n / 10;
        }
    }
    return len;
}