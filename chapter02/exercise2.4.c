/*write an alternative of the squeeze function that deletes each character in s1 that matches any character in s2
original squeeze function:
*/

#include <stdio.h>
#define MAXLINE 100

void squeeze(char s1[], char s2[]);

int main () 
{
	int c, i;
	char s1[MAXLINE], s2[MAXLINE];	
//	char s1[] = "the quick brown fox jumped over the lazy dog.";
//	char s2[] = "taeiou";

	printf(">s1 followed by [ENTER]:\n");
    for (i=0; i<MAXLINE && (c=getchar()) != EOF && c != '\n'; ++i) {
        s1[i] = c;
   }
	printf(">s2 followed by [ENTER]:\n");
    for (i=0; i<MAXLINE && (c=getchar()) != EOF && c != '\n'; ++i) {
        s2[i] = c;
	}
	squeeze(s1, s2);
	return 0;
}

void squeeze(char s1[], char s2[]) 
{
	int i, j, k;

	for (i=0; s2[i] != '\0'; ++i) {
		for(j=0, k=0;s1[k] != '\0'; j++) {
			if (s1[j] != s2[i]) {
				//printf("%c[%d]\n", s1[j], k); //debugging
				s1[k++] = s1[j];
			}
		}
	}
	s1[k] = '\0';
//	printf("%s[%d]\n", s1, k); //debugging
	printf("\"%s\"\n", s1);
}
