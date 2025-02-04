#include <stdio.h>

double fahr2cel (double f)
{
	return (5.0 / 9.0) * (f - 32.0);
}

int main(void)
{
	double fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		printf("%3.0f\t%6.1f\n", fahr, fahr2cel(fahr));
		fahr = fahr + step;
	}
}
