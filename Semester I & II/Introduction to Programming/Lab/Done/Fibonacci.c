#include<stdio.h>
int main()
{
    int a=0,b=1,c,n,i;
    printf("Enter limit of the series: ");
    scanf("%d",&n);
    printf("Numbers in Fibonacci Series are: ");
    for(i=0;i<n;++i)
    {
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
    }
    printf("\nnth term is %d",(b-a));
    return 0;
}
