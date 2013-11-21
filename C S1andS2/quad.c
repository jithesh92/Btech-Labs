#include<stdio.h>
#include<math.h>
main()
{
        int a,b,c,d;
        float x,x1,x2;
        printf("Enter the three numbers:");
        scanf("%d%d%d",&a,&b,&c);
        d=(b*b-4*a*c);
        if(d==0)
        {

                printf("the eqution has equal roots");
                x=-b/2*a;
                printf("root = %f",x);
        }
        else if(d>0)
        {
                printf("it has 2 roots\n");
                x1=(-b+sqrt(d))/2*a;
                x2=(-b-sqrt(d))/2*a;
                printf("root1=%f",x1);
                printf("root2=%f",x2);
        }
        else
        {
                printf("the equation has no real roots");
        }
}