#include<stdio.h>
#include<string.h>
int main()
{
    int num,i=0,j;
    char str['!'],stemp;
    scanf("%d",&num);
    int temp=num,mod;
    while(temp!=0)
    {
        mod=temp%10;
        str[i++]='0'+mod;
        temp=temp/10;
    }
    str[i]='\0';
    for(i=0;str[i]!='\0';++i)
        printf("%c",str[i]);
    printf("\n");
    for(i=0,j=strlen(str);str[i]!='\0';++i,--j)
    {
        if(i<j/2)
        {
            stemp=str[i];
            str[i]=str[j-1];
            str[j-1]=stemp;
        }
        printf("%c",str[i]);
    }
    return 0;
}
