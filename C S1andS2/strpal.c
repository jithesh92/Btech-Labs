#include<stdio.h>
#include<string.h>
main()
{
        char str[20];
        int i,l,j;
        int flag=0;
        printf("\n enter the string:");
        gets(str);
        l=strlen(str);
        for(i=0,j=l-1;i<l/2;i++,j--)
        {
                if(str[i]!=str[j])
                {
                        flag=1;
                        break;
                }
        }
        if(flag==0)
                printf("\n %s is palindrom",str);
        else
                printf("\n %s is not palindrom",str);
}