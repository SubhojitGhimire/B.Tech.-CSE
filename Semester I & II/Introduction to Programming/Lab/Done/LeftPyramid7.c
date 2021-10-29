#include<stdio.h>
int main()
{
	int i,j;
	for(i=0;i<7;++i)
	{	
		if(i<7/2)
		{
			for(j=0;j<(7/2)-i;++j)
				printf(" ");
			for(j=0;j<=i;++j)
				printf("*");
			printf("\n");
		}
		else
		{
			for(j=7/2;j<i;++j)
				printf(" ");
			for(j=7;j>i;--j)
				printf("*");
			printf("\n");
		}
	}
	return 0;
} 