#include <stdio.h>
#define MAXLINE	1000

int getLine(char line[], int maxline);

int main ()
{
	int len, max; 
	char line[MAXLINE];

	max = 80; 
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > max) { 
			printf("%s\n", line);
		}	
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
