
#include<stdio.h>
main()
{int n,d,m,sum=0;
printf("enter the number:");
scanf("%d",&n);
m=n;
do
{
d=n%10;
sum=sum+(d*d*d);
n=n/10;
}while(n>0);
if(sum==m)
printf("the number is armstrong");
else
printf("the number is not armstrong");
}
