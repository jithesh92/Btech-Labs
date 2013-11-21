#include<stdio.h>
int n;
main()
{
        void perfect(int);
        printf("enter no.");
        scanf("%d",&n);
        perfect(n);
}
void perfect(int a)
{
        int i,s=0;
        for(i=1;i<a;i++)
        {
                if(a%i==0)
                        s=s+i;
        }
        if(s==a)
                printf("it is perfect");
        else
                printf("it is not perfect");
}