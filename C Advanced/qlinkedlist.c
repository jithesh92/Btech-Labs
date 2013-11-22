
#include<stdio.h> 
typedef struct node 
{ 
	int data; 
	struct node *link; 
}n; 
n *front=NULL; 
n *rear=NULL; 
main() 
{ 
	n *new,*ptr; 
	int a,item; 
	do 
	{ 
		printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Is Empty\n5-Make Empty\n6-Exit\n"); 
		scanf("%d",&a); 
		switch(a) 
		{ 
			case 1: 
				printf("Enter the item "); 
				scanf("%d",&item); 
				new=(n*)malloc(sizeof(n)); 
				new->data=item; 
				new->link=NULL; 
				if(front==NULL&&rear==NULL) 
				{ 
					front=new; 
					rear=new; 
				} 
				else 
				{ 
					rear->link=new; 
					rear=rear->link; 
				} 
				break; 
			case 2: 
				if(front==NULL) 
				printf("Queue Underflow\n"); 
				else 
				{ 
					printf("The deleted item is %d",front->data); 
					ptr=front; 
					front=front->link; 
					free(ptr); 
				}	 
				break; 
			case 3: 
				if(front==NULL) 
				printf("Queue is empty\n"); 
				else 
				{ 
					ptr=front; 
					printf("The elements are \n"); 
					while(ptr->link!=NULL) 
					{ 
					printf("\n%d",ptr->data); 
					ptr=ptr->link; 
					} 
					printf("\n%d",ptr->data); 
				} 
				break; 
			case 4: 
				if(front==NULL) 
				printf("Queue is empty\n"); 
				else 
				printf("Queue is not empty\n"); 
				break; 
			case 5: 
				while(front==NULL) 
				{ 
				ptr=front; 
				front=front->link; 
				free(ptr); 
				} 
				front=NULL; 
				rear=NULL; 
				printf("Queue is empty now\n"); 
				break; 
			case 6: 
				break; 
			default: 
				printf("Invalid choice\n"); 
				break; 
			 
		} 
	} 
	while(a!=6); 
}
