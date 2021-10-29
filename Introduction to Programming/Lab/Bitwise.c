#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    if(a&1)
        printf("Odd");
    else
        printf("Even");
    return 0;
}
