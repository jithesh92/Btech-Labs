#include<stdio.h>
#include<stdlib.h>
# define infinity 9999
struct node
{
	 int pred;
	 int dist;
	 int status;
};
struct edge
{
	int v,u;
};
int adj[10][10],n;
create_graph()
{
	 int i,max_edge,origin,destin,wt;
	 printf("\nenter the number of vertices : ");
	scanf("%d",&n);
	max_edge=n*(n-1)/2;
	for(i=1;i<=max_edge;i++)
	{
		 printf(" enter the edge %d ( 0 0 to quit) : ",i);
		 scanf("%d %d",&origin,&destin);
		if((origin==0)&&(destin==0))
		break;
		printf("enter the weight for this edge : ");
		scanf("%d",&wt);
		if(origin>n|| destin>n||origin<=0||destin<=0)
		{
			printf("\n invalid edge");
			i--;
		}
		else
		{
		 	 adj[origin][destin]=wt;
		    	adj[destin][origin]=wt;
		}
	}
	if(i<n-1)
	exit(0);
}
display()
{
	 int i,j;
	 for(i=1;i<=n;i++)
	{
		 for(j=1;j<=n;j++)
			 printf("%d\t  ",adj[i][j]);
	 printf("\n");
	}
}
int all_perm(struct node state[10])
{
	 int i;
	 for(i=1;i<=n;i++)
	{
		 if(state[i].status==0)
		return 0;
	}
	return 1;
}
int maketree(struct edge tree[10],int *weight)
{
	 struct node state[10];
	 int i,k,min,count,current,newdist,m,u1,v1;
	 *weight=0;
	 for(i=1;i<=n;i++)
	{
		 state[i].pred=0;
		 state[i].dist=infinity;
		 state[i].status=0;
	 }
	state[1].pred=0;
	state[1].dist=0;
	state[1].status=1;
	current =1;
	count=0;
	while(all_perm(state)!=1)
	{
		 for(i=1;i<=n;i++)
		{
			 if(adj[current][i]>0 && state[i].status==0)
			 {
				  if(adj[current][i]<state[i].dist)
				{
					 state[i].pred=current;
					 state[i].dist=adj[current][i];
				 }
			}
		}
		min=infinity;
		for(i=1;i<=n;i++)
		 {
			  if(state[i].status==0 && state[i].dist<min)
			{
				 min=state[i].dist;
				current=i;
			}
		}
		state[current].status=1;
		u1=state[current].pred;
		v1=current;
		count++;
		tree[count].u=u1;
		tree[count].v=v1;
		*weight+=adj[u1][v1];
		}
	return count;
}
main()
{
	 int i,j,path[10],wt_tree,count;
	 struct edge tree[10];
	 create_graph();
	 printf("\n adjacency matrix\n");
	 display();
	count=maketree(tree,&wt_tree);
	printf("\n weight of spanning tree is : %d \t\n",wt_tree);
	printf("\n edges in spanning tree\n");
	for(i=1;i<n;i++)
	{
		 printf( " %d -> ",tree[i].u);
		 printf("%d\n",tree[i].v);
	}
}
