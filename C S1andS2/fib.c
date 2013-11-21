
#include<stdio.h>
main()
{int i,a=0,b=1,c,n;
        printf("Enter the limit:");
        scanf("%d",&n);
        printf("%d\t%d",a,b);
        for(i=3;i<=n;i++)
        {       c=a+b;
                a=b;
                b=c;
                printf("\t%d",c);
        }
}
