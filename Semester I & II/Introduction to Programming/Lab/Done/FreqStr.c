#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char str[30],temp[30],freq,i,j;
    printf("Enter a string: ");
    gets(str);
    strcpy(temp,str);
    for(i=0;str[i]!='\0';++i)
    {
        if(isalpha(temp[i]))
        {
            freq=0;
            for(j=i;temp[j]!='\0';++j)
            {
                if(str[i]==temp[j])
                {
                    ++freq;
                    temp[j]='0';
                }
            }
            printf("Frequency of %c is %d\n",str[i],freq);
        }
    }
    return 0;
}
