#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node* next;
};
int i;
struct node *head, *t, *n;
void create(void);
void insertb(void);
void display(void);
int main()
{//not completed. will update it later
	int ch, c;
	i=0;
	head=NULL;
	printf("\n-----------------LINKED LIST-----------------");
	printf("\nBefore creation your linked list is:\nhead->NULL");
	do
	{
		printf("\n1.Continue creation\t2.Stop the creation\nEnter your choice:");
		scanf("%d",&ch);
		if (ch==1)
		{
			i++;
			printf("\nCreating %d th node...",i);
			create();
		}
	}while(ch!=2);
	display();
	do
	{
		printf("\n1.Insertion\t2.Deletion\t3.Display\t4.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n1.At the beginning\t2.At a specific position\t3.At the end\t4.Exit\nEnter your choice: ");
				scanf("%d",&c);
				switch(c)
				{
					case 1: insertb(); break;
					/*case 2: insertp(); break;
					case 3: inserte(); break;*/
					default: printf("\nInvalid choice!!!");
				}
				break;
			/*case 2:
				printf("\n1.At the beginning\t2.At a specific position\t3.At the end\t4.Exit\nEnter your choice: ");
				scanf("%d",&c);
				switch(c)
				{
					case 1: deleteb(); break;
					case 2: deletep(); break;
					case 3: deletee(); break;
				}
				break;*/
			default: printf("\nIvalid choice!!!");
		}
	}while(ch!=4);
	return 0;
}
void create()
{
	int item;
	n = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data part: ");
	scanf("%d",&item);
	if (i==1)
	{
		head = n;
		t = n;
	}
	else
	{
		t->next = n;
		t = t->next;
	}
	n->val = item;
	n->next = NULL;
	printf("\nNode created!");
}
void insertb()
{
	printf("\nEnter the data part: ");
	scanf("%d",&item);
	n = (struct node*)malloc(sizeof(struct node));
}
void display()
{
	t = head;
	printf("\nhead->");
	while(t!=NULL)
	{
		printf("%d->",t->val);
		t = t->next;
	}
	printf("NULL");
}
