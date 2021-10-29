#include <stdio.h>

void Heapify (int arr ['!'], int size, int p)
{
    int parent = p;
    int LeftChild = 2*p + 1;
    int RightChild = 2*p + 2;
    if (LeftChild < size && arr [LeftChild] > arr [parent])
        parent = LeftChild;
    if (RightChild < size && arr [RightChild] > arr [parent])
        parent = RightChild;
    if (parent!= p)
    {
        int temp = arr [p];
        arr [p] = arr [parent];
        arr [parent] = temp;
        Heapify (arr, size, parent);
    }
}

void HeapSort (int arr ['!'], int size)
{
    for (int i = size/2 - 1; i>=0; --i)
        Heapify (arr, size, i);
    for (int i = size - 1; i>0; --i)
    {
        int temp = arr [0];
        arr [0] = arr [i];
        arr [i] = temp;
        Heapify (arr, i, 0);
    }
}

int main()
{
    int arr['!'], size;
    
    //printf ("Enter number of elements: ");
    scanf ("%d", &size);
    
    //printf ("Enter Elements:\n");
    for (int i=0; i<size; ++i)
        scanf ("%d", &arr[i]);
    
    HeapSort (arr, size);
    
    //printf ("Output: ");
    for (int i=0; i<size; ++i)
        printf ("%d ", arr[i]);
    
    return 0;
}