#include <stdio.h>

#define MINASCII 32
#define MAXASCII 126

int main ()
{
	int i, j, c;
	int chartype[MAXASCII - MINASCII + 1];

	i = j = 0;

	for(i = MINASCII; i<=MAXASCII; ++i) {
		chartype[i - MINASCII] = 0;
	}

	while ((c = getchar()) != EOF){		
		if (c >= MINASCII && c <= MAXASCII)
			++chartype[c - MINASCII];
	}

	printf("Frequency of char input (corresponding Ascii number):\n");
	for(i = MINASCII; i<=MAXASCII; ++i){
		if(chartype[i - MINASCII] >= 0)
			printf("%3d|", i);
		
		for (j=0; j < chartype[i - MINASCII]; ++j){
			putchar('*');
		}
		putchar('\n');

	}
	return 0;
}
