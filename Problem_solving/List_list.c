#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int data;
	struct node *next;
}node;

typedef struct list
{
	int iLen;
	node *head;
	struct list *next;
}list;

int iSize = 0;

node *Create_node(int iValue)
{
	node *new_node = NULL;
	
	new_node = (node*)malloc(sizeof(node));
		
	if(new_node == NULL)
	{
		printf("Error in creating new node\n");
		return NULL;
	}

	new_node -> data = iValue;
	new_node -> next = NULL;
		
	return new_node;
}

list *Create_list_node(int m)
{
	list *list_node = NULL;
	
	list_node = (list*)malloc(sizeof(list));
	
	if(list_node == NULL)
	{
		printf("Error in creating list node\n");
		return NULL;
	}

	list_node -> iLen = m;
	list_node -> head = NULL;
	list_node -> next = NULL;

	return list_node;
}

void Build_linked_list(node **first,int iNo)
{
	int i = 0, iValue = 10;
	
	node *new_node = NULL;

	new_node = Create_node(iValue * i);

	if(new_node == NULL)
	{
		return;
	}
	*first = new_node;
	node *temp = *first;

	for(i = 1; i < iNo; i++)
	{
		node *new_node = Create_node(iValue * i);
		
		if(new_node == NULL)
		{
			return;
		}

		temp -> next = new_node;
		temp = new_node;
	}
	
	return;
}

void Create_List_List(list **first,int k, int m)
{
	int i = 0;
	
	list *new_list = Create_list_node(m);
	
	if(new_list == NULL)
	{
		return;
	}

	*first = new_list;
	list *temp = *first;
	iSize++;

	for(i = 1; i < k; i++)
	{
		list *new_list = Create_list_node(m);
	
		if(new_list == NULL)
		{
			return;
		}		
	
		temp -> next = new_list;
		temp -> next;
		iSize++;
	}

	temp = *first;

	for( i = 0; i < k; i++)
	{
		Build_linked_list(&(temp->head),temp->iLen);
		temp = temp -> next;
	}

	return;
}
/*
void Display_list(node *head)
{
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
		
	node *temp = head;

	while(temp != NULL)
	{
		printf("|%d|->",temp -> data);
		temp = temp -> next;
	}

	printf("\n");

	return;
}

void Display_all_lists(list *first_list)
{
	if(first_list == NULL)
	{
		printf("List is empty\n");
		return;
	}

	int i = 1;

	list *temp = first_list;

	while(temp != NULL)
	{
		printf("Printing list number %d : ",i);
		Display_list(temp->head);
		temp = temp -> next;
	}

	return;
}
*/
int main()
{	
	int k = 0, m = 0;
	
	list *first_list = NULL;
	
	printf("Enter number of lists you have : ");
	scanf("%d",&k);

	printf("Enter number of nodes in each list : ");
	scanf("%d",&m);
	
	Create_List_List(&first_list,k,m);	
	
	Display_all_lists(first_list);

	return 0;
}
