#include<stdio.h>
int main()
{
    int arr['!'],k,i,j,temp,size;
    printf("Input terms in your array... Enter 0 to terminate\n");
    scanf("%d",&arr[0]);
    for(i=1;arr[i-1]!=0;++i)
    {
        scanf("%d",&arr[i]);
    }
    size=i-1;
    printf("Enter how many terms to shift? ");
    scanf("%d",&k);
    for(i=0;i<k;++i)
    {
        temp=arr[0];
        for(j=0;j<size-1;++j)
        {
            arr[j]=arr[j+1];
        }
        arr[j]=temp;
    }
    printf("New Array Elements= ");
    for(i=0;i<size;++i)
    printf("%d ",arr[i]);
    return 0;
}
