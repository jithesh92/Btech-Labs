#include<stdio.h>
main()
{int n,d,sum=0;
printf("enter the number");
scanf("%d",&n);
while(n>0)
{d=n%10;
sum=sum+d;
n=n/10;
}
n=0;
printf("sum of digits=%d",sum);
}