#include<stdio.h>
int fib(int m);
main()
{
        int n,i,x;
        printf("\nenter the range:");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                x=fib(i);

                printf("%d\t",x);
        }
}
int fib(int m)
{
        if(m<=1)
                return m;
        else
                return(fib(m-1)+fib(m-2));
}