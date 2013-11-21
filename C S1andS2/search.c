#include<stdio.h>
main()
{
        int a[15],x,n,i,flag;
        printf("\n enter the no. of numbers");
        scanf("%d",&n);
        printf("\n enter the number");
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        printf("\n enter the number to be searched:");
        scanf("%d",&x);
        for(i=0;i<n;i++)
        {
                if (a[i]==x)
                {
                        flag=1;
                        break;
                }
        }
        if(flag==1)
                printf("%d found",x);
        else
                printf("%d not found",x);
}