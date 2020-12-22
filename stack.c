#include<stdio.h>
int stack[100],n,top,x;
void push(void);
void pop(void);
void display(void);
int main()
{
	int ch;
	top=-1;
	printf("\nEnter the size of the stack: ");
	scanf("%d",&n);
	do
	{
		printf("\n\n***************************************\n\t\tStack\n***************************************");
		printf("\n1.Push\t2.Pop\t3.Display Stack\t4.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
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
	return 0;
}
void push()
{
	if(top == n-1)
		printf("\nStack overflow");
	else
	{
		printf("\nEnter the element to be inserted: ");
		scanf("%d",&x);
		stack[++top]=x;
		printf("\n%d inserted",x);
	}
}
void pop()
{
	if(top==-1)
		printf("\nStack underflow");
	else
	{
		x=stack[top];
		top--;
		printf("\n%d deleted",x);
	}
}
void display()
{
	printf("\nYour stack is: ");
	if(top>=0)
	{
		for (int i = top; i >-1; i--)
		printf("\n%d",stack[i]);
	}
	else
		printf("\nEmpty");
}