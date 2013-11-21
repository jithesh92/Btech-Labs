#include<stdio.h>
int factr(int x);
main(int argc,char *argv[])
{
        int n,f;
        n=atoi(argv[1]);
        f=factr(n);
        printf("\nfactorial of %d is %d\n",n,f);
}
int factr(int x)
{
        if(x<=1)
                return 1;
        else
                return x*factr(x-1);
}