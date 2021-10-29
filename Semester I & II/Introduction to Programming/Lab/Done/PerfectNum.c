#include<stdio.h>
int main()
{
    int num,i,sum=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    for(i=1;i<num/2;++i)
    {
        if(num%i==0)
            sum=sum+i;
    }
    sum^num?printf("Not a Perfect Number"):printf("Perfect Number");
    return 0;
}
