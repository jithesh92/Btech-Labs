#include<stdio.h>
main()
{       int i,j,k,p,q,m,n,a[20][20],b[20][20],c[20][20];
        printf("\nenter no. of rows & columns of 1st matrix\n");
        scanf("%d%d",&m,&n);
        printf("\nenter no. of rows & columns of 2nd matrix\n");
        scanf("%d%d",&p,&q);
        if(n==p)
        {
                printf("enter the elements of matrix 1\n");
                for(i=0;i<m;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                scanf("%d",&a[i][j]);
                        }
                }
                printf("enter the elements of matrix 2\n");
                for(i=0;i<p;i++)
                {
                        for(j=0;j<q;j++)
                        {
                                scanf("%d",&b[i][j]);
                        }
                }
                printf("The product of matrix multiplication is\n");
                for(i=0;i<m;i++)
                {
                        for(j=0;j<q;j++)
                        {
                                c[i][j]=0;
                                for(k=0;k<n;k++)
                                {
                                        c[i][j]+=a[i][k]*b[k][j];
                                }
                        }
                }
                for(i=0;i<m;i++)
                {
                        for(j=0;j<q;j++)
                        {
                        printf("\n");
                }
        }
        else
                printf("cannot perform multiplication\n");
}