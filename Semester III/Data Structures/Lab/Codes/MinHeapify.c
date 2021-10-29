#include <stdio.h>

void MinHeapify (int arr ['!'], int size, int s)
{
    int smallest = s;
    int LeftChild = 2*s + 1;
    int RightChild = 2*s + 2;
    if (LeftChild < size && arr [LeftChild] < arr [smallest])
        smallest = LeftChild;
    if (RightChild < size && arr [RightChild] < arr [smallest])
        smallest = RightChild;
    if (smallest != s)
    {
        int temp = arr [s];
        arr [s] = arr [smallest];
        arr [smallest] = temp;
        MinHeapify (arr, size, smallest);
    }
}

void BuildHeap ( int arr ['!'], int size)
{
    for (int i = size/2; i >= 0; --i)
        MinHeapify (arr, size, i);
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

    printf ("\nThe array representation of your Min Heap is: ");
    for (int i=0; i<size; ++i)
        printf ("%d ", arr[i]);

    return 0;
}