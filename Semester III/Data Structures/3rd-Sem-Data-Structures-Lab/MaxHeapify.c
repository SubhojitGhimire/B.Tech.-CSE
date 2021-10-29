/*
Question: Write a C program to perform max heapify operation.
*/

//My Approach/Solution:
#include <stdio.h>

void MaxHeapify (int arr ['!'], int size, int l)
{
    int largest = l;
    int LeftChild = 2*l + 1;
    int RightChild = 2*l + 2;
    if (LeftChild < size && arr [LeftChild] > arr [largest])
        largest = LeftChild;
    if (RightChild < size && arr [RightChild] > arr [largest])
        largest = RightChild;
    if (largest != l)
    {
        int temp = arr [l];
        arr [l] = arr [largest];
        arr [largest] = temp;
        MaxHeapify (arr, size, largest);
    }
}

void BuildHeap ( int arr ['!'], int size)
{
    for (int i = (size/2)-1; i >= 0; --i)
        MaxHeapify (arr, size, i);
}

int main()
{
    int arr ['!'], size;

    printf ("Enter size of the heap: ");
    scanf ("%d", &size);

    printf ("Enter Elements in Heap:\n");
    for (int i=0; i<size; ++i)
        scanf ("%d", &arr[i]);
    
    BuildHeap (arr, size);

    printf ("\nThe array representation of your Max Heap is: ");
    for (int i=0; i<size; ++i)
        printf ("%d ", arr[i]);

    return 0;
}
