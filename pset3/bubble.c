#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int search[] = {3,2,5,1,5,8,7,6};
    
    bool iter;

    do
    {
        iter = false;
        for (int i = 0, n = sizeof(search)/sizeof(search[0]); i < n-1; i++) // go through the whole list
        {
            if (search[i] > search[i+1])
            {
                int temp = search[i];
                search[i] = search[i+1];
                search[i+1] = temp;
                iter = true;
            }
        }
    } while (iter);
}