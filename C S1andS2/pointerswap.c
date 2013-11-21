#include<stdio.h>
void swap(int *a,int *b);
main()
{
int x,y;
printf("\n enter the no.:");
scanf("%d%d",&x,&y);
printf("Before swapping:x=%d,y=%d",x,y);
swap(&x,&y);
printf("\n After swapping:x=%d,y=%d,",x,y);
}
void swap(int *a,int *b)
{
int t;
t=*a;
*a=*b;
*b=t;
}