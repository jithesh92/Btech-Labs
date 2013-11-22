#include<stdio.h>
#include<stdlib.h>
struct edge
{
	int u;
	int v;
	int weight;
	struct edge *link;
}*front=NULL;
int father[20],n,wt_tree=0,count=0;
struct edge tree[20];
void insert_pque(int i,int j,int wt)
{
	struct edge *temp,*q;
	temp=(struct edge *)malloc(sizeof(struct edge));
	temp->u=i;
	temp->v=j;
	temp->weight=wt;
	if(front==NULL || temp->weight<front->weight)
	{
		temp->link=front;
		front=temp;
	}
	else
	{
		q=front;
		while(q->link!=NULL && q->link->weight<=temp->weight)
		q=q->link;
		temp->link=q->link;
		q->link=temp;
			if(q->link==NULL)
			{
				temp->link=NULL;
			}
	}
}
create_graph()
{
	int i,max_edge,orgin,destin,wt;
	printf("\nENTER THE NO.OF VERTICES :  ");
	scanf("%d",&n);
	max_edge=n*(n-1)/2;
	for(i=1;i<=max_edge;i++)
	{
		printf("ENTER THE EDGE %d(0 0 to quit):  ",i);
		scanf("%d %d",&orgin,&destin);
		if((orgin==0)&&(destin==0))
		break;
		printf("ENTER THE WEIGHT FOR THIS EDGE :  ");
		scanf("%d",&wt);
		if(orgin>n || destin>n || orgin<=0 || destin<=0)
		{
			printf("INVALID EDGE \n");
			i--;
		}
		else
		insert_pque(orgin,destin,wt);
	}
	if(i<n-1)
	{
		printf("SPANNIG TREE IS NOT POSSIBLE ");
		exit(0);
	}
}
void insert_tree(int i,int j,int wt)
{
	count++;
	tree[count].u=i;
	tree[count].v=j;
	tree[count].weight=wt;
}
struct edge* del_pque()
{
	struct edge *temp;
	temp=front;
	front=front->link;
	return temp;
}
void maketree()
{
	struct edge *temp;
	int node1,node2,root_n1,root_n2;
	while(count<n-1)
	{
		temp=del_pque();
		node1=temp->u;
		node2=temp->v;
		while(node1>0)
		{
			root_n1=node1;
			node1=father[node1];
		}
		while(node2>0)
		{
			root_n2=node2;
			node2=father[node2];
		}
		if(root_n1 != root_n2)
		{
			insert_tree(temp->u,temp->v,temp->weight);
			wt_tree+=temp->weight;
			father[root_n2]=root_n1;
		}
	}
}
main()
{
	int i;
	create_graph();
	maketree();
	for(i=1;i<=count;i++)
	{
		printf("%d->",tree[i].u);
		printf("%d\n",tree[i].v);
	}
	printf("weight of minimum spanning tree : %d\n",wt_tree);
}
