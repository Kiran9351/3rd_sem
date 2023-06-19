#include<stdio.h>

#define SIZE 10000
#define HEADER 100
void *arr[SIZE];


typedef struct node
{
	int data;
	struct node *next;
}NODE;

typedef struct LinkdeList
{
	NODE *head;
	int iLen;
}LIST;


void my_free(int *ptr)
{
	int  i = 0, j = 0, temp = 0, start = 0, end = 0, size = 0;
/*	
	void *new_ptr = (void*)(ptr);
	
	start = *(int*)(new_ptr - 8);
	end = *(int*)(new_ptr - 4);
	size = end - start;
*/
	start =*(int*)(void*)(ptr - 8);
	end = *(int*)(void*)(ptr - 4);
	size = end - start;


	printf("\nstart = %d, end = %d, size = %d\n", start,end,size);
/*
	for(i = 1; i < (HEADER/4); i = i + 2)
	{
		if(*(int*)(arr + i) == end + 1)
		{
			*(int*)(arr + i) = start;	
			break;
		}
		else if(*(int*)(arr + i) == 0)
		{
			*(int*)(arr + i) = start;
			*(int*)(arr + (i + 1)) = end;
			break;
		}
	}

	*(int*)(arr + 0) += size;

        j = i - 2;
	while(j > 0)
	{
		if((*(int*)(arr + (i + 1)) - *(int*)(arr + i)) < (*(int*)(arr + (j + 1)) - *(int*)(arr + j)))
		{    
			temp = *(int*)(arr + (i + 1));
			*(int*)(arr + (i + 1)) = *(int*)(arr + (j + 1));
			*(int*)(arr + (j + 1)) = temp;

                        temp = *(int*)(arr + i);
                        *(int*)(arr + i) = *(int*)(arr + j);
                        *(int*)(arr + j) = temp;
		}

                i = i - 2;
		j = j - 2;
	}*/

}


void manage_header(int header_index, int iSize)
{
	int i = 0, temp = 0, j = 0;

	*(int*)(arr + (header_index)) = *(int*)(arr + (header_index)) + iSize;

	if(*(int*)(arr + (header_index)) == *(int*)(arr + (header_index + 1)))
	{
		i  = header_index;
		while( i < ((HEADER/4) - 2) && (*(int*)(arr + i) != 0))
		{
			*(int*)(arr + i) = *(int*)(arr + (i + 2));
			i++;	
		}

		if(i == (HEADER/4) - 2)
		{
			*(int*)(arr + i) = 0;
			*(int*)(arr + (i + 1)) = 0;
		}
	}	
	else
	{
		i = header_index;
		j = i - 2;
		while(j > 0)
		{
			if((*(int*)(arr + (i + 1)) - *(int*)(arr + i)) < (*(int*)(arr + (j + 1)) - *(int*)(arr + j)))
			{
				temp = *(int*)(arr + (i + 1));
				*(int*)(arr + (i + 1)) = *(int*)(arr + (j + 1));
				*(int*)(arr + (j + 1)) = temp;

				temp = *(int*)(arr + i);
				*(int*)(arr + i) = *(int*)(arr + j);
				*(int*)(arr + j) = temp;
			}

			i = i - 2;
			j = j - 2;	
		}
	}

/*	printf("\nPrinting header : ");
	for(i = 0; i < (HEADER /4); i++)
	{
		printf("%d ",*(int*)(arr + i));
	}
*/
}

int search_free_index(int iSize)
{
	int i = 0, j = HEADER/4;

	for(i = 1; i < j; i = i + 2)
	{
		if(*(int*)(arr+(i+1)) - *(int*)(arr + i) >= iSize)
		{
			break;
		}
	}

	if(i == j)
	{
		return -1;
	}
	else
	{
		*(int*)(arr + 0) = *(int*)(arr + 0) - iSize;
		return i;
	}
}

void *my_malloc(int iSize)
{
	int free_index = 0, header_index = 0, new_size = 0, start_index = 0;
	void *return_ptr = NULL;

	new_size = iSize + 8;
	header_index = search_free_index(new_size);

	if(header_index == -1)
	{
		printf("\nNo free memory available\n");
		return NULL;
	}
	start_index = *(int*)(arr + header_index);
	free_index =*(int*)(arr +  header_index) + 8;
	
	*(int*)(arr + start_index) = start_index;
	*(int*)(arr + (start_index + 1)) = start_index + new_size;
	
	printf("\nstart index = %d, end index = %d",*(int*)(arr + start_index), *(int*)(arr + (start_index + 1)));
	
	printf("\nFree index = %d",free_index);

	return_ptr = arr + (free_index);
	
	manage_header(header_index,new_size);

	return return_ptr;
}

void Display_List(LIST *ptr, int List_size)
{
	NODE *temp = ptr->head;

	printf("\nPrinting list values: ");
	while(temp != NULL)
	{
		printf("|%d|->",temp->data);
		temp = temp->next;
	}

	printf("\n");
}

LIST *construct_linked_list(int iSize)
{
	LIST *ptr = NULL;
	
	int i = 0, iValue = 0;
	NODE *temp = NULL;

	ptr =(LIST*)my_malloc(sizeof(LIST));

	if(ptr == NULL)
	{
		printf("\nNo free memory\n");
		return NULL;
	}
	else
	{
		ptr->head = NULL;
		ptr -> iLen = iSize;
	}

	NODE *first_node = NULL;
	first_node = (NODE*)my_malloc(sizeof(NODE));
	printf("\nEnter the value at node 1 : ");
	scanf("%d",&iValue);
	first_node -> data = iValue;
	first_node -> next = NULL;

	ptr->head = first_node;

	temp = first_node;

	for( i = 2; i <= iSize; i++)
	{
		NODE *new_node = NULL;
		new_node = (NODE*)my_malloc(sizeof(NODE));
		printf("\nEnter the value at node %d : ",i);
		scanf("%d",&iValue);
		new_node -> data = iValue;
		new_node -> next = NULL;
		temp->next = new_node;
		temp = new_node;
	}


	return ptr;
}

void Display_array(int *ptr, int iSize)
{
	int i = 0;
	
	printf("\nPrinting elements of array: ");
	for(i = 0; i < iSize; i++)
	{
		printf("%d ",ptr[i]);
	}

	printf("\n");
}

int *construct_array(int iSize)
{
	int i = 0, iValue = 0;

	int *ptr = NULL;

	//printf("\nEnter the size of the array: ");
	//scanf("%d",&iSize);
	
	ptr = (int*)my_malloc(iSize*sizeof(int));

	for(i = 0; i < iSize; i++)
	{
		printf("\nEnter the element at the index %d = ",i);
		scanf("%d",&iValue);
		ptr[i] = iValue; 
	}
	
	return ptr;
	
}

void header_creation(int header)
{
	int header_size = (header/4);

	void *header_pointer = arr;

	for(int i = 0 ; i < header_size; i++)
	{
		*(int*)(header_pointer + i) = 0;
	}
	
	*(int*)(arr + 0) = SIZE - HEADER;
	*(int*)(arr + 1) = HEADER;
	*(int*)(arr + 2) = SIZE - 1;

	printf("\narr[0] = %d, arr[1] = %d, arr[2] = %d",*(int*)(arr + 0), *(int*)(arr + 1), *(int*)(arr + 2));

	/*
	printf("\nPrinting header = ");
	for(int i = 0 ; i < header_size; i++)
	{
		printf("%d ",*(int*)(header_pointer + i));

	}
	*/
}

void Display_header(int header)
{
	int i = 0;
	/*
	while(*(int*)(arr + i) != 0)
	{
		printf("%d ",*(int*)(arr + i));
	}*/

	for(i = 0; i < (header/4); i++)
	{
		printf("%d ",*(int*)(arr + i));
	}

	printf("\n");
}

int main()
{

	int *array_ptr = NULL;

	int array_size = 0, List_size = 0;
	
	LIST *list_ptr = NULL;
		
	header_creation(HEADER);
	printf("\nHeader creation completed successfully\n");
	
	Display_header(HEADER);

	printf("\nEnter the size of the array: ");
	scanf("%d",&array_size);
	array_ptr = construct_array(array_size);
	Display_array(array_ptr,array_size);
	printf("\narray construction is successful\n");

	Display_header(HEADER);
	printf("\nEnter the size of the Linked list: ");
	scanf("%d",&List_size);
	list_ptr = construct_linked_list(List_size);
	Display_List(list_ptr,List_size);
	printf("\nLinked list construction is succesful\n");

	Display_header(HEADER);

	my_free(array_ptr);

	Display_header(HEADER);
	

	return 0;
}


