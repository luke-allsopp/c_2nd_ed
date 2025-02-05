/* write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to rightmost n bits of y.
   leaving all other bits unchanged */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getbits(unsigned x, int p, int n);

int main (void)
{
	int x = 9713;							//0010 0101 1111 0001
	int y = 3500;							//0000 1101 1010 1100 

	printf("setbit: %d", setbits(x,11,4,y)); //expect 11761 (0010 1100 1111 0001)
											 //getting 11505(10 1100 1111 0001)
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	int mask = ~(~0 << n) << (p - n + 1);	// 0000 1111 0000 0000

	x &= ~mask;								// 0010 0000 1111 0001

	y = getbits(y,p,n);						// 0000 0000 0000 1100
	
	y <<= (p - n + 1);						// 0000 1100 0000 0000
	
	return 	x | y;							// 0010 1100 1111 0001
}

unsigned getbits(unsigned x, int p, int n) 
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}
