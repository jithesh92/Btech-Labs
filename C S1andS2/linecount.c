#include<stdio.h>
#include<ctype.h>
main()
{
        char s;
        int l=1;
        int w=1;
        int c=0;
        printf("\n enter the passage:\n");
        while((s=getchar())!=EOF)
        {
                if(s=='\n')
                        l++;
                if((s==' ')||(s=='\t')||(s=='\n'))
                        w++;
                if(isalpha(s))
                        c++;
}
                printf("\nno. of lines:%d\nno. of words:%d\nno. of characters:%d
\n",l,w,c);

}