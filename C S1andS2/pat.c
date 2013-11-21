/*
Aim: Write a C program to display the following pattern
1
1 	2
1 	2 	3
1	2	3	4
*/

#include<stdio.h>
main()
{
        int i,j,n;
        printf("\nEnter the number of rows:");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=i;j++)
                {printf("%d\t",j);
                }
                printf("\n");
        }
}