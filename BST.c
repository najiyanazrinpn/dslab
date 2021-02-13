#include <stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *left;
	struct node *right;
};
struct node *root, *n, *temp;
struct node* insertx(struct node* root, int x);
struct node* deletex(struct node* root, int x);
struct node* searchx(struct node* root, int x);
void display(struct node*);
void main()
{
	int ch, x;
	root = NULL;
	do
	{
		printf("\n----------------------------------------------------\n\t\tBINARY SEARCH TREE\n----------------------------------------------------\n1. Insert a node\t2. Delete a node\t3. Search\t4. Display\t5. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					
					printf("Enter the element to be inserted: ");
					scanf("%d",&x);
					root = insertx(root,x);
					break;
			case 2: 
					if (root==NULL)
						printf("\nDeletion not possible!!!");
					else
					{
						printf("\nEnter the element to be deleted: ");
						scanf("%d",&x);
						printf("\nDelete %d",x);
						root = deletex(root,x);
					}
					break;
			case 3: 
					printf("\nEnter the element to be searched: ");
					scanf("%d",&x);
					root = searchx(root,x);
					break;
			case 4: if(root==NULL)
						printf("Tree is NULL");
					else
						display(root);
					break;
			case 5: 
					printf("Exiting...");
					break;
			default:
					printf("Invalid choice!!!");
		}
	}while(ch!=5);
}
struct node* insertx(struct node* root, int x)
{
	if(root==NULL)
	{
		n = (struct node*)malloc(sizeof(struct node));
		n->val = x;
		n->left = NULL;
		n->right = NULL;
		root = n;
	}
	else
		if(x < root->val)
			root->left = insertx(root->left,x);
		else if(x>root->val)
			root->right = insertx(root->right,x);
		else
			printf("\nCan't insert duplicate element!!!");
	return root;
}
struct node* inorderPred(struct node* root)
{
	temp = root;
	while(temp && temp->left!=NULL)
		temp = temp->left;
	return temp;
}
struct node* deletex(struct node* root, int x)
{
	if(x < root->val)
		root->left = deletex(root->left,x);
	else if(x > root->val)
		root->right = deletex(root->right,x);
	else
	{
		if(root->left==NULL)
		{
			struct node *temp = root->right;
			printf("\nElement deleted");
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node *temp = root->left;
			printf("\nElement deleted");
			free(root);
			return temp;
		}
		struct node *temp = inorderPred(root->right);
		root->val = temp->val;
		root->right = deletex(root->right,temp->val);
	}
	return root;
}
struct node* searchx(struct node* root, int x)
{
	if(root==NULL)
		printf("\nThe element doesn't exist!!!");
	else if(x==root->val)
		printf("\n%d found.",x);
	else
		if(x < root->val)
			root->left = searchx(root->left,x);
		else
			root->right = searchx(root->right,x);
	return(root);
}
void display(struct node* root)
{
	if(root!=NULL)
	{
		display(root->left);
		printf("\n%d",root->val);
		display(root->right);
	}
}