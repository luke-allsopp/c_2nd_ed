#include <ctype.h>
#include <stdio.h>

//atoi v2 - convert char array to int.

int atoi (char s[])
{
	int i, n, sign; 

	for (i=0; isspace(s[i]); i++)
		;							//do nothing for whitespace
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;						//skip signs
	for (n=0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}
