#include<stdio.h>
#include<stdlib.h>

typedef struct floor_info
{
	int building_no;
	int floor_no;
	char type;	
}FI;

typedef struct building_info
{
	int building_no;
	int no_of_floors;
	
	FI *floor_array;	

	struct building_info *next;
}BI;

typedef struct city
{
	int no_of_buildings;

	BI *bHead;
}CI;


BI *create_building_node(int i)
{
	BI *new_build_node = NULL;
		
	new_build_node = (BI*)malloc(sizeof(BI));

	if(new_build_node == NULL)
	{
		printf("Error in creating building node\n");
		return NULL;
	}

	new_build_node -> building_no = i;

	printf("Enter the number of floors in building %d: ",i);
	scanf("%d",&(new_build_node -> no_of_floors));

	new_build_node -> floor_array = (FI*)malloc((new_build_node -> no_of_floors) * sizeof(FI));

	for(int j = 0; j < new_build_node -> no_of_floors; j++)
	{
		(new_build_node -> floor_array + j) -> building_no = i;

		(new_build_node -> floor_array + j) -> floor_no = j;		
	
		printf("Enter the type of floor : ");
		scanf(" %c",&((new_build_node -> floor_array + j) -> type));
	}

	new_build_node -> next = NULL;

	return new_build_node;
}

void create_building_info(CI *city_ptr)
{
	if(city_ptr == NULL)
	{
		printf("Found error in allocated memorry of city info\n");
		return;
	}

	int i = 0;

	if(city_ptr -> bHead == NULL)	
	{
		city_ptr -> bHead = create_building_node(i);
	}

	BI *temp = city_ptr -> bHead;

	for(i = 1; i < city_ptr -> no_of_buildings; i++)
	{
		BI *new_build_node = create_building_node(i);
		
		temp -> next = new_build_node;

		temp = new_build_node;
	}
	
	return;	
}

CI *create_city()
{
	CI *city_ptr = NULL;

	city_ptr = (CI*)malloc(sizeof(CI));

	if(city_ptr == NULL)
	{
		printf("Error in allocating memory for city structure\n");
		return NULL;
	}

	printf("Enter the number of buildings in city: ");
	scanf("%d",&(city_ptr -> no_of_buildings));

	city_ptr -> bHead = NULL;
	
	return city_ptr;
}

int main()
{
	CI *city_ptr = create_city();	
	
	create_building_info(city_ptr);
	
	return 0;
}
