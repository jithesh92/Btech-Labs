
#include<stdio.h> 

typedef struct node 
{ 
	int data; 
	struct node *link; 
}n; 
n *top=NULL; 

main() 
{ 
	int a,item; 
	n *temp,*save; 
	do 
	{ 
		printf("\n1-Push\n2-Pop\n3-display\n4-Is Empty\n5-Make Empty\n6-Exit\n"); 
		scanf("%d",&a); 
		switch(a) 
		{ 
			case 1: 
				printf("Enter the item\n"); 
				scanf("%d",&item); 
				temp=(n*)malloc(sizeof(n)); 
				temp->data=item; 
				temp->link=top; 
				top=temp; 
				break; 
			case 2: 
				if(top==NULL) 
				printf("Stack underflow\n"); 
				else 
				{ 
				temp=top; 
				printf("The element deleted = %d\n",temp->data); 
				free(temp); 
				top=top->link; 
				} 
				break; 
			










			case 3: 
				if(top==NULL) 
				printf("Stack is empty\n"); 
				else 
				{ 
				save=top; 
				printf("The elements of the stack are :"); 
				while(save!=NULL) 
				{ 
				printf("%d\t",save->data); 
				save=save->link; 
				} 
				} 
				break; 
			case 4: 
				if(top==NULL) 
				printf("Stack is empty\n"); 
				else 
				printf("Stack is not empty\n"); 
				break; 
			case 5: 
				while(top!=NULL) 
				{ 
				temp=top; 
				top=top->link; 
				free(temp); 
				} 
				top=NULL; 
				printf("Stack is empty now\n"); 
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


