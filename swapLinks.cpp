#include<iostream>
#include<stdlib.h>
using namespace std;

void createList(struct node**,int);
void displayList(struct node*);
void swapKeys(struct node **,int,int);

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
	createList(&head,87);
	createList(&head,112);
	createList(&head,444);
	displayList(head);
	swapKeys(&head,34,1001);
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



void displayList(struct node *t)
{
	struct node *p=t;
	while(p)
	{
		cout<< (p->d) <<"\t";
		p=p->next;
	}
	cout<<endl;
}


void swapKeys(struct node **h, int x, int y)
{
	struct node *prevX,*curX;			//searching x in the list
	prevX=NULL; curX= *h;
	while(curX && curX->d !=x)
	{
		prevX=curX;
		curX=curX->next;
	}

	struct node *prevY,*curY;			//searching y in the list
	prevY=NULL; curY= *h;
	while(curY && curY->d !=y)
	{
		prevY=curY;
		curY=curY->next;
	}

	if(curX== NULL or curY==NULL)		//return if x or y doesn't exist
		return;

	if (prevX != NULL) 			//if x in not head of linked  list
       prevX->next = curY;
   else // Else make y as new head
       *h = curY;  
 
   								// If y is not head of linked list
   if (prevY != NULL)
       prevY->next = curX;
   else  // Else make x as new head
       *h = curX;
 
   // Swap next pointers
   struct node *temp = curY->next;
   curY->next = curX->next;
   curX->next  = temp;

}