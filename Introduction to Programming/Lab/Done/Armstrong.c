#include<stdio.h>
#include<math.h>
int main()
{
    int num,sum=0,mod,temp,i,j;
    printf("Enter a number: ");
    scanf("%d",&num);
    temp=num;
    for(i=1,j=0;i<=num;i=i*10,++j);
    while(temp!=0)
    {
        mod=temp%10;
        sum=sum+pow(mod,j);
        temp=temp/10;
    }
    if(sum==num)
        printf("The number is Armstrong");
    else
        printf("The number is not Armstrong");
    return 0;
}
