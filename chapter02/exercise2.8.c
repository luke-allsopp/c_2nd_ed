#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void)
{
	printf("%u\n", rightrot(8, 5));		// 8 == 0000000000001000 n = 5
	return 0;
}

unsigned rightrot(unsigned x, int n){
	return x >> n | ((x & (~(~0 << n))) << (8 - n));	// 64 = 0000000001000000
}
