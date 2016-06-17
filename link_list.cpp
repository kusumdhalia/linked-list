#include<iostream>
#include<stdlib.h>
using namespace std;

void createList(struct node**,int);	//inserts a node at the end
void displayList(struct node*);
void insert_begin(struct node **,int); 		//inserts node at the begin
void insert_after(struct node **, int, int); 		//inserts the node after nth node

struct node
{
	int d;
	struct node *next;
};

int main()
{
	struct node *head=(struct node *)malloc(sizeof(struct node*));
	head=NULL;
	createList(&head,34);
	createList(&head,99);
	createList(&head,1001);
	insert_begin(&head,12);
	insert_begin(&head,85);
	insert_after(&head,4,67);
	displayList(head);
	return(0);
	
}

void insert_begin(struct node **h,int n)
{
	struct node *p= (struct node *) malloc (sizeof(struct node *));
	struct node *q= (struct node *) malloc (sizeof(struct node *));
	p= *h;
	q->d=n;
	q->next=p;
	(*h)=q;

}

void insert_after(struct node **h, int n,int t)
{
	struct node *p= (struct node *) malloc(sizeof(struct node *));
	p->d=t;
	struct node *q= *h;
	
	if(n==0)
	{
		insert_begin(h,t);
		return;
	}

	for (int i = 1; q && i < n; i++)
		q=q->next;

	p->next=q->next;
	q->next=p;
}

void createList(struct node **start,int t)
{
	struct node *newn= (struct node*) malloc(sizeof(struct node *));
	newn->d=t;
	newn->next=NULL;
	struct node *p = *start;
	if ((*start)==NULL)
	{
		*start=newn;
		return;
	}
	
	while(p->next!=NULL)
		p=p->next;

	p->next=newn;
}

void displayList(struct node *t)
{
	struct node *p=t;
	while(p)
	{
		cout<< (p->d) <<endl;
		p=p->next;
	}
	cout<<endl;
}