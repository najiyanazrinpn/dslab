#include <stdio.h>
int main()
{
	int a[10],b[10],c[20],m,n,i,j;
	printf("\nEnter size of array1: ");
	scanf("%d",&m);
	printf("\nEnter %d elements: ",m);
	for (i = 0; i < m; i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	printf("\nEnter size of array2: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ",n);
	for (j = 0; j < n; j++)
	{
		scanf("%d",&b[j]);
		c[i]=b[j];
		i++;
	}
	printf("\nArray1: ");
	for (i = 0; i < m; i++)
		printf("\t%d",a[i]);
	printf("\nArray2: ");
	for (j = 0; j < n; j++)
		printf("\t%d",b[j]);
	printf("\nMerged array before sorting: ");
	for (i = 0; i < m+n; i++)
		printf("\t%d",c[i]);
	for (int i = 0; i < m+n; i++)
	{
		for(j=i; j<m+n;j++)
			if(c[i]>c[j])
			{
				int t=c[i];
				c[i]=c[j];
				c[j]=t;
			}
	}
	printf("\nMerged array before sorting: ");
	for (i = 0; i < m+n; i++)
		printf("\t%d",c[i]);
	return 0;
}