#include <stdio.h>

int main ()
{
	int c, nl, ws, t;
	nl = ws = t = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		else if (c == '\t')
			++t;
		else if (c == ' ')
			++ws;
	}
	printf ("newlines: %d\twhitespace: %d\ttabs: %d\n", nl, ws, t);
}
