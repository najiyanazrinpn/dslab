#include <stdio.h>
int cq[100], front, rear, n, i;
void enqueue(void);
void dequeue(void);
void search(void);
void display(void);
int main()
{
	int ch;
	front = rear = -1;
	printf("\nEnter the size of the circular queue: ");
	scanf("%d",&n);
	do
	{
		printf("\n***************************************\n\tCircular Queue\n***************************************");
		printf("\n1.Enqueue\t2.Dequeue\t3.Search an element\t4.Display your queue\t5.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
				break;
			case 2: dequeue(); break;
			case 3: search(); break;
			case 4: display(); break;
			case 5: printf("\nExiting..."); break;
			default: printf("\nInvalid choice!!! Enter 1-5 :)");
		}
	}while(ch!=5);
	return 0;
}
void enqueue()
{
	int x;
	if (front == (rear+1)%n)
		printf("\nQueue overflow");
	else
	{
		printf("\nEnter the element to be inserted: ");
		scanf("%d",&x);
		if(front == -1)
			front = rear = 0;
		else
			rear = (rear+1)%n;
		cq[rear] = x;
	}
}
void dequeue()
{
	int x;
	if (front == -1)
		printf("\nQueue underflow");
	else
	{
		x = cq[front];
		if(front == rear)
			front = rear = -1;
		else
			front = (front+1)%n;
		printf("\n%d deleted",x);
	}
}
void search()
{
	int x,f=0;
	printf("\nEnter the element to be searched: ");
	scanf("%d",&x);
	if(front !=-1)
	{
		for (i = front; i != rear; i = (i+1)%n)
			if(cq[i] == x)
			{
				printf("\n%d is present at the index %d",cq[i],i);
				f++;
			}
		if(cq[i] == x)
		{
			printf("\n%d is present at the index %d",cq[i],i);
			f++;
		}
		if (f==0)
			printf("\n%d is not present in the queue",x);
	}
	else
		printf("\nEmpty Queue");
}
void display()
{
	printf("\nYour queue is");
	if(front !=-1)
	{
		for (i = front; i != rear; i = (i+1)%n)
				printf("\n%d",cq[i]);
		printf("\n%d",cq[i]);
	}
	else
		printf("\nEmpty");
}