#include<stdio.h>
int main()
{
    int num,temp,sum=0,mod,i;
    printf("Enter a number: ");
    scanf("%d",&num);
    temp=num;
    for(;temp!=0;)
    {
        mod=temp%10;
        sum=sum+mod;
        temp=temp/10;
    }
    printf("Sum of the digits of %d is %d",num,sum);
	return 0;
}
