#include <stdio.h>

//printd print n in decimal

double printd(int n)
{
	if (n < 0)	{
		putchar('-');
		n = -n;
	}
	if (n / 10)	{
		printd(n/10);
	}
	putchar(n % 10 + '0');
}

int main ()
{
	int test = -10289.12390;

	printd(test);
	putchar('\n');
	return 0;
}
