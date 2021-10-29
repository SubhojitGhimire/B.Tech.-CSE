#include<stdio.h>
int main()
{
    int num,val;
    printf("Enter a number: ");
    scanf("%d",&num);
    val=num&1;
    val==1?printf("Odd"):printf("Even");
    return 0;
}
