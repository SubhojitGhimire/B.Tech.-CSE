/*
Question: Write a C program to implement binary search.
*/

//My Approach/Solution:
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, size, i, find, index, flag=0;
    int ub, lb, mid;

    printf ("Enter the size of the array: ");
    scanf ("%d", &size);

    arr = (int *) malloc (size * sizeof(int));

    printf ("\nEnter your SORTED Array: ");
    for (i=0; i<size; ++i)
    {
        scanf ("%d", &arr[i]);
    }

    printf ("\nEnter the element whose location you wish to find: ");
    scanf ("%d", &find);

    ub = size-1;
    lb = 0;

    while (lb<=ub)
    {
        mid = (lb + ub) / 2;
        
        if (arr[mid] == find)
        {
             index = mid;
             ++flag;
             break;
        }           
        else if (arr[mid] < find)
            lb = mid + 1;
        else
            ub = mid - 1;        
    }

    if (flag)
        printf ("\nThe location of %d is %d in the array.", find, mid+1);
    else
        printf ("\nThis element %d doesn't exist in the array.", find);
    

    return 0;
}   
