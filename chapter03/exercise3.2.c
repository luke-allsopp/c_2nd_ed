/*3.2- write a function escape(s,t) that converts characters such as newline and tab into visible escape seqs as it copies the string t to s
 * 		- use a switch
 * 		- write a function for going the opposite direction as well (removing visible escape sequences and inserting invisible ones)
 */

#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
int escape(char s[], char t[]);
int capture(char s[], char t[]);

int main (void) 
{
	int len;
	char line[MAXLINE], nline[MAXLINE], nline2[MAXLINE];

	while((len=getLine(line, MAXLINE))>0) {
		escape(line, nline);
		printf("\nINPUT: %s\nOUTPUT  (escape): %s\n", line, nline);
		capture(nline, nline2);
		printf("OUTPUT (capture): %s\n", nline2);
	}
	return 0;
}

int getLine (char s[], int lim)
{
    int c, i;
    for (i=0; i<lim-1 && (c=getchar()) != EOF; ++i) {
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}

int escape(char s[], char t[]) 
{
	int i =0 , j=0;

	while(s[i] != '\0') {
		switch (s[i]) {
			case '\t':
				t[j] = '\\';
				t[j++] = '\\';
				t[j++] = 't';
				break;
			case '\n':
				t[j] = '\\';
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			default:
				t[j++] = s[i];
				break;
		}
		i++;
	}
	t[j] = '\0';
	return j;
}

int capture(char s[], char t[]) 
{
	int i = 0, j = 0; 
	
	while(s[i] != '\0') {
		if((s[i] == '\\') && (s[i+1] == 't' || s[i+1] == 'n')) {
			switch(s[i+1]) {
				case 't':
					t[j++] = '\t';
					i+=2;
					break;
				case 'n':
					t[j++] = '\n';
					i+=2;
					break;
				default:
					break;
			}
		}
		else{
			t[j++] = s[i];
			i++;
		}
	}
	t[j] = '\0';
	return j;

}
