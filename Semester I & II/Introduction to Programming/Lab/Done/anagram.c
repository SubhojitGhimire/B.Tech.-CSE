#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char str1[30],str2[30];
	int i,j,check=0,len1,len2,cnt1=0,cnt2=0;
	printf("Enter String 1: ");
	gets(str1);
	printf("Enter String 2: ");
	gets(str2);
	len1=strlen(str1);
	len2=strlen(str2);
	if(len1==len2)
	{
		for(i=0;i<len1;++i)
		{
			for(j=0;j<len1;++j)
				if(tolower(str1[i])==tolower(str1[j]))
					++cnt1;
			for(j=0;j<len1;++j)
				if(tolower(str1[i])==tolower(str2[j]))
					++cnt2;
			if(cnt1==cnt2)
				++check;
			else
				break;
		}
		if(check==len1)
			printf("Strings are anagrams");
		else
			printf("Strings are not anagrams");
	}
	else
	{
		printf("Strings are not anagrams");
	}
	return 0;
}