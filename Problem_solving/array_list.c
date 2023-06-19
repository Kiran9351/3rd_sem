#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

typedef struct node
{
	int data;
	struct node* next;	
}node;

typedef struct list
{
	int iLen;
	struct node *head;
}list;

node *Create_node(int iValue)
{
	node *new_node = NULL;
	
	new_node = (node*)malloc(sizeof(node));

	if(new_node == NULL)
	{
		printf("Error while creating new node\n");	
		return NULL;
	}

	new_node -> data = iValue;
	new_node -> next = NULL;

	return new_node;
}


node *Build_Linked_List(int m)
{	
	int i = 0, iValue = 10;
	
	node *head = NULL;
	node *temp = NULL;	
	
	node *new_node = NULL;
	new_node = Create_node(iValue * i);
	
	if(new_node == NULL)
	{
		return NULL;
	}	
	
	head = new_node;
	temp = head;

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

void Create_lists(list *array_list, int k, int m)
{
	int i = 0;
	
	if(array_list == NULL)
	{
		return;
	}
	
	for(i = 0; i < k; i++)
	{
		(array_list + i)-> iLen = m;
		(array_list + i) -> head = Build_Linked_List(m);
		
		if(array_list[i].head == NULL)
		{
			return;
		}
	}
	
	printf("All lists are created\n");

	return;
}


list *Create_array_list(int k)
{
	int i = 0;
	
	list *array_list = NULL;
	
	array_list = (list*)malloc(k * sizeof(list));
	
	if(array_list == NULL)
	{
		printf("Memory error\n");
		return NULL;
	}
	
	for(i  = 0; i < k; i++)
	{
		array_list[i].iLen = 0;
		array_list[i].head = NULL;
	}

	return array_list;
}


node* Insert_first(node *head, int iValue)
{
	node *new_node = NULL;

	new_node = Create_node(iValue);

	if(new_node == NULL)
	{
		return head;
	}
	
	new_node -> next = head;
	head = new_node;

	return head;
}
/*
node *Insert_node(node *head,int iValue, int iPos, int iLength)
{
	int i = 0;
	
	if(iPos < 1 || iPos > iLength + 1)
	{
		printf("Enter valid position\n");
		return NULL;
	}
	
	node *new_node = Create_node(iValue);
	
	if(new_node == NULL)
	{
		return NULL;
	}
	
	if(iPos == 1)
	{
		new_node -> next = head;
		head = new_node	
	}
	else
	{
		for(i = 1; i < iPos - 1; i++)
		{
			temp = temp -> next;
		}
		
		new_node -> next = temp -> next;
		temp -> next = new_node;		
	}

	return head;
}
*/
void Insert_In_List(list *array_list, int List_no, int iValue/*, int node_no*/)
{
	if(array_list == NULL)
	{	
		printf("Array list is empty\n");
		return;
	}

	array_list[List_no - 1].head = Insert_first(array_list[List_no - 1].head,iValue);
	array_list[List_no - 1].iLen += 1;
	
	return;
}


int Delete_node(node *head, int iPos, int iLength)
{
	int i = 0, iRet = 0;
	
	if(iPos < 1 || iPos > iLength)
	{
		printf("Enter valid position of node\n");
		return -1;
	}

	node *temp = head;
	
	if(iPos == 1)
	{
		iRet = head -> data;
		head = temp -> next;
		free(temp);
	}
	else
	{
		for(i = 1 ; i < iPos - 1; i++)
		{
			temp = temp -> next;	
		}

		node *target = temp -> next;
		temp -> next = target -> next;
		iRet = target -> data;
		
		free(target);
	}

	return iRet;
}

int Delete_from_list(list *array_list, int List_no, int node_no)
{
	int iRet = 0;
	
	if(array_list == NULL)
	{
		printf("Array list is empty\n");	
		return -1;
	}

	if(array_list[List_no - 1].head == NULL)
	{	
		printf("List is empty\n");	
		return -1;
	}

	iRet = Delete_node(array_list[List_no - 1].head,node_no,array_list[List_no - 1].iLen);
	array_list[List_no - 1].iLen -= 1;
		
	return iRet;
}


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
		printf("|%d|->",temp->data);
		temp = temp -> next;
	}

	printf("\n");
}

void Display_single_list(list *array_list, int List_no)
{
	if(array_list == NULL)
	{	
		printf("Array list is empty\n");
		return;
	}
	
	printf("Printing list number %d: ",List_no);

	Display_list(array_list[List_no - 1].head);

	return;
}

void Display_All_Lists(list *array_list, int k)
{
	int i = 0;
	
	if(array_list == NULL)
	{	
		printf("Array list is empty\n");
		return;	
	}

	for(i = 0; i < k; i++)
	{	
		printf("Printing list number %d : ",i+1);
		Display_list(array_list[i].head);
	}

	printf("All lists Diplayed\n");

	return;
}
/*
int data_in_file()
{
	int fd = 0, i = 0, list_no = 0, iValue = 0;
	char str[10], str1[10];
		
	fd = open("list_data.txt",O_CREAT | O_WRONLY, 00700);

	while(i < 100)
	{
		list_no = rand() % 10;	
		iValue = rand() % 100;
		sprintf(str,"%d",list_no);
		sprintf(str1, "%d",iValue);
		strcat(str," ");
		strcat(str,str1);
		strcat(str,"\n");
		write(fd,str,strlen(str));
	
		i++;
	}

	return fd;
	
}	

void read_from_file()
{
	int fd = 0, i = 0, List_no = 0,ino = 1;
	char str[10], str2[10], ch;
	
	fd = open("list_data.txt",O_RDONLY);
	
	while(ino != 0)
	{	
		while(ch != ' ')
		{
			ino = read(fd,&ch,1);
			strcat(str,&ch);
		}
		printf("%d ",atoi(str));
	}
}
*/

void Random_insertion(list *array_list, int k)
{
	if(array_list == NULL)
	{
		printf("Array list is empty\n");
		return;
	}

	int i = 0, List_no = 0, iValue = 0, UPPER = 100000000;

	printf("Upper = %d\n",UPPER);

	while(i < UPPER)
	{
		List_no = rand() % k;
		iValue = rand() % 100;
		
		Insert_In_List(array_list,List_no,iValue);
		i++;
	}

	return;
}

int main()
{
	int k = 1000, m = 10;

	int fd = 0, iRet = 0;

//	printf("Enter the number of list : ");
//	scanf("%d",&k);
	
	list *array_list = NULL;
	
	array_list = Create_array_list(k); 
	
//	printf("Number of arrays in each list : ");
//	scanf("%d",&m);

	Create_lists(array_list,k,m);
	
	//Display_All_Lists(array_list,k);
	
//	Display_single_list(array_list,5);
	
	Random_insertion(array_list, k);
	
//	Display_single_list(array_list,5);	
	printf("Size = %d\n",array_list[4].iLen);
//	Insert_In_List(array_list,5,100);

//	fd = data_in_file();

//	read_from_file();
				
	return 0;
}

