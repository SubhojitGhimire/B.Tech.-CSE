#include<stdio.h>
int main()
{
	int arr['!'],temp['!'],i,j,freq,size;
	printf("Enter values into your array... Input 0 to terminate the array...\n");
	scanf("%d",&arr[0]);
	temp[0]=arr[0];
	for(i=1;arr[i-1]!=0;++i)
	{
		scanf("%d",&arr[i]);
		temp[i]=arr[i];
	}
	size=i;
	for(i=0;i<size;++i)
	{
		freq=0;
		if(temp[i]!=0)
		{
			for(j=i;j<size;++j)
			{
				if(arr[i]==temp[j])
				{
					++freq;
					temp[j]=0;
				}
			}
			printf("Frequency of %d= %d\n",arr[i],freq);
		}
	}
	return 0;
}