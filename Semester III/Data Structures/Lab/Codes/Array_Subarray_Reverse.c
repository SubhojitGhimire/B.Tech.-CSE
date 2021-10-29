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