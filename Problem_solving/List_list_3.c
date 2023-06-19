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
	int occupied;
	list *array_head;
	struct block *next;	
}block;

int no_of_blocks = 0;
int no_of_lists = 0;
int Total_lists = 0;

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

block *Create_block(int Occ)
{
	block *new_block = NULL;
	
	new_block = (block*)malloc(sizeof(block));
	
	if(new_block == NULL)
	{
		printf("Error in creating new block\n");
		return NULL;
	}
	
	new_block -> occupied = Occ;
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
list *Create_array_list(int k, int Occ, int m)
{
        int i = 0;
    
        list *new_array_list = NULL;
    
        new_array_list = (list*)malloc(k * sizeof(list));

        if(new_array_list == NULL)
        {                   
                printf("Error in creating new array list\n");
                return NULL;
        }    
    
        for(i = 0; i < Occ; i++)
        {
                new_array_list[i].list_len = m;
                new_array_list[i].head = Build_lists(m);
        }
	
        return new_array_list;
}

block *Build_block(int k,int Occ, int m)
{
	block *new_block = NULL;
	
	//Creating first block;
	new_block = Create_block(Occ);

	if(new_block == NULL)
	{
		return NULL;
	}

	new_block -> array_head = Create_array_list(k,Occ,m);
	
	if(new_block -> array_head == NULL)
	{
		return NULL;
	}

	return new_block;
}

void Create_lists(block **block_head,int k, int m)
{
	int i = 0, Occ = 0, iRem = k;
	
	if(k%10 != 0)
	{
		no_of_blocks = (k/10) + 1;
	}
	else
	{
		no_of_blocks = k/10;
	}
	
	if(k <= 10)
	{
		Occ = k;
	}
	else
	{
		Occ = 10;
	}

	Total_lists = no_of_blocks * 10;
	
	no_of_lists = k;
	
	block *temp = Build_block(10,Occ,m);

	*block_head = temp;

	for(i = 1; i < no_of_blocks; i++)
	{
		iRem = iRem - 10;

		if(iRem >= 10)
		{
			Occ = 10;
		}
		else
		{
			Occ = iRem;
		}
		block *new_block = Build_block(10,Occ,m);

		if(new_block == NULL)
		{
			return;
		}
		temp -> next = new_block;
		temp = new_block;
	}
		
	printf("All lists are created\n");
	
	return;
}

void Insert_first(block *block_head, int list_no, int iValue)
{
	int i = 0;

	if(block_head == NULL)
	{
		printf("Block is empyt\n");
		return;
	}

	if(list_no > no_of_lists)
	{
		printf("Enter valid list no\n");
		return;
	}

	int iCnt = list_no / 10;

	block *temp = block_head;	

	for(i = 0; i < iCnt; i++)
	{
		temp = temp -> next;
	}

	int ln = list_no % 10 - 1;
	
	(temp -> array_head + ln) -> list_len += 1;
	
	node *new_node = Create_node(iValue);	

	if(new_node == NULL)
	{
		return;
	}

	new_node -> next = (temp -> array_head + ln) -> head;

	(temp -> array_head + ln) -> head = new_node;

	return;
}

void Random_insertion(block *block_head, int k)
{
	int i = 0, UPPER = 100000000;

	while( i < UPPER)
	{
		int list_no = (rand() % k) + 1;

		int iValue = rand() % 100;

		Insert_first(block_head,list_no,iValue);
		
		i++;
	}

	return;
}

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
		Display_array_list(temp -> array_head,temp ->occupied);
		temp = temp -> next;
	}

	return;
}

int main()
{
	int k = 0, m = 0;

	printf("Enter the number of lists : ");	
	scanf("%d",&k);
	
	printf("Enter number of nodes in each list : ");
	scanf("%d",&m);

	block *first_block = NULL;
	
//	Build_block(&first_block,k,m);
	Create_lists(&first_block,k,m);
//	Create_lists(first_block,m);
	
	//Display_all_lists(first_block);
	
//	Insert_first(first_block,13,101);
//	Insert_first(first_block,6,201);

//	Display_all_lists(first_block);
	
	Random_insertion(first_block,k);
//	Display_list((first_block -> array_head + 5)->head);
//	printf("Length = %d\n",(first_block -> array_head + 5) -> list_len);
	Display_list((first_block -> next -> array_head + 2)->head);

//	printf("No of blocks = %d\n",no_of_blocks);
//	printf("No of lists = %d\n",no_of_lists);

	return 0;
}
