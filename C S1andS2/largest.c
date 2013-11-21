#include<stdio.h>
main()
{
        int a,b,c;
        printf("\nEnter 3 no.s");
        scanf("%d%d%d",&a,&b,&c);
        if(a>b)
        { 
	        if(a>c)
                {
                        printf("%d is largest",a);
                }
                else
                {
                        printf("%d is largest",c);
                }
        }
        else if(b>c)
        {
                printf("%d is largest",b);
        }
        else
        {
                printf("%d is largest",c);
        }
}
