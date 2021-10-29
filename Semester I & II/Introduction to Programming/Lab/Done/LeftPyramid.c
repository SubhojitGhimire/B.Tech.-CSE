#include<stdio.h>
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{	
		if(i<n/2)
		{
			if(n%2==0)
			for(j=0;j<(n/2)-1-i;++j)
				printf(" ");
			else
			for(j=0;j<(n/2)-i;++j)
				printf(" ");
			for(j=0;j<=i;++j)
				printf("*");
			printf("\n");
		}
		else
		{
			for(j=n/2;j<i;++j)
				printf(" ");
			for(j=n;j>i;--j)
				printf("*");
			printf("\n");
		}
	}
	return 0;
} 