#include<stdio.h>
#include<string.h>
int main()
{
    char str[]="Hello ! I am a first year guy !";
    int len=strlen(str),i,j;
    for(i=len-1;i>=0;--i)
    {
        if(str[i]==' ')
        {
            for(j=i+1;str[j]!='\0'||str[j]!=' ';++j)
                printf("%c",str[j]);
            printf(" ");
        }
    }
    return 0;
}
