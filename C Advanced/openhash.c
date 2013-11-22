
#include <stdio.h> 
struct node 
{ 
	int data; 
	struct node *next; 
}*a[10]; 
void insert(); 
void display(); 
void delete(); 
void search(); 
typedef struct node n; 
int key; 
main() 
{ 
	int i,ch; 
	do 
	{ 
		printf("\n1-Enter the data\n2-Display\n3-search\n4-delete\n5-exit\n"); 
		scanf("%d",&ch); 
		switch(ch) 
		{ 
			case 1: 
				insert(); 
				break; 
			case 2: 
				display(); 
				break; 
			case 3: 
				search(); 
				break;	 
			case 4:	 
				delete(); 
				break; 
			case 5: 
				break; 
			default: 
				printf("Invalid Option\n"); 
		} 
	} 
	while(ch!=5); 
} 



void insert() 
{ 
	n *temp,*nw; 
	int item; 
	nw=(n*)malloc(sizeof(n)); 
	printf("Enter the num :"); 
	scanf("%d",&item); 
	key=item%10; 
	nw->data=item; 
	nw->next=NULL; 
	temp=a[key]; 
	if(a[key]==NULL) 
	a[key]=nw; 
	else 
	{ 
		while(temp->next!=NULL) 
		temp=temp->next; 
		temp->next=nw; 
	} 
} 
void search() 
{ 
	n *temp; 
	int item,flag=0; 
	printf("\nEnter the number you want to search:"); 
	scanf("%d",&item); 
	key=item%10; 
	temp=a[key]; 
	while(a[key]!=NULL) 
	{ 
		if(temp->data==item) 
		{ 
		printf("Search Successful\n"); 
		flag=1; 
		break; 
		} 
	temp=temp->next; 
	} 
	if(flag==0) 
	printf("Search Not Successful\n"); 
} 






void display() 
{ 
	n *temp; 
	int i; 
	for(i=0;i<10;i++) 
	{	 
		temp=a[i]; 
		printf("\nMod=%d-",i); 
		while(temp!=NULL) 
		{ 
			printf("%d->",temp->data); 
			temp=temp->next; 
		} 
		printf("NULL"); 
	} 
} 
void delete() 
{ 
	int item; 
	n *temp,*old; 
	printf("\nEnter the number you want to delete:"); 
	scanf("%d",&item); 
	key=item%10; 
	temp=a[key]; 
	while(temp!=NULL) 
	{ 
		if(temp->data==item) 
		{ 
			if(temp==a[key]) 
			{ 
				a[key]=temp->next; 
				free(temp); 
				return; 
			} 
			else 
			{ 
				old->next=temp->next; 
				free(temp); 
				return; 
			} 
		} 
		else 
		{ 
			old=temp; 
			temp=temp->next; 
		} 
	} 
	printf("\n%d is not found",item); 
} 


