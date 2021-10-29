#include<stdio.h>
#include<string.h>

int main()
{
	int i,len=0;
	char str[30],palin[30];
	printf("Enter a string.\n");
	gets(str);
	len=strlen(str)-1;
	for(i=0;str[i]!='\0';++i)
		palin[len-i]=str[i];
	palin[i]='\0';
	printf("Reverse of your input is: %s\nHence, ",palin);
	if(strcmpi(str,palin)==0)
		printf("Palindrome");
	else
		printf("Not Palindrome");
	return 0;
}
