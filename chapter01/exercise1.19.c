#include <stdio.h>
#define MAXLINE	1000

int getLine(char line[], int maxline);
void reverse(char s[], int len);

int main ()
{
	int len; 
	char line[MAXLINE];
 
	while ((len = getLine(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s\n", line);
	}
	return 0;
}

int getLine(char s[], int lim)
{
	int c, i;
	
	for (i=0; i <lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
        s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


void reverse(char line[], int len) {
    int i, j;
    char temp;
    for(i = 0, j = len-1 ; i<j; ++i) {
        temp = line[i];
        line[i] = line[j];
        line[j] = temp; 
        j--;
    }
}
