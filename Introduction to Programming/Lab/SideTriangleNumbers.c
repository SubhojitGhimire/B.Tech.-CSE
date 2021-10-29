#include <stdio.h>
int main()
{
    int i,j;
    for(i=0;i<9;++i)
    {
        if(i<9/2)
            for(j=0;j<2*i+1;++j)
                printf("*");
        else
            for(j=0;j<(9-i)*2-1;++j)
                printf("*");
        printf("\n");
    }
    return 0;
}
