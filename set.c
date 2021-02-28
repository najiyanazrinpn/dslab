#include <stdio.h>
int superSet[30], setA[10], setB[10], bitStringA[30] = {0}, bitStringB[30] = {0}, m, ma,mb;
void display( int set[], int size);
void displayBitString( int set[], int size);
void bitstringfn(int set[], int size, int *bitStringn, int m);
void setfn(int bitString[], int m);
int search(int l, int r, int x);
void unionSet(int bitStringA[], int bitStringB[], int m);
void intersect(int bitStringA[], int bitStringB[], int m);
void difference(int bitStringA[], int bitStringB[], int m);
void main()
{
	int ch;
	printf("Enter the number of elements in super set: ");
	scanf("%d", &m);
	printf("\nEnter the elements: ");
	for (int i=0; i<m; i++)
		scanf("%d", &superSet[i]);
	for (int i = 0; i < m-1; i++)
		for (int j = i; j < m; j++)
			if(superSet[i]>superSet[j])
			{
				int t = superSet[i];
				superSet[i] = superSet[j];
				superSet[j] = t;
			}
	printf("Enter the number of elements in set A: ");
	scanf("%d", &ma);
	printf("\nEnter the elements: ");
	for (int i=0; i<ma; i++)
		scanf("%d", &setA[i]);
	for (int i = 0; i < ma-1; i++)
		for (int j = i; j < ma; j++)
			if(setA[i]>setA[j])
			{
				int t = setA[i];
				setA[i] = setA[j];
				setA[j] = t;
			}
	bitstringfn(setA, ma, bitStringA, m);
	printf("Enter the number of elements in set b: ");
	scanf("%d", &mb);
	printf("\nEnter the elements: ");
	for (int i=0; i<mb; i++)
		scanf("%d", &setB[i]);
	for (int i = 0; i < mb-1; i++)
		for (int j = i; j < mb; j++)
			if(setB[i]>setB[j])
			{
				int t = setB[i];
				setB[i] = setB[j];
				setB[j] = t;
			}
	bitstringfn(setB, mb, bitStringB, m);
	do
	{
		printf("\n--------------SET OPERATIONS--------------");
		printf("\n1. Show sets\n2. Show bitstring of set A and B\n3. Find union of A and B\n4. Find intersection of A and B\n5. Find the difference of A and B\n6. Exit");
		printf("\nEnter your choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("\nSuper set:: ");
					display(superSet, m);
					printf("\nSet A:: ");
					display(setA, ma);
					printf("\nSet B:: ");
					display(setB, mb);
					break;
			case 2: printf("\nBitstring of set A :: ");
					displayBitString(bitStringA, m);
					printf("\nBitstring of set B :: ");
					displayBitString(bitStringB, m);
					break;
			case 3: unionSet(bitStringA, bitStringB, m);
					break;
			case 4: intersect(bitStringA, bitStringB, m);
					break;
			case 5: printf("\nA-B:: ");
					difference(bitStringA, bitStringB, m);
					printf("\nB-A:: ");
					difference(bitStringB, bitStringA, m);
					break;
			case 6: printf("\nExiting...");
					break;
			default: printf("\nInvalid choice!!!");
		}
	}while(ch!=6);
}
void display(int set[], int size)
{
	int i;
	printf("{ ");
	for (i = 0; i < size-1; i++)
		printf(" %d , ", set[i]);
	printf(" %d }", set[i]);
}
void displayBitString(int set[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf(" %d", set[i]);
}
void setfn(int bitString[], int m)
{
	int set[30], j=0;
	for (int i = 0; i < m; i++)
	{
		if(bitString[i]==1)
		{
			set[j] = superSet[i];
			j++;
		}
	}
	display(set, j);
}
int search(int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (superSet[mid] == x)
			return mid;
		if (superSet[mid] > x)
			return search( l, mid - 1, x);
		return search( mid + 1, r, x);
	}
	return -1;
}
void bitstringfn(int set[], int size, int *bitString, int m)
{
	int pos,i;
	for( i = 0; i < size; i++)
	{
		pos = search(0, m-1, set[i]);
		if(pos != -1)
			bitString[pos]=1;
	}
}
void unionSet(int bitStringA[], int bitStringB[], int m)
{
	int bitString[30] = {0};
	for (int i = 0; i < m; i++)
		bitString[i] = (bitStringA[i]||bitStringB[i]);
	printf("\nAUB:: ");
	setfn(bitString, m);
	printf("\nBitstring:: ");
	displayBitString(bitString, m);
}
void intersect(int bitStringA[], int bitStringB[], int m)
{
	int bitString[30] = {0};
	for (int i = 0; i < m; i++)
		bitString[i] = (bitStringA[i]&&bitStringB[i]);
	printf("\nA^B:: ");
	setfn(bitString, m);
	printf("\nBitstring:: ");
	displayBitString(bitString, m);
}
void difference(int bitString1[], int bitString2[], int m)
{
	int diff[30];
	for (int i = 0; i<m; i++)
		diff[i] = bitString1[i];
	for (int i = 0; i < m; i++)
	{
		if((bitString1[i] == 1) && (bitString2[i] == 1))
			diff[i]=0;
	}
	setfn(diff, m);
	printf("\nBitstring:: ");
	displayBitString(diff, m);
}