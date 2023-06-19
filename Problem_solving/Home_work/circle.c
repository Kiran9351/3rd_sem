#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>

#define UPPER 100000000

bool touch(int x1, int y1, int r1, int x2, int y2, int r2)
{
	int iLen = 0;
/*
	iLen = sqrt((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));

	if(iLen == (r2 + r1))
	{
		return true;
	}	

	return false;
	*/

	iLen = (x1 + x2) - (y1 + y2);
	int r = r1 + r2;
}

int main()
{
	int iValue = 1, i = 0;

	int x1 = 0, y1 = 0, r1 = 0;
	int x2 = 0, y2 = 0, r2 = 0;

	bool bRet;
	
	while(i <= UPPER )
	{
		/*
		if(iValue == 1)
		{
			printf("Enter x co-ordinate of center of circle 1: ");
			scanf("%d",&x1);
	
			printf("Enter y co-ordinate of center of circle 1: ");
			scanf("%d",&y1);
	
			printf("Enter radius of circle 1: ");
			scanf ("%d",&r1);

			printf("Enter x co-ordinate of center of circle 2: ");
			scanf("%d",&x2);

			printf("Enter y co-ordinate of center of circle 2: ");
			scanf("%d",&y2);
	
			printf("Enter radius of circle 2: ");
			scanf("%d",&r2);

			bRet = touch(x1,y1,r1,x2,y2,r2);
			if(bRet == true)
			{
				printf("Yes, Circles touch each other at single point\n");
			}
			else
			{
				printf("No, Circles do not touch each other at single point\n");
			}
		}
		else
		{
			break;
		}

		printf("\nEnter 1 to continue\nEnter 0 to stop : ");
                scanf("%d",&iValue);
		*/

		x1 = (int) rand() % 1000;
		y1 = (int) rand() % 1000;
		r1 = (int) rand() % 200;
		x2 = (int) rand() % 1000;
		y2 = (int) rand() % 1000;
		r2 = (int) rand() % 200;

		bRet = touch(x1,y1,r1,x2,y2,r2);
		/*if(bRet == true);
		{
			printf("x1 = %d, y1 = %d, r1 = %d, x2 = %d, y2 = %d, r2 = %d\n",x1,y1,r1,x2,y2,r2);
		}*/
		i++;

	}

	printf("\n");

	return 0;
}
