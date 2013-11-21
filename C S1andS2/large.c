#include<stdio.h>
main()
{int a[15],n,i,lar;
        printf("\n enter the no. of numbers");
        scanf("%d",&n);
        printf("\n enter the no.s");

        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
                lar=a[0];
        }
        for(i=0;i<n;i++)
        {
                if( a[i]>lar )
                        lar=a[i];
        }
        printf("%d is largest",lar);

}