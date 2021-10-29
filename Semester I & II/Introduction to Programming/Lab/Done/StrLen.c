#include<stdio.h>
int main()
{
	char str[30];
	int len;
	printf("Enter String: ");
	gets(str);
	for(len=0;str[len]!='\0';++len);
	printf("Lenght of the string is: %d",len);
	return 0;
}
	