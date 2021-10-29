#include<stdio.h>
int main()
{
	int arr['!'],size,i,temp;
	printf("Enter Size of your array: ");
	scanf("%d",&size);
	printf("Enter values to your array\n");
	for(i=0;i<size;++i)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<size/2;++i)
	{
		temp=arr[i];
		arr[i]=arr[size-i-1];
		arr[size-i-1]=temp;
	}
	printf("Reversed Array is: ");
	for(i=0;i<size;++i)
		printf("%d ",arr[i]);
	return 0;	
}