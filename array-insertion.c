#include<stdio.h>
void main()
{
	int a[100],n,i,x,pos;
	printf("\nEnter the size of array: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ",n);
	for (i = 0; i < n; i++)
		scanf("%d",&a[i]);
	printf("\nYour array is: ");
	for (i = 0; i < n; i++)
		printf("\t%d",a[i]);
	printf("\nEnter the element and position to be inserted: ");
	scanf("%d%d",&x,&pos);
	if(pos<1)
		printf("\nInvalid position");
	else
	{
		for (i = n-1; i >= pos-1; i--)
			a[i+1]=a[i];
		a[pos-1]=x;
		printf("\nYour array is: ");
		for (i = 0; i < n+1; i++)
			printf("\t%d",a[i]);
	}
}