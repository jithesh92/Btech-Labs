#include<stdio.h> 
void main() 
{ 
	int a[10],front=0,rear=0,n,i; 
	do 
	{ 
		printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n"); 
		scanf("%d",&n); 
		switch(n) 
		{ 
			case 1: 
				if(rear<10) 
				{ 
					printf("Enter the number to be inserted : "); 
					scanf("%d",&a[rear]); 
					rear++; 
				} 
				else 
				printf("Queue Overlow\n"); 
				break; 
			case 2: 
				if(front==rear||front==10||rear==0) 
				{ 
					printf("Queue Underflow\n"); 
				}	 
				else 
				{ 
					printf("Deleted element is %d \n",a[front]); 
					front++; 
				} 
				break; 
			case 3: 
				if(front==rear||front==10||rear==0) 
				{ 
					printf("Queue is empty\n"); 
				}	 
				else 
				{ 
					printf("The elemets are\n"); 
					for(i=front;i<rear;i++) 
					printf("\n%d",a[i]); 
				} 
			case 4: 
				break; 
			default: 
				printf("Invalid option\n"); 
		} 
	} 
	while(n!=4);		 
}		

