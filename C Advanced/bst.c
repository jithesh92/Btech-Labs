#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	int data; 
	struct node *lchild; 
	struct node *rchild; 
}; 
struct node *root=NULL; 
find(int item,struct node **par,struct node **loc) 
{ 
	struct node *ptr,*ptrsave; 
	if(root==NULL) 
	{ 
		*loc=NULL; 
		*par=NULL; 
		return; 
	} 
	if(item==root->data) 
	{ 
		*loc=root; 
		*par=NULL; 
		return; 
	} 
	if(item<root->data) 
	ptr=root->lchild; 
	else 
	ptr=root->rchild; 
	ptrsave=root; 
	while(ptr!=NULL) 
	{ 
		if(item==ptr->data) 
		{ 
			*loc=ptr; 
			*par=ptrsave; 
			return; 
		} 
		ptrsave=ptr; 
		if(item<ptr->data) 
		ptr=ptr->lchild; 
		else 
		ptr=ptr->rchild; 
	} 
	*loc=NULL; 
	*par=ptrsave; 
} 
insert(int item) 
{ 
	struct node *temp,*parent,*location; 
	find(item,&parent,&location); 
	if(location!=NULL) 
	{ 
		printf("\nitem already present\n"); 
		return; 
	} 
	temp=(struct node*)malloc(sizeof(struct node)); 
	temp->data=item; 
	temp->lchild=NULL; 
	temp->rchild=NULL; 
	if(parent==NULL) 
	root=temp; 
	else 
	{ 
		if(item<parent->data) 
		parent->lchild=temp; 
		else 
		parent->rchild=temp; 
	} 
	printf("\nitem inserted\n"); 
} 
case_a(struct node *par,struct node *loc) 
{ 
	if(par==NULL) 
	root=NULL; 
	else 
	{ 
		if(loc==par->lchild) 
		par->lchild=NULL; 
		else 
		par->rchild=NULL; 
	} 
} 
case_b(struct node *par,struct node *loc) 
{ 
	struct node *child; 
	if(loc->lchild!=NULL) 
	child=loc->lchild; 
	else 
	child=loc->rchild; 
	if(par==NULL) 
	root=child; 
	else 
	{ 
		if(loc==par->lchild) 
		par->lchild=child; 
		else 
		par->rchild=child; 
	} 
} 
case_c(struct node *par,struct node *loc) 
{ 
	struct node *parsuc,*suc; 
	parsuc=loc; 
	suc=loc->rchild; 
	while(suc->lchild!=NULL) 
	{ 
		parsuc=suc; 
		suc=suc->lchild; 
	} 
	if((suc->lchild==NULL)&&(suc->rchild==NULL)) 
	case_a(parsuc,suc); 
	else 
	case_b(parsuc,suc); 
	if(par==NULL) 
	root=suc; 
	else 
	{ 
		if(loc==par->lchild) 
		par->lchild=suc; 
		else 
		par->rchild=suc; 
	} 
	suc->lchild=loc->lchild; 
	suc->rchild=loc->rchild; 
} 
del(int item) 
{ 
	struct node *parent,*location; 
	if(root==NULL) 
	{ 
		printf("\ntree empty\n"); 
		return; 
	} 
	find(item,&parent,&location); 
	if(location==NULL) 
	{ 
		printf("\nitem is not present in tree\n"); 
		return; 
	} 
	if((location->lchild==NULL)&&(location->rchild==NULL)) 
	case_a(parent,location); 
	if((location->lchild!=NULL)&&(location->rchild==NULL)) 
	case_b(parent,location); 
	if((location->lchild==NULL)&&(location->rchild!=NULL)) 
	case_b(parent,location); 
	if((location->lchild!=NULL)&&(location->rchild!=NULL)) 
	case_c(parent,location); 
	free(location); 
	printf("\ndeleted\n"); 
} 
inorder(struct node *ptr) 
{ 
	if(root==NULL) 
	{ 
		printf("\ntree empty\n"); 
		return; 
	} 
	if(ptr!=NULL) 
	{ 
		inorder(ptr->lchild); 
		printf("\n%d\n",ptr->data); 
		inorder(ptr->rchild); 
	} 
} 
preorder(struct node *ptr) 
{ 
	if(root==NULL) 
	{ 
		printf("\ntree empty\n"); 
		return; 
	} 
	if(ptr!=NULL) 
	{ 
		printf("\n%d\n",ptr->data); 
		preorder(ptr->lchild); 
		preorder(ptr->rchild); 
	} 
} 
postorder(struct node *ptr) 
{ 
	if(root==NULL) 
	{ 
		printf("\ntree empty\n"); 
		return; 
	} 
	if(ptr!=NULL) 
	{ 
		postorder(ptr->lchild); 
		postorder(ptr->rchild); 
		printf("\n%d\n",ptr->data); 
	} 
} 
int main() 
{ 
	int n,x; 
	struct node *location,*parent; 
	do 
	{ 
		printf("1.insertion\n2.deletion\n3.search\n4.inorder traversal\n5.preorder traversal\n6.postorder\n7.exit\n"); 
		printf("\nenter ur choice\n"); 
		scanf("%d",&n); 
		switch(n) 
		{ 
			case 1: 
				printf("\nenter element to be inserted\n"); 
				scanf("%d",&x); 
				insert(x); 
				break; 
			case 2: 
				printf("\nenter element to be deleted\n"); 
				scanf("%d",&x); 
				del(x); 
				break; 
			case 3: 
				printf("\nenter element to be searched\n"); 
				scanf("%d",&x); 
				find(x,&parent,&location); 
				if(location!=NULL) 
				printf("\nsearch successfull\n"); 
				else 
				printf("\nitem not found\n"); 
				break; 
			case 4: 
				inorder(root); 
				break; 
			case 5: 
				preorder(root); 
				break; 
			case 6: 
				postorder(root); 
				break; 
			case 7: 
				return 0; 
				break; 
			default : 
				printf("\ndefault entry\n"); 
		} 
	} 
	while(n!=7); 
} 
