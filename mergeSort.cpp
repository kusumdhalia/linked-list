#include<iostream>
#include<stdlib.h>
using namespace std;

void createList(struct node**,int);
void displayList(struct node*);
struct node* mergeLists(struct node*,struct node*);
void mergeSort(struct node **);
void split(struct node*, struct node **,struct node**);


struct node
{
	int d;
	struct node *next;
};

int main()
{
	struct node *head=(struct node *)malloc(sizeof(struct node*));
	head=NULL;
	
	createList(&head,230);
	createList(&head,400);
	createList(&head,1001);
	createList(&head,34);
	createList(&head,99);
	
	displayList(head);
	
	//reverseList(&head);
	mergeSort(&head);
	displayList(head);
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

void mergeSort(struct node **head)
{
	struct node *a, *b;
	struct node *h=*head;

	split(h,&a,&b);
	mergeSort(&a);
	mergeSort(&b);

	*head=mergeLists(a,b);

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

void split(struct node *h, struct node **a, struct node **b)
{
	struct node *slow, *fast;
	if(h==NULL or h->next==NULL)
	{
		*a=h;
		*b=NULL;
	}
	else
	{
		slow=h;
		fast=h->next;

		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast!=NULL)
			{
				slow=slow->next;
				fast=fast->next;
			}
		}

		*a=h;
		*b=slow->next;
		slow->next=NULL;
	}
}

void displayList(struct node *h)
{
	struct node *t=h;
	while(t)
	{
		cout<<t->d<<"\t";
		t=t->next;
	}
	cout<<endl;
}