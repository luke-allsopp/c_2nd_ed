//write a function htoi(s) which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equiv int.
#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

unsigned int htoi(char s[]);

int main()
{
	int c, i;
	char s[MAXLINE];
	
	printf(">Input a Hexadecimal number followed by [ENTER] to convert to unsigned int: \n");
	for (i=0; i<=MAXLINE && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}

	printf("%d\n", htoi(s));
	
	return 0;
}

unsigned int htoi(char s[])
{
    unsigned int i, n = 0;

    if (tolower(s[1]) == 'x')
        i = 2;
    else i = 0;

    for(; isdigit(s[i]) || (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'); ++i)
        if (isdigit(s[i]))
            n = n*16 + s[i] - '0';
        else n = n*16 + tolower(s[i]) + 10 - 'a';

    return n;
}
