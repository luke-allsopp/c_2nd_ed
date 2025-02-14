//Exercise 5.1 -> as written, getint treats a + or - not followed by a digit as a vaild representation of zero.
//				  Fix it to push such a character back on the input.

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getint(int *pn);

int main() {
    int n, return_val;

    printf("Enter integers (or non-integer input to stop):\n");

    while ((return_val = getint(&n))!= 0 && return_val!= EOF) {
        printf("getint returned: %d, Value of n: %d\n", return_val, n);
    }

    if (return_val == EOF) {
        printf("End of file reached.\n");
    } else if (return_val == 0) {
        printf("Invalid input encountered.\n");
    }

    return 0;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))	{
		;
	}
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')	{
		ungetch(c);
		return 0;
	}
	sign = ( c == '-') ? -1 : 1;
	if(c == '+' || c == '-')	{
		int c1 = getch();		//check forward
		if (!isdigit(c1))	{
			ungetch(c1);		//if not a digit, push back c1, and c
			ungetch(c);
			return 0;		//and error out
		}
		c =  c1;	//proceed, assign c1 to c
	}
	for (*pn = 0; isdigit(c); c = getch())	{
		*pn = 10 * *pn + (c - '0');
	}
	*pn *= sign;
	if(c != EOF)	{
		ungetch(c);
	}
	return c;
}

int getch (void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch (int c)
{
    if (bufp >= BUFSIZE)    {
        printf("ungetch: too many characters\n");
    }
    else    {
        buf[bufp++] = c;
    }
}
