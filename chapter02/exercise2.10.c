//2.10 - rewrite lower function to convert upper to lower case.

#include <stdio.h>

int lower(int c);

int main ()
{	
	int c;
	while((c=getchar()) != EOF) {
		printf("%c\n", lower(c));
	}	
	return 0;
}

int lower(int c) 
{	
	
	return(c >= 'A' && c <= 'Z') ? c += 'a' - 'A' : c;
	
}
