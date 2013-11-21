#include<stdio.h>
int fact(int m);
main()
{
        int n,f;
        printf("\nenter the number");
        scanf("%d",&n);
        f=fact(n);
        printf("\nfactorial of %d=%d",n,f);
}
int fact(int m)
{
        if (m<=1)
                return 1;
        else
                return(m*fact(m-1));
}