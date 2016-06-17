#include<stdio.h>
#include<stdlib.h>

struct node
{
	int d;
	struct node *next;
};

int main()
{
	int j,k,n,m;
	k=1;
	void add(struct node **,int);
	void display(struct node *);
	void search_del(struct node *,int);
	void reverse(struct node **);
	struct node *h;
	h=NULL;
	while(k)
	{
		printf("***Menu***\n1.Create list\n2.Display\n3.Search and delete\n4.Reverse\n5.Exit\n");
		printf("Enter your choice");
		scanf("%d",&j);
		switch(j)
		{
			case 1:
				printf("Enter data");
				scanf("%d",&n);
				add(&h,n);
				break;
			case 2:
				display(h);
				break;
			case 3:
				printf("Enter the element to delete");
				scanf("%d",&m);
				search_del(h,m);
				break;	
			case 4:
				reverse(&h);
				break;
			case 5:
				k=0; 
				break;
			default:
				printf("wrong choice");
		}
	}
	return(0);
}

void add(struct node **p,int n)
{
	struct node *q,*t;
	//printf("abcd");
	if(*p==NULL)
	{
		*p=(struct node *)malloc(sizeof(struct node));
		(*p)->d=n;
		(*p)->next=NULL;
	}
	else
	{
		q=*p;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		t=(struct node *)malloc(sizeof(struct node));
		t->d=n;
		t->next=NULL;
		q->next=t;
	}	
}

void display(struct node *t)
{
	while(t!=NULL)
	{
		printf("%d\t",t->d);
		t=t->next;
	}
//	printf("%d\t",t->d);
	printf("\n");
}

void search_del(struct node *p,int x)
{
	while(p->next->d!=x)
	{
		p=p->next;
	}
	if(p->next->d==x)
	{
		p->next=p->next->next;
	}
}

void reverse(struct node **p)
{
	/*struct node *q,*s,*r;
	s=NULL;
	q=(*p)->next;
	r=(*p); 
	while(q->next!=NULL)
	{
		r->next=s;
		s=r;
		r=q;
		q=q->next;
	}	
	q->next=r;
	(*p)=q;*/
	
	struct node *q,*s,*r;
	s=NULL;
	q=(*p);
	r=(*p)->next;
	while(q->next!=NULL)
	{
		q->next=s;
		s=q;
		q=r;
		r=r->next;
	}
	q->next=s;
	*p=q;
}
