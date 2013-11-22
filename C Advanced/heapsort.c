
#include<stdio.h>
int arr[20],n;
display()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n %d \t",arr[i]);
		printf("\n ");
	}
}
createheap()
{
	int i;
	for(i=0;i<n;i++)
	insert(arr[i],i);
}
insert(int num,int loc)
{
	int par;
	while(loc>0)
	{
		par=(loc-1)/2;
			if(num<=arr[par])
			{
				arr[loc]=num;
				return;
			}
		arr[loc]=arr[par];
		loc=par;
	}
	arr[0]=num;
}
heapsort()
{
	int last;
	for(last=n-1;last>0;last--)
	{
		delroot(last);
	}
}
delroot(int last)
{
	int left,right,i,temp;
	i=0;
	temp=arr[i];
	arr[i]=arr[last];
	arr[last]=temp;
	left=2*i+1;
	right=2*i+2;
	while(right<last)
	{
		if(arr[i]>=arr[left]&&arr[i]>=arr[right])
		return;
		if(arr[right]<=arr[left])
		{
			temp=arr[i];
			arr[i]=arr[left];
			arr[left]=temp;
			i=left;
		}
		else
		{
			temp=arr[i];
			arr[i]=arr[right];
			arr[right]=temp;
			i=right;
		}
		left=2*i+1;
		right=2*i+2;
	}
	if(left==last-1&&arr[i]<arr[left])
	{
		temp=arr[i];
		arr[i]=arr[left];
		arr[left]=temp;
	}
}
main()
{
	int i;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\n entered list is : \n");
	display();
	createheap();
	printf("\n heap is: \n");
	display();
	heapsort();
	printf("\n sorted list is: \n");
	display();
}                       







