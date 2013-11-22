#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<math.h> 
#include<ctype.h> 
char stack[200],inf[200],post[200]; 
int top=-1; 
struct node 
{ 
	char c; 
	struct node *rlink; 
	struct node *llink; 
} 
*stc[20],*root; 
postfix() 
{ 
	char c; 
	int i=0,k=0,j,n,a; 
	n=strlen(inf); 
	inf[n+1]=inf[n]; 
	inf[n]=')'; 
	n++; 
	top++; 
	stack[top]='('; 
	for(i=0;i<n;i++) 
	{ 
		c=inf[i]; 
		a=inf[i]; 
		if(a>64&&a<91||a>96&&a<123||a>47&&a<58) 
		{ 
		post[k]=c; 
		k++; 
		} 
		else if(c=='^') 
		{ 
			while(top>=0&&stack[top]=='^') 
			{ 
				post[k]=stack[top]; 
				k++; 
			} 
			top++; 
			stack[top]=c; 
		} 
		else if(c=='*'||c=='/') 
		{ 
			while(top>0&&stack[top]=='^'||stack[top]=='*'||stack[top]=='/') 
			{ 
				post[k]=stack[top]; 
				k++; 
				top--; 
			} 
			top++; 
			stack[top]=c; 
		} 
		else if(c=='+'||c=='-') 
		{ 

			while(top>0&&stack[top]=='*'||stack[top]=='^'||stack[top]=='/'||stack[top]=='+'||stack[top]=='-') 
			{ 
				post[k]=stack[top]; 
				k++; 
				top--; 
			} 
			top++; 
			stack[top]=c; 
		} 
		else if(c==')') 
		{ 
			while(top>=0&&stack[top]!='(') 
			{ 
				post[k]=stack[top]; 
				k++; 
				top--; 
			} 
			top--; 
		} 
		else if(c=='(') 
		{ 
			top++; 
			stack[top]='('; 
		} 
		else 
		printf("invalid expression"); 
	} 
} 
int exptree() 
{ 
	char c; 
	int i=0; 
	struct node *newnode,*temp; 
	while(post[i]!='\0') 
	{ 
		c=post[i]; 
		newnode=(struct node*)malloc(sizeof(struct node)); 
		newnode->c=c; 
		if(isdigit(c)||isalpha(c)) 
		{ 
			newnode->rlink=newnode->llink=NULL; 
			top++; 
		} 
		else 
		{ 
			temp=stc[top]; 
			top--; 
			newnode->rlink=temp; 
			temp=stc[top]; 
			newnode->llink=temp; 
		} 
		stc[top]=newnode; 
		i++; 
	} 
	return stc[top]; 
} 
float eval(struct node *ptr) 
{ 
	float a,b,c,i; 
	if(ptr!=NULL) 
	{ 
		a=eval(ptr->llink); 
		b=eval(ptr->rlink); 
		switch(ptr->c) 
		{ 
			case '+' : c=a+b; 
			break; 
			case '*' : c=a*b; 
			break; 
			case '-' : c=a-b; 
			break; 
			case '/' : c=a/b; 
			break; 
			case '^' : 
					c=1; 
					for(i=0;i<b;i++) 
					c=c*a; 
					break; 
			default : 
					if(isdigit(ptr->c)) 
					c=ptr->c-48; 
					else if(isalpha(ptr->c)) 
					{ 
						printf("Enter the value for %c : ",ptr->c); 
						scanf("%f",&c); 
					}	 
						 
		} 
	return c; 
} 
return 1; 
} 
void main() 
{ 
	printf("enter infix expression \n"); 
	scanf("%s",&inf); 
	postfix(); 
	if(top==-1) 
	{ 
		printf("\nThe Postfix expression is : %s\n",post); 
		root=exptree(); 
		printf("\nResult=%f\n",eval(root)); 
	} 
	else 
	printf("Invalid Exprssion\n"); 
} 

