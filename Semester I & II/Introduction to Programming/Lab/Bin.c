#include<stdio.h>
#include<math.h>
int main()
{
    long int num,i=1LL,mod;
    scanf("%ld",&num);
    while(num!=0)
    {
            mod=num%10;
            i=i|(1<<mod);
            num=num/10;
    }
    if(i==pow(2,10)-1)
            printf("Contains all digits");
    else
            printf("Does not contain all digits");
    return 0;
}
