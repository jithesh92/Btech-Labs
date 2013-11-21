#include<stdio.h>
main()
{
        int y;
        printf("enter the year");
        scanf("%d",&y);
        if(y%400==0)
        {
                printf("it is a leap year");
        }
        else if((y%100!=0)&&(y%4==0))
              {
                   printf("it is a leap year");

              }
              else
              {
                printf("it is not a leap year");
              }
}
