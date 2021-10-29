#include <stdio.h>
int main()
{
    int i,j,a;
    for(i=0;i<7;++i)
    {
        if(i<7/2)
            {
                for(j=0,a=i+1;j<2*i+1;++j)
                    if(j<=(2*i+1)/2)
                    {
                        printf("%d",a++);
                        if(j==(2*i+1)/2)
                            --a;
                    }
                    else
                        printf("%d",--a);
            }
        else
            for(j=0,a=7-i;j<(7-i)*2-1;++j)
            {
                if(j<=((7-i)*2-1)/2)
                {
                    printf("%d",a++);
                    if(j==((7-i)*2-1)/2)
                        --a;
                }
                else
                    printf("%d",--a);
            }
        printf("\n");
    }
    return 0;
}
