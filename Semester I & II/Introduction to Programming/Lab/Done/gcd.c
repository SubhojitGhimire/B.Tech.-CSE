#include<stdio.h>
int main()
{
    int num1,num2,i;
    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);
    if(num1>num2)
        i=num2;
    else
        i=num1;
    for(;i>=1;--i)
    {
        if(num1%i==0&&num2%i==0)
        {
            printf("HCF of %d and %d is %d",num1,num2,i);
            break;
        }
    }
    return 0;
}
