#include<stdio.h>
#include<string.h>
main()
{
        char str[20];
        int i,l;
        printf("\n enter the string:");
        gets(str);
        l=strlen(str);
        printf("\n Reversed string:");
        for(i=l;i>=0;i--)
                putchar(str[i]);
}