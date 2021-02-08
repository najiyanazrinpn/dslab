#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* prev;
	int val;
	struct node* next;
};
struct node *head, *tail, *n;
void insertb(void);
void inserte(void);
void insertp(void);
void deleteb(void);
void deletee(void);
void deletep(void);
void search(void);
int size(void);
void display(void);
int main()
{
	int ch, c;
	head = NULL;
	tail = NULL;
	printf("\n-----------------DOUBLY LINKED LIST-----------------");
	printf("\nBefore operation your doubly linked list is:\nhead->NULL\ntail->NULL");
	do
	{
		printf("\n1.Insertion\t2.Deletion\t3.Search\t4.Display\t5.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n1.At the beginning\t2.At a specific position\t3.At the end\t4.Exit\nEnter your choice: ");
				scanf("%d",&c);
				switch(c)
				{
					case 1: insertb(); break;
					case 2: insertp(); break;
					case 3: inserte(); break;
					case 4: break;
					default: printf("\nInvalid choice!!!");
				}
				break;
			case 2:
					printf("\n1.At the beginning\t2.At a specific position\t3.At the end\t4.Exit\nEnter your choice: ");
					scanf("%d",&c);
					switch(c)
					{
						case 1: deleteb(); break;
						case 2: deletep(); break;
						case 3: deletee(); break;
						case 4: break;
						default: printf("\nInvalid choice!!!");
					}
				break;
			// case 3: search();break;
			case 4: display(); break;
			case 5: printf("\nExiting..."); break;
			default: printf("\nIvalid choice!!!");
		}
	}while(ch!=5);
	return 0;
}
void insertb()
{
	n = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter value: ");
	scanf("%d",&n->val);
	n->prev = NULL;
	if (head == NULL)
	{
		n->next = NULL;
		tail = n;
	}
	else
	{
		n->next = head;
		head->prev = n;
	}
	head = n;
	printf("\n%d inserted",n->val);
}
void insertp()
{
	int pos;
	int sz = size();
	struct node *temp;
	printf("\nEnter the position to be inserted: ");
	scanf("%d",&pos);
	if((pos<1)||(pos>sz+1))
		printf("\nInvalid position!!!");
	else if((pos==1)||(sz==0))
		insertb();
	else if(pos==sz+1)
		inserte();
	else
	{
		n = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter value: ");
		scanf("%d",&n->val);
		temp = head;
		for (int i = 1; i<pos-1; i++)
			temp=temp->next;
		n->next = temp->next;
		n->prev = temp;
		(temp->next)->prev=n;
		temp->next = n;
		printf("\n%d inserted",n->val);
	}
}
void inserte()
{
	if (head == NULL)
		insertb();
	else
	{
		n = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter value: ");
		scanf("%d",&n->val);
		n->prev = tail;
		n->next = NULL;
		tail->next = n;
		tail = n;
		printf("\n%d inserted",n->val);
	}
}
void deleteb()
{
	if(head == NULL)
		printf("\nDeletion not possible!!!");
	else if (head==tail)
	{
		printf("\n%d deleted",head->val);
		free(head);
		head = NULL;
		tail = NULL;
	}
	else
	{
		struct node *temp;
		temp = head;
		head = head->next;
		head->prev = NULL;
		printf("\n%d deleted",temp->val);
		free(temp);
	}
}
void deletep()
{
	int pos;
	int sz = size();
	struct node *temp;
	printf("\nEnter the position of the element to be deleted: ");
	scanf("%d",&pos);
	if((head == NULL)||(pos<1)||(pos>sz))
		printf("\nDeletion not possible!!!");
	else if(pos==1)
		deleteb();
	else if(pos==sz)
		deletee();
	else
	{
		temp = head;
		for (int i = 1; i<pos; i++)
		{
			temp=temp->next;
		}
		(temp->prev)->next = temp->next;
		(temp->next)->prev = temp->prev;
		free(temp);
	}
}
void deletee()
{
	if(head == NULL)
		printf("\nDeletion not possible!!!");
	else if (head==tail)
	{
		printf("\n%d deleted",head->val);
		free(head);
		head = NULL;
		tail = NULL;
	}
	else
	{
		struct node *temp;
		temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		printf("\n%d deleted",temp->val);
		free(temp);
	}
}
void display()
{
	struct node *temp;
	printf("head->");
	temp = head;
	while(temp!=NULL)
	{
		printf("%d->",temp->val);
		temp = temp->next;
	}
	printf("NULL\n");
	temp = tail;
	while(temp!=NULL)
	{
		printf("%d\t",temp->val);
		temp = temp->prev;
	}
}
int size()
{
	struct node *temp;
	int n=0;
	temp = head;
	while(temp!=NULL)
	{
		n++;
		temp = temp->next;
	}
	return n;
}