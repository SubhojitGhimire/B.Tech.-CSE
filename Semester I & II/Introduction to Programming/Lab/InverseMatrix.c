#include<stdio.h>
#include<windows.h>
COORD coord={0,0};
void gotoxy(int x,int y)
 {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
int main()
{
	int mat[3][3],temp[3][6],adj[3][3],det=0,i,j,a,b,d[3],x=0,y=1;
	float inv[3][3];
	printf("Enter elements into matrix\n");
	for(i=0;i<3;++i)
    {
            x=0;
		    for(j=0;j<3;++j)
		{

            gotoxy(x,y);
			scanf("%d",&mat[i][j]);
			temp[i][j]=temp[i][j+3]=mat[i][j];
			x+=3;
		}
		++y;
    }
    printf("\n");
    for(i=0;i<3;++i)
    {
        for(j=0;j<6;++j)
            printf("%d\t",temp[i][j]);
        printf("\n");
    }
    printf("\n");

	for(i=0;i<1;++i)
	{
		a=i;
		for(j=0;j<3;++j)
		{
			b=j;
			det+=(mat[i][j]*(temp[a+1][b+1]*temp[a+2][b+2]-temp[a+1][b+2]*temp[a+2][b+1]));
		}
	}
    //Alternatively, the following 4 lines can be used for calculating determinant
	/*
	d[0]=mat[0][0]*(mat[1][1]*mat[2][2]-mat[1][2]*mat[2][1]);
	d[1]=mat[0][1]*(mat[1][0]*mat[2][2]-mat[1][2]*mat[2][0]);
	d[2]=mat[0][2]*(mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0]);
	det=d[0]-d[1]+d[2];
    */

	printf("Determinant of matrix is: %d\n",det);

if(det!=0)
{
	for(i=0;i<3;++i)
	{
		a=i;
		for(j=0;j<3;++j)
		{
			b=j;
			if(i==0)
				adj[i][j]=(temp[a+1][b+1]*temp[a+2][b+2]-temp[a+1][b+2]*temp[a+2][b+1]);
			else if(i==1)
				adj[i][j]=(-1)*(temp[a-1][b+1]*temp[a+1][b+2]-temp[a-1][b+2]*temp[a+1][b+1]);
            else if(i==2)
                adj[i][j]=(temp[a-2][b+1]*temp[a-1][b+2]-temp[a-2][b+2]*temp[a-1][b+1]);
        }
	}
	printf("Adjoint is: \n");
	for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
            if(i!=j&&i<j)
            {
                a=adj[i][j];
                adj[i][j]=adj[j][i];
                adj[j][i]=a;
            }
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
    printf("Inverse is \n");
    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
            inv[i][j]=adj[i][j]/(det*1.0);
            printf("%0.3f\t",inv[i][j]);
        }
        printf("\n");
    }
}
    return 0;
}
