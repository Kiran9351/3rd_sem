#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int UPPER = 10000;

bool touch(int x1, int y1, int r1, int x2, int y2, int r2)
{
	int temp = 0, iLen = 0;
	
	if(r1 < r2)
	{
		temp = x1;
		x1 = x2 ;
		x2 = temp;
	
		temp = y1;
		y1 = y2;
		y2 = temp;	

		temp = r1;
		r1 = r2;
		r2 = r1;
	}
	
	if(((y2 - r2) < (y1 + r1) && (y2 - r2) > (y1 - r1)) || ((y2 + r2) < (y1 + r1) && (y2 + r2) > (y1 - r1)))
	{
		if(((x2 + r2) < (x1 + r1) && (x2 + r2) > (x1 - r1)) || ((x2 - r2) < (x1 + r1) && (x2 - r2) > (x1 - r1))) 
		{
			iLen = sqrt((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
			
			if(iLen == (r1 + r2))
			{	
				return true;
			}	
		}	
	}
		
	return false;
}

char *write_to_file()
{
	int i = 0, x1 = 0, y1 = 0, r1 = 0, x2 = 0, y2 = 0, r2 = 0;
	
	char *filename = "Circle_data.txt";
	
	int fd = open(filename,O_CREAT | O_WRONLY,00700);

	while(i < UPPER)
	{
		x1 = rand() % 100;
		x2 = rand() % 100;
		r1 = rand() % 50;
		
		x2 = rand() % 100;
		y2 = rand() % 100;
		r2 = rand() % 50;

		write(fd,&x1,sizeof(int));
		write(fd,&y1,sizeof(int));
		write(fd,&r1,sizeof(int));
		write(fd,&x2,sizeof(int));
		write(fd,&y2,sizeof(int));
		write(fd,&r2,sizeof(int));
		
		i++;			
	}	

	close(fd);
	
	return filename;
}


int Read_from_file(char *filename)
{
	int i = 0, iCnt = 0, n = 0, iRet = 0;
	int x1 = 0, y1 = 0, r1 = 0, x2 = 0, y2 = 0, r2 = 0;

	bool bRet;
	
	char *str = (char*)malloc(sizeof(int));

	int fd = open(filename,O_RDONLY);
	
	if(fd != -1)
	{	
		for(i = 0; i < UPPER; i++)
		{
			n = read(fd,str,sizeof(int));
			x1 = *(int*)str;
	
			n = read(fd,str,sizeof(int));
			y1 = *(int*)str;
			
			n = read(fd,str,sizeof(int));
			r1 = *(int*)str;
		
			n = read(fd,str,sizeof(int));
			x2 = *(int*)str;

			n = read(fd,str,sizeof(int));
			y2 = *(int*)str;
		
			n = read(fd,str,sizeof(int));
			r2 = *(int*)str;
	
			bRet = touch(x1,y1,r1,x2,y2,r2);

			if(bRet == true)
			{
				iCnt++;
			}
		}	
	}

	return iCnt;
}

int main()
{
	int i = 0, iCnt = 0, iRet = 0;

        int x1 = 0, y1 = 0, r1 = 0;
        int x2 = 0, y2 = 0, r2 = 0;

        bool bRet;
		
	char *filename = write_to_file();
	
	iRet = Read_from_file(filename);
/*	
        while(i < UPPER)
        {
                x1 = (int) rand() % 1000;
                y1 = (int) rand() % 1000;
                r1 = (int) rand() % 200;
                x2 = (int) rand() % 1000;
                y2 = (int) rand() % 1000;
                r2 = (int) rand() % 200;

                bRet = touch(x1,y1,r1,x2,y2,r2);

                if(bRet == true)
                {
                        iCnt++;
		}
		
		i++;	
	}
*/
	printf("iCnt = %d\n",iRet);
	return 0;
}
