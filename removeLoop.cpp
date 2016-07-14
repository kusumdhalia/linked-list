#include<iostream>
#include<stdlib.h>
using namespace std;

void createList(struct node**,int);
void displayList(struct node*);
void detect_remove_loop(struct node *);

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
	createList(&head,210);
	createList(&head,444);
	createList(&head,500);
	createList(&head,799);
	createList(&head,1001);
	//displayList(head);
	head->next->next->next->next->next->next->next=head->next->next;
	detect_remove_loop(head);
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

void detect_remove_loop(struct node *head)
{
	struct node *slow, *fast;
	slow=head;
	fast=head->next;

	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			break;
	}

	if(slow==fast)
	{
		slow = head;

		while(slow!=fast->next)
		{
			slow=slow->next;
			fast=fast->next;
		}
		fast->next=NULL;
	}
	
}

/*void removeLoop(struct node *loop, struct node *head)
{
	struct node* p=loop;
	struct node* q=loop;
	int k=0;

	while(p!=q)
	{
		p=p-next;
		k++;
	}

}*/

void displayList(struct node* h)
{
	struct node *p=h;
	while(p)
	{
		cout<<p->d<<"\t";
		p=p->next;
	}
	cout<<endl;
}