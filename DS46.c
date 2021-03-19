#include <stdio.h>
#include <stdlib.h>
struct node_46
{
	int val_46;
	struct node_46 *next_46;
}*front_46, *rear_46, *n_46;
void display_46(void);
void enqueue_46(int x_46);
int dequeue_46(void);
void main()
{
	int ch_46, x_46;
	front_46 = NULL;
	rear_46 = NULL;
	enqueue_46(2);
	enqueue_46(3);
	enqueue_46(4);
	enqueue_46(5);
	enqueue_46(6);
	do
	{
		printf("\n-----------------------------------------\n\tDEQUEUE USING LINKED LIST\n-----------------------------------------");
		printf("\n1. Display queue\t2. Dequeue\t3. Exit\nEnter your choice: ");
		scanf("%d",&ch_46);
		switch(ch_46)
		{
			case 1: display_46();
					break;
			case 2: 
					if(front_46 == NULL)
					{
						printf("\nQueue underflow!!!");
					}
					else
					{
						x_46 = dequeue_46();
						printf("\n%d deleted",x_46);
					}
					break;
			case 3: printf("\nExiting..");
					break;
			default: printf("\nInvalid choice!!!\nChoice must be 1,2 or 3");
		}
	}while(ch_46 != 3);
}
void display_46()
{
	if((front_46 == NULL) && (rear_46 == NULL))
		printf("\nReturned an empty queue!!!");
	else
	{
		
		printf("\nYour queue is");
		if(front_46 == rear_46)
		{
			printf("\t%d",front_46->val_46);
		}
		else
		{
			struct node_46 *temp_46;
			temp_46 = front_46;
			do
			{
				printf("\t%d",temp_46->val_46);
				temp_46 = temp_46->next_46;
			}while(temp_46 != NULL);
		}
	}
}
void enqueue_46(int x_46)
{
	n_46 = (struct node_46*) malloc(sizeof(struct node_46));
	n_46->val_46 = x_46;
	n_46->next_46 = NULL;
	if(rear_46 == NULL)
	{
		front_46 = rear_46 = n_46;
		
	}
	else
	{
		rear_46->next_46 = n_46;
		rear_46 = rear_46->next_46;
	}
}
int dequeue_46()
{
	int x_46 = front_46->val_46;
	if(front_46 == rear_46)
	{
		free(front_46);
		front_46 = rear_46 = NULL;
	}
	else
	{
		struct node_46 *temp_46;
		temp_46 = front_46;
		front_46 = front_46->next_46;
		free(temp_46);
	}
	return x_46;
}