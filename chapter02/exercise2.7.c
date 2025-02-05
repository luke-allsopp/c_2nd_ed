#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main (void)
{
	int x = 4269;	//0001 0000 1010 1101

	printf("invert: %d\n", invert(x,7,4));	//expect: 0001 0000 0101 1101 == 4189
	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	unsigned int mask;
	
	mask = ~(~0 << n);
	mask <<= p+1-n;

	return x ^ mask;
}
