#include<stdio.h>
void main()
{
    int mat1[3][3],mat2[3][3],i,j;
    for(i=0;i<3;++i)
        for(j=0;j<3;++j);
            scanf("%d",&mat1[i][j]);
    for(i=2;i>=0;--i)
    {
        for(j=0;j<3;++j)
        {
            mat2[j][i]=mat1[i][j];
        }
    }
    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
            printf("%d\t",mat2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
