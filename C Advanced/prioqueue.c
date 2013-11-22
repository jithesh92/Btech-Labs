#include<stdio.h> 
#define SIZE 15           
int f=0,r=-1;        
typedef struct PRQ 
{ 
 	int ele; 
 	int pr; 
}PriorityQ; 
PriorityQ PQ[SIZE]; 
PQinsert(int elem, int pre) 
{ 
	int i;       
	if( Qfull()) 
	printf("\n\n Overflow!!!!\n\n"); 
 	else 
 	{ 
		i=r; 
		r++; 
	  	while(PQ[i].pr >= pre && i >= 0) 
	  	{ 
		  	PQ[i+1]=PQ[i]; 
		   	i--; 
	  	} 
	  	PQ[i+1].ele=elem; 
	  	PQ[i+1].pr=pre; 
 	} 
} 
PriorityQ PQdelete() 
{                       
	PriorityQ p; 
	if(Qempty()){ printf("\n\nUnderflow!!!!\n\n"); 
 	p.ele=-1;p.pr=-1; 
 	return(p); } 
	else 
 	{ 
	  	p=PQ[f]; 
	  	f=f+1; 
	  	return(p); 
 	} 
} 
int Qfull() 
{                      
	if(r==SIZE-1) return 1; 
	return 0; 
} 
int Qempty() 
{                     
	if(f > r) return 1; 
	return 0; 
} 
display() 
{                   
	int i; 
	if(Qempty()) printf(" \n Empty Queue\n"); 
	else 
	{ 
		printf("Syntax: Element [Priority]\n"); 
		printf("Front->"); 
		for(i=f;i<=r;i++) 
		printf("%d[%d], ",PQ[i].ele,PQ[i].pr); 
		printf("<-Rear"); 
	} 
} 
main() 
{                           
	int opn; 
	PriorityQ p; 
	printf("\n Priority Queue (DSC order) \n"); 
	do 
	{ 
		printf("\n\n1-Insert\n2-Delete\n3-Display\n4-Exit\n"); 
		printf("Choice : "); 
		scanf("%d",&opn); 
		switch(opn) 
		{ 
			case 1: 
				printf("\nEnter the element and priority : "); 
				scanf("%d%d",&p.ele,&p.pr); 
				PQinsert(p.ele,p.pr); 
				break; 
			case 2: 
				p=PQdelete(); 
				if( p.ele != -1) 
				printf("\n\nDeleted Element is %d \n",p.ele); 
				break; 
			case 3:display(); break; 
			case 4:break; 
			default: printf("\n\nInvalid Option\n\n");break; 
		} 
	}while(opn != 4); 
}




