#include <stdio.h>
#include <limits.h>
int V[10], adj[10][10]={0}, visited[10]={0}, k=0, cost = 0;
int v_num, e_num;
void adjacency_matrix(void);
int search(int x, int array[]);
void prims(int);
void main()
{
	int st,u,v,wt,min_wt;
	printf("\n------------------------------------\n\tPrims\n------------------------------------");
	printf("\nEnter the number of vertices: ");
	scanf("%d",&v_num);
	printf("\nEnter the %d vertices: ",v_num);
	for(int i=0; i < v_num; i++)
		scanf("%d", &V[i]);
	printf("\nEnter the number of edges: ");
	scanf("%d", &e_num);
	for (int i = 1; i <= e_num; i++)
	{
		printf("\nEnter the %dth pair of vertices: ", i);
		scanf("%d%d",&u,&v);
		printf("\nEnter the weight of the edge %d-%d: ",u,v);
		scanf("%d",&wt);
		int pos1 = search(u,V);
		int pos2 = search(v,V);
		if ((pos1 != -1)&&(pos2 != -1))
		{
			if((i==1)||(wt<min_wt))
			{
				st = u;
				min_wt = wt;
			}
			adj[pos1][pos2] = wt;
			adj[pos2][pos1] = wt;
		}
		else e_num--;
	}
	printf("\nThe vertices: ");
	for(int i = 0; i < v_num; i++)
		printf("\t%d", V[i]);
	printf("\nAdjacency Matrix:\n");
	adjacency_matrix();
	prims(st);
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
			printf("%d\t",adj[i][j]);
		printf("\n");
	}
}
void prims(int st)
{
	printf("\nVisited: %d",st);
	int min_wt=INT_MAX, u, v;
	int pos = search(st, V);
	if(k==0)
		visited[k++] = st;
	// int q[10];
	if(k<v_num)
	{
		for(int i = 0; i<v_num; i++)
		{
			if(adj[pos][i]!=0 && adj[pos][i]<min_wt)
			{
				min_wt = adj[pos][i];
				v = V[i];
				u = V[pos];
			}
		}
		adj[search(v,V)][search(u,V)] = INT_MAX;
		adj[search(u,V)][search(v,V)] = INT_MAX;
		cost+=min_wt;
		visited[k++]=v;
		prims(v);
	}
	else
		printf("\nTotal cost: %d",cost);
}