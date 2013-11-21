#include<stdio.h>
main()
{
        int a[10],n,i,j,temp;
        printf("\n enter the no. of numbers");
        scanf("%d",&n);
        printf("\n enter the numbers");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        if (a[i]>a[j])
                        {
                                temp=a[i];
                                a[i]=a[j];
                                a[j]=temp;
                        }
                }
        }
        printf("sorted numbers");
        for(i=0;i<n;i++)
                printf("%d\t",a[i]);
}