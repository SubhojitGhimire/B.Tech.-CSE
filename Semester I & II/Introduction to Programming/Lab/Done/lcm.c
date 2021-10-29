#include<stdio.h>
int main()
{
    int num1,num2,i;
    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);
    if(num2>num1)
        i=num2;
    else
        i=num1;
    for(;i>0;i=i+num1)
    {
        if(i%num1==0&&i%num2==0)
        {
            printf("LCM of %d and %d is %d",num1,num2,i);
            break;
        }
    }
    return 0;
}

//Also, LCM=(num1*num2)/HCF(num1,num2)
