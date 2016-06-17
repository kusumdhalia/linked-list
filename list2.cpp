#include<iostream>
#include<stdlib.h>
using namespace std;

void createList(struct node**,int);
void displayList(struct node*);
int lengthOfList(struct node *);

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
	displayList(head);
	cout<<lengthOfList(head)<<"nodes"<<endl;
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

/*int lengthOfList(struct node *h)  //using iteration
{
	struct node *p=h;
	int l=0;
	while(p)		
	{
		l++;
		p=p->next;
	}
	return(l);
}*/

int lengthOfList(struct node *h)		//using recursion
{
	if (!h)
	{
		return (0);/* code */
	}
	else
		return(1+lengthOfList(h->next));

}