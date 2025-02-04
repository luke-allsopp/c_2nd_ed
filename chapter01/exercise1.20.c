/* Exercise 1-20:
 * Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. 
 * Assume a fixed set of tab stops, say every n columns. 
 *
 * Should n be a variable or a symbolic parameter? 
 */

#include <stdio.h>

#define TABLEN 4
#define MAXLINE 1000	

int getLine (char line[], int maxline);
void detab (char to[], char from[]);

int main (void)
{
	int len;
	char line[MAXLINE];
	char nline[MAXLINE];

	while ((len = getLine(line, MAXLINE)) > 0) {
		detab(nline, line);
		printf("%s", nline);
	}
	return 0;
}

int getLine (char s[], int lim) 
{
	int c, i;
	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void detab (char to[], char from[]) 
{
	int i, j, n;

	i = j = n = 0;

	while((to[j] = from[i]) != '\0') {
        if (to[j] == '\t')
            for (n = 0; n < TABLEN; ++n, ++j)
                to[j] = ' ';
        else
            ++j;
        ++i;
   }
}
