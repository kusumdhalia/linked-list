#include<iostream>
#include<stdlib.h>
using namespace std;

void createList(struct node**,int);
void displayList(struct node*);
struct node* mergeLists(struct node *,struct node *);

struct node
{
	int d;
	struct node *next;
};

int main()
{
	struct node *h1=(struct node *)malloc(sizeof(struct node*));
	h1=NULL;
	createList(&h1,34);
	createList(&h1,99);
	createList(&h1,1001);
	cout<<"list 1:\t";
	displayList(h1);
	
	struct node *h2=(struct node *)malloc(sizeof(struct node*));
	h2=NULL;
	createList(&h2,14);
	createList(&h2,51);
	createList(&h2,88);
	createList(&h2,512);
	cout<<"list 2:\t";
	displayList(h2);

	struct node* h3=mergeLists(h1,h2);
	cout<<"Merged list:"<<endl;
	displayList(h3);
	return(0);
	
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
}

struct node* mergeLists(struct node *a, struct node *b)
{
	struct node *c=NULL;

	if(a==NULL)
		return(b);
	if(b==NULL)
		return(a);

	if( (a->d) <= (b->d))
	{
		c=a;
		c->next=mergeLists(a->next,b);
	}
	else
	{
		c=b;
		c->next=mergeLists(a,b->next);
	}
	return(c);
}