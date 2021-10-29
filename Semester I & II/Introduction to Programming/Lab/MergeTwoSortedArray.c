#include<stdio.h>
int main()
{
    int arr1[5],arr2[5],arr3[10],a=0,i,j;
    printf("Array 1\n");
    for(i=0;i<5;++i)
        scanf("%d",&arr1[i]);
    printf("Array 2\n");
    for(i=0;i<5;++i)
        scanf("%d",&arr2[i]);
    for(i=0,j=0;i<5&&j<5;++a)
    {
            if(arr1[i]<arr2[j])
                arr3[a]=arr1[i++];
            else
                 arr3[a]=arr2[j++];
    }
    while(i<5)
             arr3[a++]=arr1[i++];
    while(j<5)
            arr3[a++]=arr2[j++];
    printf("Array after Merging: ")
    for(i=0;i<10;++i)
        printf("%d ",arr3[i]);
    return 0;
}
