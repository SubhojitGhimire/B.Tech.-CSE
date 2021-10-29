#include<stdio.h>
int main()
{
    int n,r,i,npr,nfact=1,nrfact=1;
    printf("Enter total number of objects(n): ");
    scanf("%d",&n);
    printf("Enter number of objects taken at a time(r): ");
    scanf("%d",&r);
    for(i=n;i>0;--i)
        nfact=nfact*i;
    for(i=(n-r);i>0;--i)
        nrfact=nrfact*i;
    npr=nfact/nrfact;
    printf("%dP%d is %d",n,r,npr);
    return 0;
}
