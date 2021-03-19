#include <stdio.h>
int v[10], e[100][2], adj[10][10]={0}, visited[10] = {0}, stack[10];
int v_num, e_num, top = -1;
int k = 0;
void adjacency_matrix(void);
int search(int x, int array[]);
// int searchstack(int x, int array[]);
void push(int);
int pop();
void dfs(int);
void main()
{
	int st, i;
	printf("\n------------------------------------\n\tDepth First Search\n------------------------------------");
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
		{
			adj[pos1][pos2]=1;
			adj[pos2][pos1]=1;
		}
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
	dfs(st);
	printf("\nDFS");
	for (int i = 0; i < v_num; i++)
	{
		printf("\n%d",visited[i]);
	}
	return;
}
int search(int x, int array[])
{
	for (int i = 0; i < v_num; i++)
		if (array[i] == x)
			return i;
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
void push(int x)
{
	stack[++top] = x;
	// visited[i] = x;
}
int pop()
{
	return(stack[top--]);
}
void dfs(int st)
{
	push(st);
	int x = st;
	visited[k++] = st;
	int pos = search(st,v);
	for(int i = 0; i<v_num;i++)
	{
		if((adj[pos][i]==1)&&(search(v[i],visited)==-1))
		{
			push(v[i]);
			dfs(v[i]);
		}
	}
}