#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void bubblesort (int *arr, int size, int flag);
void selectionsort (int *arr, int size, int flag);
void insertionsort (int *arr, int size, int flag);

int main()
{
    int *arr, *temparr, size, i, j, flag;
    clock_t start, end;
    double bubble_t, insertion_t, selection_t;
    printf ("Enter the size of the array: ");
    scanf ("%d", &size);

    arr = (int *) malloc (size * sizeof(int));
    temparr = (int *) malloc (size * sizeof(int));

    printf ("\nGenerating Random Elements into the array...\n");

    srand (time(0));
    for (i=0; i<size; ++i)
    {
        arr [i] = rand() % 100;
        temparr[i] = arr[i];
    }

    printf ("This is the array created: ");
    for (i=0; i<size; ++i)
    {
        printf("%d  ", arr[i]);
    }

    getch();

    for (j=0; j<2; ++j) 
    {
        if (j==0)
        {
            printf ("\n\n\n#######################\n");
            printf ("ASCENDING ORDER SORTING");
            printf ("\n#######################");
            flag = 0;
        }
        else if (j==1)
        {
            printf ("\n\n\n########################\n");
            printf ("DESCENDING ORDER SORTING");
            printf ("\n########################");
            flag = 1;
        }
        
        start = clock ();
        printf ("\n\nBubble Sorting the Array... Please Wait...\n");
        bubblesort (arr, size, flag);
        end = clock ();
        bubble_t = (double)(end-start)/CLOCKS_PER_SEC;
        printf ("\nTime taken by bubble sort is %lf.", bubble_t);

        getch();

        for (i=0; i<size; ++i)
        {
            arr[i] = temparr[i];
        }

        start = clock ();
        printf ("\n\nSelection Sorting the Array... Please Wait...\n");
        selectionsort (arr, size, flag);
        end = clock ();
        selection_t = (double) (end-start)/CLOCKS_PER_SEC;
        printf ("\nTime taken by selection sort is %lf.", selection_t);

        getch();

        for (i=0; i<size; ++i)
        {
            arr[i] = temparr [i];
        }

        start = clock();
        printf ("\n\nInsertion Sorting the Array... Please Wait...\n");
        insertionsort (arr, size, flag);
        end = clock ();
        insertion_t = (double) (end - start)/CLOCKS_PER_SEC;
        printf ("\nTime taken by insertion sort is %lf.", insertion_t);
        getch();
    }

    return 0;
}

void bubblesort (int *arr, int size, int flag)
{
    int i, j, temp; 
    if (!flag) 
        for (i=0; i<size-1; ++i)          
        {
            for (j = 0; j<size-i-1; ++j)
            {
                if (arr[j] > arr[j+1]) 
                {
                    temp = arr [j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }           
        }
    else
        for (i=0; i<size-1; ++i)          
        {
            for (j = 0; j<size-i-1; ++j)
            {
                if (arr[j] < arr[j+1]) 
                {
                    temp = arr [j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }           
        }
    printf ("Sorted: ");
    for (i=0; i<size; ++i)
    {
        printf ("%d  ", arr[i]);
    }
}

void selectionsort (int *arr, int size, int flag)
{
    int i, j, temp, ind;
    if (!flag)
        for (i=0; i<size-1; ++i)
        {
            ind = i;
            for (j= i+1; j<size; ++j)
            {
                if (arr[j] < arr[ind])
                    ind = j;
            }
            temp = arr [i];
            arr [i] = arr[ind];
            arr[ind] = temp;
        }
    else
        for (i=0; i<size-1; ++i)
        {
            ind = i;
            for (j= i+1; j<size; ++j)
            {
                if (arr[j] > arr[ind])
                    ind = j;
            }
            temp = arr [i];
            arr [i] = arr[ind];
            arr[ind] = temp;
        }
    printf ("Sorted: ");
    for (i=0; i<size; ++i)
    {
        printf ("%d  ", arr[i]);
    }
}

void insertionsort (int *arr, int size, int flag)
{
    int i, j, key;
    if (!flag)
        for (i=1; i<size; ++i)
        {
            key = arr[i];
            for (j=i-1; (j>=0 && arr[j]>key); --j)
            {
                arr[j+1] = arr[j];
            }
            arr [j+1] = key;
        }
    else
        for (i=1; i<size; ++i)
        {
            key = arr[i];
            for (j=i-1; (j>=0 && arr[j]<key); --j)
            {
                arr[j+1] = arr[j];
            }
            arr [j+1] = key;
        }
    printf ("Sorted: ");
    for (i=0; i<size; ++i)
    {
        printf ("%d  ", arr[i]);
    }
}