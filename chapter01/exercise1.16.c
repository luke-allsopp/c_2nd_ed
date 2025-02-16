#include <stdio.h>
#define MAXLINE	1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main ()
{
	int len, max; 
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0; 
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len; 
			copy(longest, line);
		}
	}
	if (max > 0) {
		printf("Longest line:\n%s%d Characters long.\n", longest, max);
	}
	return 0;
}

int getLine(char s[], int lim)
{
	int c, i, j;
	
	for (i=0, j=0; i <lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		if(i<lim-1) {
			s[j++] = c;
		}
	}
	if (c == '\n') {
		if(i<=lim-1) {
            s[j++] = c;
        }
		++i;
	}
	s[j] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i; 

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
