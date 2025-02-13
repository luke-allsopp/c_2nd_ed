//ex4.12 - adapt printd to write a recursive version of itoa ie; convert an int to a string.
#include <stdio.h>
#include <stdlib.h>										//for abs() as sign handled elsewhere, and the char ascii conversion requires pos int.

#define MAXLEN 10

void itoa2(int n, char s[]);

int main()
{
	int x1 = 100;
	int x2 = -1204;
	int x3 = 32000;
	char s1[MAXLEN], s2[MAXLEN], s3[MAXLEN];

	itoa2(x1, s1);
	itoa2(x2, s2);
	itoa2(x3, s3);

	printf("x1: %s, x2: %s, x3: %s \n", s1, s2, s3);
	return 0;
}



void itoa2(int n, char s[])
{
	static int sign = 0;
	static int i;

    if (sign == 0) {									//first loop through, set sign and i
        sign = (n < 0) ? -1 : 1;
        i=0;
    }

    if (n / 10) {
		itoa2(n / 10, s);
    }
    if (sign != 0) {
        if (sign < 0)	{
			s[i++] = '-';
		}
		sign = 0;
    }
    s[i++] = abs(n % 10) + '0';
    s[i] = '\0';
}
