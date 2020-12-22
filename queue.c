#include<stdio.h>
int queue[10],n,front,rear,x;
void enqueue(void);
void dequeue(void);
void display(void);
int main()
{
	int ch;
	front=rear=-1;
	printf("\nEnter the size of the queue: ");
	scanf("%d",&n);
	do
	{
		printf("\n***************************************\n\t\tQueue\n***************************************");
		printf("\n1.Enqueue\t2.Dequeue\t3.Display your queue\t4.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				front=0;
				enqueue();
				break;
			case 2:
				dequeue();
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
void enqueue()
{
	if (rear==n-1)
	{
		printf("\nQueue overflow");
	}
	else
	{
		front = 0;
		printf("\nEnter the element to be inserted: ");
		scanf("%d",&x);
		queue[++rear]=x;
		printf("\n%d inserted",queue[rear]);

	}
}
void dequeue()
{
	if (front < 0)
	{
		printf("\nQueue underflow");
	}
	else
	{
		x=queue[front];
		printf("\n%d deleted",x);
	}
	if(front==rear)
		front=rear=-1;
	else
		front+=1;
}
void display()
{
	printf("\nYour queue is: ");
	if (front<0)
		printf("\nEmpty");
	else
		for (int i = front; i <= rear; i++)
			printf("\n%d",queue[i]);
}