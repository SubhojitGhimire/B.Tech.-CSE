#include<stdio.h>
int main()
{
	int num,rev=0,mod,temp;
	printf("Enter a Number: ");
	scanf("%d",&num);
	temp=num;
	for(;temp!=0;)
	{
		mod=temp%10;
		rev=rev*10+mod;
		temp=temp/10;
	}
	printf("Reverse of %d is %d",num,rev);
	return 0;
}