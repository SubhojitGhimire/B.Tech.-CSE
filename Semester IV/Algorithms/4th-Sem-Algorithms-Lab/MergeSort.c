/*
Question: Write a C program to perform Merge Sort.
Instructions: 1. Write a C program to implement Merge sort 
              2. Enter the number of Elements
              3. Perform merge sort algorithm
              4. Display sorted order elements
*/

//My Approach/Solution:
#include <stdio.h>
#include <stdlib.h>

void mergeSort (int *arr, int ind_left, int ind_right)
{
    if (ind_left < ind_right)
    {
        int ind_mid = (ind_left + ind_right) / 2;
        mergeSort (arr, ind_left, ind_mid);
        mergeSort (arr, ind_mid+1, ind_right);
        
        int size1 = ind_mid - ind_left + 1;
        int size2 = ind_right - ind_mid;
        int arr1 [size1], arr2 [size2];
        
        for (int i=0; i<size1; ++i)
            arr1 [i] = arr [ind_left + i];
        for (int i=0; i<size2; ++i)
            arr2 [i] = arr [ind_mid + i + 1];
        
        int i=0, j=0, k=ind_left;
        while (i<size1 && j<size2)
        {
            if (arr1[i] <= arr2[j])
                arr [k] = arr1 [i++];
            else
                arr [k] = arr2 [j++];
            ++k;
        }
    
        while (i<size1)
            arr [k++] = arr1 [i++];
        while (j<size2)
            arr [k++] = arr2 [j++];
    }
}

int main ()
{
    int *arr, size;
    
    //printf ("Enter size of the array: ");
    scanf ("%d", &size);
    arr = (int *) malloc (size * sizeof (int));
    
    //printf ("Enter elements in the array: ");
    for (int i=0; i<size; ++i)
        scanf ("%d", &arr[i]);
    
    mergeSort (arr, 0, size-1);
    
    //printf ("The merged and sorted array is: ");
    for (int i=0; i<size; ++i)
        printf ("%d ", arr [i]);
    
    return 0;
}
