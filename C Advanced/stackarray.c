#include<stdio.h> 
void main() 
{ 
	int a[10],top=0,n,i; 
	do 
	{ 
		printf("\n1-Push\n2-Pop\n3-display\n4-Exit\n"); 
		scanf("%d",&n); 
		switch(n) 
		{ 
			case 1: 
				if(top<10) 
				{ 
					printf("Enter the number to be pushed : "); 
					scanf("%d",&a[top]); 
					top++; 
				} 
				else 
				printf("Stack overflow\n"); 
				break; 
			case 2: 
				top=top-1; 
				if(top==-1) 
				{ 
					printf("Stack underflow\n"); 
					top=0; 
				}	 
				else 
				printf("Element is %d \n",a[top]); 
				break; 
			case 3: 
				top=top-1; 
				if(top==-1) 
				{ 
				printf("Stack is empty\n"); 
				top=0; 
				} 
				else 
				{ 
				printf("The stack is\n");
				for(i=top;i>-1;i--) 
				printf("\n%d",a[i]); 
				++top; 
				} 
				break; 
		} 
	} 
	while(n!=4);		 
}	
