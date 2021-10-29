#include<stdio.h>
int main()
{
    int mat[4][4],i,j,i1;
    for(i=0;i<4;++i)
        for(j=0;j<4;++j)
            scanf("%d",&mat[i][j]);
    for(i=0;i<4;++i)
    {
        i1=3;
        for(j=0;j<4;++j)
        {
            if(i%2==0)
            {
                printf("%d ",mat[i][j]);
            }
            else
            {
                printf("%d ",mat[i][i1]);
                --i1;
            }
        }
    }
}
