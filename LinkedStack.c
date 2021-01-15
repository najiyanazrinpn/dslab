#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node *next;
};
struct node *head,*top;
int i = 0;
void push(int);
void pop(void);
void display(void);
void main()
{
	int ch, size;
	head = NULL;
	top = NULL;
	printf("\nEnter the size of stack: ");
	scanf("%d",&size);
	do
	{
		printf("\n\n***************************************\n\t\tStack\n***************************************");
		printf("\n1.Push\t2.Pop\t3.Display Stack\t4.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push(size);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nExiting...");
				break;
			default:
				printf("\nInvalid choice! Please enter a valid choice(1/2/3/4).");
		}
	}while(ch!=4);
}
void push(int size)
{
	if(i>=size)
		printf("\nStack overflow!!! Push is not possible.");
	else
	{
		int item;
		struct node *n;
		n = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter the element: ");
		scanf("%d",&item);
		n->val = item;
		n->next = NULL;
		if (top == NULL)
		{
			head = n;
			top = n;
		}
		else
		{
			top->next = n;
			top = top->next;
		}
		i++;
	}
}
void pop()
{
	if (i==0)
		printf("\nStack underflow!!! Pop is not possible.");
	else
	{
		struct node *prev, *temp;
		temp = head;
		prev = head;
		while(temp!=top)
		{
			prev = temp;
			temp = temp->next;
		}
		top = prev;
		prev->next = NULL;
		int x = temp->val;
		free(temp);
		printf("\n%d deleted",x);
		i--;
		if(i==0)
			head = top = NULL;
	}
}
void display()
{
	printf("\nYour stack is:");
	if(i==0)
		printf("\tEmpty");
	else
	{
		struct node *temp;
		temp = head;
		while(temp!=NULL)
		{
			printf("\t%d",temp->val);
			temp = temp->next;
		}
	}
}