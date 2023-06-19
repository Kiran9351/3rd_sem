
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

//Size of int is 4 bytes i.e 32 bits

int a = INT_MAX;

void printBinary()
{
	int i = 0, b = 0;

	for(i = 31; i >= 0; --i)
	{
		b = (a >> i) & 1;
		printf("%d",b);
	}
	
	printf("\n");
}

int set_Bit(int pos)
{
	int b = 1;
	b = b << pos;

	a = a | b;

	return a;
}

void unset_bit(int pos)
{
	int b = 1;
	b = b << pos;

	b = ~b;
	a = a & b;
}

int give_me_block_address(int start_add)
{
	int i = 0, b = 0, add = 0;

	for(i = 31; i >= 0; --i)
	{
		b = (a >> i) & 1;
		if(b == 1)
		{	
			add = start_add + (31 - i) * 100;
			break;
		}
	}
	
	unset_bit(i);
	
	return add;
}

int unset_bits()
{
	int b = 1, i = 0;

	for(i = 31; i >= 0; --i)
	{
		b = 1;

		b = b << i;
		b = ~b;
		a = a & b;
	}
}

void set_bits()
{
	int n = rand() % 5, i = 0, pos = 0;

	for(i = 0;i < n; ++i)
	{
		pos = rand() % 32;
		set_Bit(pos);
	}
}

int main()
{
//	printBinary(a);
	set_Bit(31);
//	printBinary(a);
	
	int start_add = 100;

	int add = 0;
	
	unset_bits();

	set_bits();
	printBinary();	

	add = give_me_block_address(start_add);
	printf("%d\n",add);

	printBinary();

	return 0;
}
