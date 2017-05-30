#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int search[] = {1,2,3,4,5,6,7,8};
    printf("Enter Needle: ");
    int needle = get_int();
    
    int min = search[0]; // define lowest entry
    int max = search[sizeof(search)/sizeof(search[0]) -1]; // get highest entry
    

    while (min <= max) // check if low hasn't gone over max entry
    {
        int midPoint = (min + max) / 2; // get the mid point between the high/low point
        if (needle == search[midPoint-1])
        {
            printf("Found\n");
            return true;
        }
        if (needle > search[midPoint-1])
        {
            min = midPoint + 1;
        }
        if (needle < search[midPoint-1])
        {
            max = midPoint - 1;
        }
    }
}