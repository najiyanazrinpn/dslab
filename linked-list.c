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
void inserte(void);
void insertp(void);
void deleteb(void);
void deletee(void);
void deletep(void);
void display(void);
int main()
{
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
					case 2: insertp(); break;
					case 3: inserte(); break;
					case 4: break;
					default: printf("\nInvalid choice!!!");
				}
				break;
			case 2:
				if(i==0)
					printf("\nDeletion not possible!!");
				else
				{
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
				}
				break;
			case 3: display(); break;
			case 4: printf("\nExiting..."); break;
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
	int item;
	printf("\nEnter the data part: ");
	scanf("%d",&item);
	n = (struct node*)malloc(sizeof(struct node));
	n->val = item;
	n->next=head;
	head = n;
	i++;
}
void insertp()
{
	int item,pos;
	struct node *temp;
	printf("\nEnter the position to be inserted(1-%d): ",i+1);
	scanf("%d",&pos);
	if (pos<1 || pos>i+1)
		printf("\nInvalid position!!!");
	else
	{
		if (pos == 1)
			insertb();
		else if (pos == i+1)
			inserte();
		else
		{
			struct node *pre;
			printf("\nEnter the data part: ");
			scanf("%d",&item);
			n = (struct node*)malloc(sizeof(struct node));
			n->val = item;
			int j = 2;
			pre = head;
			temp = head->next;
			while(temp->next!=NULL)
			{
				if (j==pos)
					break;
				j++;
				pre = temp;
				temp=temp->next;
			}
			n->next = pre->next;
			pre->next = n;
		}
	}
}
void inserte()
{
	int item;
	struct node *temp;
	printf("\nEnter the data part: ");
	scanf("%d",&item);
	n = (struct node*)malloc(sizeof(struct node));
	n->val = item;
	if (head == NULL)
		head = n;
	else
	{
		temp = head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=n;
	}
	n->next=NULL;
	i++;
}
void deleteb()
{
	struct node *n;
	n = head;
	head = head->next;
	free(n);
	printf("\nNode deleted");
	i--;
}
void deletep()
{
	int pos;
	printf("\nEnter the position of the element to be deleted: ");
	scanf("%d",&pos);
	if (pos<1 || pos>i)
	{
		printf("\nInvalid position!!!");
	}
	else
	{
		struct node *n, *pre;
		pre = head;
		n = head->next;
		int j = 2;
		while(n->next != NULL)
		{
			if(j == pos)
				break;
			j++;
			pre = n;
			n = n->next;
		}
		pre->next = n->next;
		free(n);
		printf("\nNode deleted");
		i--;
	}
}
void deletee()
{
	struct node *pre, *n;
	n = head;
	while(n->next!=NULL)
	{
		pre = n;
		n=n->next;
	}
	if(n==head)
		head = NULL;
	else
		pre->next=NULL;
	free(n);
	printf("\nNode deleted");
	i--;
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