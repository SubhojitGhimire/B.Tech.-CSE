/*
Question: Write a C program to perform Quick Sort:
Instructions: 1. Implement Quick Sort algorithm to sort an unsorted array
              2. Insert the number of elements
              3. Pick the last element as a pivot
              4. Perform partition operation
              5. Display sorted array
*/

//My Approach/Solution:
#include <stdio.h>
#include <stdlib.h>

void quickSort (int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr [high];
        int smaller_index = (low - 1);
        for (int i = low; i<= high-1; ++i)
        {
            if (arr[i] < pivot)
            {
                ++smaller_index;
                int temp = arr [smaller_index];
                arr [smaller_index] = arr [i];
                arr [i] = temp;
            }
        }
        int temp = arr [smaller_index + 1];
        arr [smaller_index + 1] = arr [high];
        arr [high] = temp;
        
        quickSort (arr, low, smaller_index);
        quickSort (arr, smaller_index+2, high);
    }
}

int main ()
{
    int *arr, size;
    //printf ("Enter size of the array: ");
    scanf ("%d", &size);
    arr = (int *) malloc (size * sizeof(int));
    //printf ("Enter elements in the array: ");
    for (int i=0; i<size; ++i)
        scanf ("%d", &arr[i]);
    
    quickSort (arr, 0, size-1);
    
    //printf ("The sorted array is: ");
    for (int i=0; i<size; ++i)
        printf ("%d ", arr[i]);
    
    return 0;
}
