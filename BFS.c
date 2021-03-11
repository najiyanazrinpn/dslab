#include <stdio.h>
int v[10], e[100][2], adj[10][10]={0}, visited[10] = {0}, queue[10];
int v_num, e_num, front = -1, rear = -1;
void adjacency_matrix(void);
int search(int x, int array[]);
int searchqueue(int x, int q[]);
void enqueue(int);
int dequeue(void);
int empty(void);
void bfs(int);
void main()
{
	int st;
	printf("\n------------------------------------\n\tBreadth First Search\n------------------------------------");
	printf("\nEnter the number of vertices: ");
	scanf("%d",&v_num);
	printf("\nEnter the %d vertices: ",v_num);
	for(int i=0; i < v_num; i++)
		scanf("%d", &v[i]);
	printf("\nEnter the number of edges: ");
	scanf("%d", &e_num);
	printf("\nEnter the %d pair/s of vertices(edges): ", e_num);
	for (int i = 0; i < e_num; i++)
	{
		scanf("%d%d", &e[i][0], &e[i][1]);
		int pos1 = search(e[i][0],v);
		int pos2 = search(e[i][1],v);
		if ((pos1 != -1)&&(pos2 != -1))
			adj[pos1][pos2]=1;
	}
	printf("\nThe vertices: ");
	for(int i=0; i < v_num; i++)
		printf("\n%d", v[i]);
	printf("\nThe edges: ");
	for(int i=0; i < e_num; i++)
		printf("{%d, %d} ", e[i][0], e[i][1]);
	printf("\nAdjacency Matrix:\n");
	adjacency_matrix();
	printf("\nEnter the starting vertex: ");
	scanf("%d", &st);
	bfs(st);
	return;
}
int search(int x, int array[])
{
	for (int i = 0; i < v_num; i++)
		if (array[i] == x)
			return i;
	return -1;
}
int searchqueue(int x, int q[])
{
	for (int i = front; i <= rear; i++)
	{
		if (q[i] == x)
			return i;
	}
	return -1;
}
void adjacency_matrix()
{
	for (int i = 0; i < v_num; i++)
	{
		for (int j = 0; j < v_num ; j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
}
void enqueue(int x)
{
	if (rear == -1)
		front = rear = 0;
	else
		rear+=1;
	queue[rear] = x;
}
int dequeue()
{
	int x;
	if (front >= 0)
		x=queue[front];
	if(front==rear)
		front=rear=-1;
	else
		front+=1;
	return(x);
}
void bfs(int st)
{
	int i = 0;
	enqueue(st);
	int in;
	printf("\nBFS for the given graph is: ");
	while(visited[v_num-1]==0)
	{
		visited[i] = dequeue();
		printf("\n%d",visited[i]);
		int pos = search(visited[i], v);
		for (int j = 0; j < v_num; j++)
		{
			if ((adj[pos][j]==1)&&(search(v[j], visited)==-1)&&(searchqueue(v[j], queue)==-1))
				enqueue(v[j]);
		}
		i++;
	}
}