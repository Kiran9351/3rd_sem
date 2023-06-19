#include<stdio.h>

int mult(int x, int y)
{
	int iCnt = 0, temp = 0, m_ = 0, xx = 0, x_ = 0, t = 0;

	while(iCnt <= y)
	{
		temp = 1, xx = x;

		while(t <= y)
		{
			m_ = m_ + temp;
			x_ = x_ + xx;
			xx = xx + xx;
			temp = temp + temp;
			t = t + temp;
/*
			x_ = xx;
			xx = xx + xx;
			m_ = temp;
			temp = temp + temp;
*/
		}

		iCnt = m_;
		t = m_;
	}

	return x_;
}

int main()
{
	int iNo1 = 0, iNo2 = 0, iRet = 0;

	printf("Enter first number : ");
	scanf("%d",&iNo1);

	printf("Enter second number : ");
	scanf("%d",&iNo2);

	iRet = mult(iNo1, iNo2);
	printf("%d * %d = %d\n",iNo1,iNo2,iRet);

	return 0;
}
