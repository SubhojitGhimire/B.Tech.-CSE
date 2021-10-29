/*
Question: Given an array arr[] of positive integers of size N. Write a C program to reverse every sub-array of K group elements.
Instructions:   a. You are supposed to allocate the array or matrix using malloc functions.
                b. You must ensure that your solution defends any test-cases. For instance, 1x1 matrix.
                c. Input should be given by random function and the code snippet of a single dimensional array is given below- 
                    #include<stdlib.h>
                    #include<time.h>
                    srand(time(0));
                    for(i=0;i<n;i++)
                      a[i]=(rand()%(upper_limit-lower_limit +1))+lower_limit;
*/

//My Approach/Solution:
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int *arr, *subarr, i, j, size, k, count;

    printf ("Enter size of the array: ");
    scanf ("%d", &size);

    arr = (int *) malloc (size * sizeof(int));

    printf ("Randomly Generating Array of size %d.\nThis is the array generated: ", size);

    srand (time(0));
    for (i=0; i<size; ++i)
    {
        arr [i] = (rand () % 100);
        printf ("%d ", arr[i]);
    }
        
    printf ("\n\nEnter the grouping (subarray) size: ");
    scanf ("%d", &k);
    if (k > size)
    {
        printf ("Subarray cannot be greater than array... Error!!!");
        exit (0);
    }
    subarr = (int *) malloc (k * sizeof(int));
    
    printf ("Calculating and Printing the reverse of your array in subarrays...\n");

    for (i=0; i<size; )
    {
        j=0; count=0;
        while (j<k && i<size)
        {
            subarr [j++] = arr [i++];
            ++count;
        }
        for (j=count-1; j>=0; --j)
            printf ("%d ", subarr [j]);
    }

    return 0;
}
