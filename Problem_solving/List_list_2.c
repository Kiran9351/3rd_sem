#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct list
{
	int list_len;
	node *head;
}list;

typedef struct block
{
	int array_len;
	int occupied;
	list *array_head;
	struct block *next;	
}block;

int no_of_blocks = 0;
int no_of_lists = 0;

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

block *Create_block(int k)
{
	block *new_block = NULL;
	
	new_block = (block*)malloc(sizeof(block));
	
	if(new_block == NULL)
	{
		printf("Error in creating new block\n");
		return NULL;
	}
	
	new_block -> array_len = k;
	new_block -> occupied = 0;
	new_block -> array_head = NULL;
	new_block -> next = NULL;
	
	return new_block;
}

node* Build_lists(int m)
{
	int i = 0, iValue = 10;
	
	node *head = NULL;

	node *new_node = NULL;

	new_node = Create_node(iValue * i);
	
	if(new_node == NULL)
	{
		return NULL;
	}

	head = new_node;
	node *temp = head;

	for(i = 1; i < m; i++)
	{
		new_node = Create_node(iValue * i);
		
		if(new_node == NULL)
		{
			return NULL;
		}

		temp -> next = new_node;
		temp = new_node;
	}

	return head;
}
/*
void Create_lists(block *block_ptr, int m)
{
	if(block_ptr == NULL)
	{
		printf("Block is empty\n");
		return;
	}

	int i = 0;

	for(i = 0; i < block_ptr -> array_len; i++)
	{
		(block_ptr -> array_head + i) -> list_len = m;
		(block_ptr -> array_head + i) -> head = Build_lists(m);

		if((block_ptr -> array_head + i) -> head == NULL)
		{
			return;	
		}
		block_ptr -> occupied += 1;
	}

	printf("All lists are created\n");
	
	return;
}

*/
list *Create_array_list(int k, int m)
{
        int i = 0;
    
        list *new_array_list = NULL;
    
        new_array_list = (list*)malloc(k * sizeof(list));

        if(new_array_list == NULL)
        {                   
                printf("Error in creating new array list\n");
                return NULL;
        }    
    
        for(i = 0; i < k; i++)
        {
                new_array_list[i].list_len = m;
                new_array_list[i].head = Build_lists(m);
        }
	
	printf("\nAll lists are build\n");
	
        return new_array_list;
}

void Build_block(block **block_head,int k, int m)
{
	block *new_block = NULL;
	
	//Creating first block;
	new_block = Create_block(k);

	if(new_block == NULL)
	{
		return;
	}

	new_block -> array_head = Create_array_list(k,m);
	
	if(new_block -> array_head == NULL)
	{
		return;
	}

	if(*block_head == NULL)
	{
		*block_head = new_block;
	}
	else
	{
		block *temp = *block_head;

		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}

		temp -> next = new_block;
	}

	return;
}
/*
void Create_lists(block **block_head,int k, int m)
{
	int i = 0;

	no_of_blocks = (k/10) + 1;

	no_of_lists = no_of_blocks * 10;

	block *temp = Build_block(10,m);

	*block_head = temp;	

	for(i = 1; i < no_of_blocks; i++)
	{
		block *new_block = Build_block(10,m);

		if(new_block == NULL)
		{
			return;
		}
		temp -> next = new_block;
		temp = new_block;
	}

	return;
}
*/
void Display_list(node *head)
{
	if(head == NULL)
	{
		printf("List is empyt\n");
		return;
	}

	node *temp = head;

	printf("Printing list : ");
	
	while(temp != NULL)
	{
		printf("|%d|->",temp -> data);
		temp = temp -> next;
	}

	printf("\n");

	return;
}

void Display_array_list(list *array_head, int array_len)
{
	if(array_head == NULL)
	{
		printf("Array list is empty\n");
		return;
	}

	int i = 0;

	for(i = 0; i < array_len; i++)
	{
		printf("%d ",i+1);
		Display_list(array_head[i].head);
	}

	return;
}

void Display_all_lists(block *block_head)
{
	if(block_head == NULL)
	{
		printf("Block is empty\n");
		return;
	}

	block *temp = block_head;

	while(temp != NULL)
	{
		Display_array_list(temp -> array_head,temp ->array_len);
		temp = temp -> next;
	}

	return;
}

int main()
{
	int k = 0, m = 0;

	printf("Enter the number of list : ");	
	scanf("%d",&k);
	
	printf("Enter number of nodes in each list : ");
	scanf("%d",&m);

	block *first_block = NULL;
	
	Build_block(&first_block,k,m);

//	Create_lists(first_block,m);
	
	Display_all_lists(first_block);
	
	printf("No of blocks = %d\n",no_of_blocks);
	printf("No of lists = %d\n",no_of_lists);

	return 0;
}
