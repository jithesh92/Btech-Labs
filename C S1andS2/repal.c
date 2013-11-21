#include<stdio.h>
int palin(int m);
int rev=0;
main()
{
        int n,x,p;
        printf("\nenter the number:");
        scanf("%d",&n);
        x=n;
        p=palin(n);
        if(x==p)
                printf("%d is a palindrom",x);
        else
                printf("%d is not a palindrom",x);
}
palin(int m)
{
        int d;
        if (m>0)
        {
                d=m%10;
                rev = rev*10+d;
                m=m/10;
                palin(m);
        }
        return rev;
}
