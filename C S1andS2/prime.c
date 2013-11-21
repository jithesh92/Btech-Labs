#include<stdio.h>
main()
{
        int n,i,flag=0;
        printf("\nEnter the number:");
        scanf("%d",&n);
        if(n==1)
        {printf("\nNumber is not prime");
        }
        else
        {for(i=2;i<=(n/2);i++)
                {
                        if(n%i==0)
                        {flag=1;
                                break;
                        }
                }
                if(flag==1)
                        printf("\nNumber is not prime\n");
                else
                        printf("\nNumber is prime\n");
        }
}