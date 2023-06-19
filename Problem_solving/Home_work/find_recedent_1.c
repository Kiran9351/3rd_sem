#include<stdio.h>
#include<stdlib.h>

typedef struct building_info
{
	int building_no;
	int no_of_floors;

	char *floor_info;
}BI;

int total_floor;

typedef struct dist_list
{
	int building_no;
	int floor_no;

	int arr[4];
	
}Dist;

void right_travel(BI *build_array)
{
	Dist *right = NULL;

	 right = (Dist*)malloc(total_floors * sizeof(Dist));

	if(right == NULL)
	{
		printf("Error in memmory allocation\n");
		return;
	}
	
	build_nos = build_array[0].no_of_buildings; 

	for(i = 0; i < build_nos; i++)
	{
		floor_count = build_array[i].no_of_floors;

		for(j = 0; j < 
	}
}

BI *create_buildings_array(int no_of_buildings)
{
	int i = 0, j = 0, iValue = 0;
	BI *build_array = NULL;

	build_array = (BI*)malloc(no_of_buildings * sizeof(BI));

	if(build_array == NULL)
	{
		printf("Error in creating build array\n");
		return NULL;
	}

	for( i = 0; i < no_of_buildings; i++)
	{
		build_array[i].building_no = i;

		printf("Enter the number of floors in building %d : ", i);
		scanf("%d",&iValue);

		build_array[i].no_of_floors = iValue;
		total_floors += iValue;

		build_array[i].floor_info = (char*)malloc(iValue * sizeof(char));

		for(j = 0 ; j < iValue; j++)
		{
			printf("Enter the type of floor %d : ",j);
			scanf(" %c",((build_array + i) -> floor_info + j));
		}
	}

	return build_array;
}

int main()
{
	int no_of_buildings = 0;

	printf("Enter the number of buildings : ");
	scanf("%d",&no_of_buildings);

	BI *build_array = create_buildings_array(no_of_buildings);

	return 0;
}
