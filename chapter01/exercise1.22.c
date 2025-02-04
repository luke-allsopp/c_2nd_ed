// write a program to fold long input lines into two or more shorter lines after the last non-blank character that occurs before the nth 
// column of input. 
// !!Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the length.
//
// places - in word if overlength and no space
// UNDEFINED BEHAVIOR IF LINE LENGTH EXCEEDS INT (32K)

#include <stdio.h>

#define FOLDLEN 25

int main (void) 
{
	int i=0, c;

	while ((c=getchar()) != EOF) {
		++i;
		if (i>=FOLDLEN && c == ' ' ) {
			i=0;
			putchar('\n');
		}else if( i>FOLDLEN && c != ' ') {
			i=0;
			putchar('-');
			putchar('\n');
		}else{
			putchar(c);
		}
	}
	return 0;
}
