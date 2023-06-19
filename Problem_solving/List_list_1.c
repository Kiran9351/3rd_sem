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
		printf("Error in creating node\n");
		return NULL;
	}
	
	new_node -> data = iValue;
	new_node -> next = NULL;

	return new_node;
}

list *Create_list(int m)
{
	list *new_list = NULL;
		
	new_list = (list*)malloc(sizeof(list));
	
	if(new_list == NULL)
	{
		printf("Error in creating new list\n");	
		return NULL;
	}
	
	new_list -> iLen = m;
	new_list -> head = NULL;
	new_list -> next = NULL;

	return new_list;
}	

node *Build_list(node **head,int iLen)
{
	int i = 0, iValue = 10;

	node *new_node = NULL;
	
	new_node = Create_node(iValue * i);

	if(new_node == NULL)
	{
		return NULL;
	}

	*head = new_node;
	
	node *temp = new_node;

	for(i = 1; i < iLen; i++)
	{
		new_node = Create_node(iValue * i);
		
		if(new_node == NULL)
		{
			return NULL;
		}

		temp -> next = new_node;
		temp = new_node;	
	}

	return *head;
}

void Build_sub_lists(list *start)
{
	int i = 0;

	if(start == NULL)
	{
		printf("Big list is empty\n");	
		return;
	}
	
	list *temp = start;

	for(i = 0; i < iSize; i++)
	{	
		Build_list(&(temp->head),temp->iLen);
		temp = temp -> next;
	}
	
	return;
}

void Insert_in_big_list(list **head, int m)
{
	list *new_list = Create_list(m);
	
	if(new_list == NULL)
	{
		return;
	}

	if(*head == NULL)
	{
		*head = new_list;
	}
	else
	{
		list *temp = *head;
		
		while(temp -> next != NULL)
		{	
			temp = temp -> next;
		}

		temp -> next = new_list;

		Build_list(&(new_list -> head),new_list->iLen);
	}

	iSize++;

	return;
}

void Build_big_list(list **head, int k, int m)
{
	int i = 0;
	
	list *temp = NULL;
	
	list *new_list = Create_list(m);

	if(new_list == NULL)
	{
		return;
	}

	*head = new_list;

	temp = new_list;
	iSize++;
	
	for(i = 1; i < k; i++)
	{
		new_list = Create_list(m);
		
		if(new_list == NULL)
		{
			return;
		}

		temp -> next = new_list;
		temp = new_list;
		iSize++;
	}

	return;
}

void Insert_first(node **head, int iValue)
{
	node *new_node = Create_node(iValue);
	
	if(new_node == NULL)
	{
		return;
	}

	new_node -> next = *head;
	*head = new_node;

	return;
}

void Insert_in_list(list *head, int List_no, int iValue)
{	
	if(head == NULL)
	{
		printf("Big list is empty\n");	
		return;
	}
	
	int i = 0;
	
	list *temp = head;

	for(i = 1; i < List_no; i++)
	{
		temp = temp -> next;
	}	
	
	Insert_first(&(temp -> head),iValue);
	temp -> iLen += 1;

	return;
}

void Display_list(node *head)
{
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	node *temp = head;
	printf("Printing elements : ");
	while(temp != NULL)
	{
		printf("|%d|->",temp -> data);
		temp = temp -> next;
	}

	printf("\n");

	return;
}

void Display_list_no(list *head, int List_no)
{
	if(head == NULL)
	{
		printf("Big list is empty\n");
		return;
	}
		
	int i = 0;
	
	list *temp = head;

	for(i = 1; i < List_no; i++)
	{
		temp = temp -> next;
	}
	
	Display_list(temp -> head);
	printf("Size = %d\n",temp -> iLen);
	return;
}

void Display_all_lists(list *head)
{
	if(head == NULL)
	{
		printf("Big list is empty\n");	
		return;
	}

	int i = 0;
	list *temp = head;
	node *first = NULL;
	
	printf("Printing All lists:\n");

	for(i = 0; i < iSize; i++)
	{	
		printf("%d ",i+1);
		Display_list(temp -> head);
		temp = temp -> next;
	}

	return;
}

void Display_big_list(list *head)
{
	if(head == NULL)
	{
		printf("Big list is empty\n");
		return;
	}

	list *temp = head;

	printf("Printing the value of big list : ");
	while(temp != NULL)
	{
		printf("|%d|->",temp->iLen);
		temp = temp -> next;
	}

	printf("\n");

	return;
}

void Random_insertion(list *head, int k)
{
	if(head == NULL)
	{
		printf("Big list is empty\n");
		return;
	}	

	int i = 0, List_no = 0, iValue = 0;

	while(i < 100000000)
	{
		List_no = (rand() % k) + 1;
		iValue = rand() % 100;
	
		Insert_in_list(head,List_no,iValue);
		i++;	
	}

	return;
}

int main()
{
	int k = 0, m = 0;
	
	list *first = NULL;

	printf("Enter the value of k : ");
	scanf("%d",&k);

	printf("Enter number of nodes in each list : ");
	scanf("%d",&m);

	Build_big_list(&first,k,m);

	Build_sub_lists(first);

//	Display_all_lists(first);	
//	printf("\n\n");

//	Insert_in_big_list(&first,m);

//	Display_all_lists(first);


	Random_insertion(first,k);

//	Display_list_no(first,3);		
	return 0;
}
