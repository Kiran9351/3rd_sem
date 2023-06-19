#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

#define UPPER 100000000

bool touch(int x1, int y1, int r1, int x2, int y2, int r2)
{
	if(y2 >= y1)
	{
		if((y1 + r1) > (y2 - r2) && (y1 + r1) < (y2 + r2))
		{	
			if(x2 <= x1)
			{
				if((x2 + r2) > (x1 - r1) && (x2 + r2) < (x1 + r1))
				{
					int iLen = 0;

        				iLen = sqrt((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
	
       					if(iLen == (r2 + r1))
        				{
                				return true;
        				}

				}
			}
			else
			{
				if((x2 - r2) > (x1 - r1) && (x2 - r2) < (x1 + r1))
                                {
                                        int iLen = 0;

                                        iLen = sqrt((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));

                                        if(iLen == (r2 + r1))
                                        {
                                                return true;
                                        }

                                }

			}
		}

	}
	else
	{
		if((y1 - r1) > (y2 - r2) && (y1 - r1) < (y2 + r2))
                {
			if(x2 <= x1)
                        {
                                if((x2 + r2) > (x1 - r1) && (x2 + r2) < (x1 + r1))
                                {
                                        int iLen = 0;

                                        iLen = sqrt((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));

                                        if(iLen == (r2 + r1))
                                        {
                                                return true;
                                        }       

                                }
                        }
			else
			{
				if((x2 - r2) > (x1 - r1) && (x2 - r2) < (x1 + r1))
                                {
                                        int iLen = 0;

                                        iLen = sqrt((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));

                                        if(iLen == (r2 + r1))
                                        {
                                                return true;
                                        }

                                }

			}
                }
	}

	return false;
}

int main()
{
	int i = 0;

        int x1 = 0, y1 = 0, r1 = 0;
        int x2 = 0, y2 = 0, r2 = 0;

        bool bRet;

	while(i < UPPER)
	{
		x1 = (int) rand() % 1000;
                y1 = (int) rand() % 1000;
                r1 = (int) rand() % 200;
                x2 = (int) rand() % 1000;
                y2 = (int) rand() % 1000;
                r2 = (int) rand() % 200;

                bRet = touch(x1,y1,r1,x2,y2,r2);
/*
		if(bRet == true)
		{
			printf("Circles touching\n");
		}
*/
		i++;
	}


	return 0;
}
