#include<stdio.h>
#include<string.h>
int main()
{
	char str1[30],str2[30],str[60];
	int len=0,i,j;
	printf("Enter string 1: ");
		gets(str1);
	printf("Enter string 2: ");
		gets(str2);
	len=strlen(str1);
	strcpy(str,str1);
	str[len]=' ';
	for(i=len+1,j=0;str[i-1]!='\0';++i,++j)
		str[i]=str2[j];
	printf("New string is: %s",str);
	return 0;
}