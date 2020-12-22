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
	printf("\nEnter the position of the element to be deleted(1-%d): ",n);
	scanf("%d",&pos);
	if(pos<1)
		printf("\nInvalid position");
	else
	{
		for (i = pos-1; i < n; i++)
			a[i]=a[i+1];
		n--;
		printf("\nYour array is: ");
		for (i = 0; i < n; i++)
			printf("\t%d",a[i]);
	}
}