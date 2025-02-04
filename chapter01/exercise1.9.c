#include <stdio.h>

int main () 
{
	int c1, c2, c, ws;
	ws =0;

	while ((c = getchar()) != EOF) {
		c1 = c;
		if (c2 == ' ' && c1 == ' ') {
			printf("");
		}else{
			putchar(c1);
			c2 = c1;
		}
	}
}
