/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (value < 0)
    {
        return false;
    }
    else 
    {
        int min = 0;
        int max = n-1;
        
    
        while (min <= max)
        {
            int midPoint = (min + max) / 2;
            if (value == values[midPoint])
            {
                return true;
            }
            else if (value > values[midPoint])
            {
                min = midPoint + 1;
            }
            else
            {
                max = midPoint - 1;
            }
        } 
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    bool iter;

    do
    {
        iter = false;
        for (int i = 0; i < n-1; i++)
        {
            if (values[i] > values[i+1])
            {
                int temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                iter = true;
            }
        }
    } while (iter);
    return;
}
