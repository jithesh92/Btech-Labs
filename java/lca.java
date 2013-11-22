import java.util.*;

class Node
	{
	int data;
	Node l,r,p;
	
	Node(Node parent,int n)
		{
		p=parent;
		l=null;
		r=null;
		data=n;
		}
	}
	
class Tree
	{
	Node root;
	
	
	
	Tree(int ro)
		{
		root=new Node(null,ro);
		}
	
	public Node insert(int po,Node l)
		{
		if(l!=null)
		{
		if(l.data==po)
			{
			Scanner in= new Scanner(System.in);
			
			System.out.println("Enter the value");
			int val=in.nextInt();
			System.out.println("Left or Right (l/r)");
			
			char a=in.next().charAt(0);
			if(a=='l')
				{
				l.l=new Node(l,val);
				
				}
				
			else if(a=='r')
				{
				l.r=new Node(l,val);
				
				}
			return l;	
			}
		else
			{
			insert( po,l.l);
			insert( po,l.r);
			}
			return l;
		}
	return l;
	}
	
	public void dis(Node p)
		{
		if(p!=null)
			{
			dis(p.l);
			System.out.println(p.data);
			dis(p.r);
			}
		}
	}
	
class Common_Ancestor extends Thread
	{
	Node p;
	int a;
	public  boolean found;
	
	Common_Ancestor(Node l,int n)
		{
		p=l;
		a=n;
		found=false;
		}
	
	public void run()
		{
		
		
		this.found=tra(p,a);
		
		
			
		
		}
		
	public boolean tra(Node p,int a )
		{
		boolean b=false,c=false;
		if(p!=null)
			{
			
			if(p.data==a)
				{
				return (true);
				}
			else{
			b=tra(p.l,a);
			c=tra(p.r,a);
				}
			
			}
		
			return (b||c);
			
		}
	
	
	}	
public class Least_Common_Ancestor
	{
	
	public static void main(String arg[])
		{
		int n;
		Scanner in= new Scanner(System.in);
		final String ANSI_CLS = "\u001b[2J";
        	final String ANSI_HOME = "\u001b[H";
        	System.out.print(ANSI_CLS + ANSI_HOME);
		System.out.println("Enter the root  ");
		n=in.nextInt();
		Tree bt=new Tree(n);
		int ch;
		
		do
			{
			 
	
			System.out.println("Enter Your choice  ");
			System.out.println("1. Insert");
			System.out.println("2. Display Inorder  ");
			System.out.println("3. Least common factor ");
			System.out.println("4. Exit");
			ch=in.nextInt();
		
			switch(ch)
				{
				case 1:
				  System.out.println("Enter the position  ");
				  n=in.nextInt();
				  bt.insert(n,bt.root);
				break;
				case 2:
			
				   bt.dis(bt.root);
				break;
				case 3:
				   System.out.println("Enter the Nodes to find LCA");
				   int a=in.nextInt();
				   int b=in.nextInt();
				   check(a,b,bt.root);
				break;
				}
			}
		while(ch<4);
		  
		
		}
	public static void check(int a,int b,Node p)
		{
		
		
		Common_Ancestor a1=new Common_Ancestor(p.r,b);
		Common_Ancestor a2=new Common_Ancestor(p.l,a);
		a1.start();
		a2.start();
		
		try{
		
		Thread.sleep(100);
		}
		catch(InterruptedException e){}
		
		//System.out.println("1 " +a1.found);
		//System.out.println("2 " +a2.found);
		
		if(((a1.found)&&(p.data==a))||((a2.found)&&(p.data==b)))
			{
			if(p.p==null)
				{
				System.out.println("No common ancestor");
				}
			else{
				System.out.println("LCA is " +LCA(p.p));
				}
			}
		
		else if((a1.found)&&(a2.found))
			{
						
			System.out.println("LCA is " +LCA(p));
			}
		else if((a1.found)&&(!a2.found))
			{
			check( a, b, p.r);
			}
		else if((!a1.found)&&(a2.found))
			{
			check( a, b, p.l);
			}
		else if((!a1.found)&&(!a2.found))
			{
			check( b,a, p);
			}
		}
		public static int LCA(Node p)
			{
			int lca=p.data;
			
			return lca;
			}
	
	}
